#include "strategycase.h"

/*!
 * @def     __FILENAME__
 * @brief   Translate Filename to reusable macro
*/
#define __FILENAME__ (__builtin_strrchr(__FILE__, '/') ? __builtin_strrchr(__FILE__, '/') + 1 : __FILE__)

TestStrategy::TestStrategy() : TestStrategy(0) {}

TestStrategy::TestStrategy(int granularity) : BaseCase(__FILENAME__) {
  set_granularity(granularity);
  BaseCase::log->named_log(__FILENAME__, "Testing CombatStrategy!");
  sprintf(this->msgHead, "Tested");
  sprintf(this->msgTail, "for Strategy!");
  this->test_all();
}

void TestStrategy::test_all() {
  this->test_assign();
  this->test_factory();
  this->test_attack_resolution();
  this->test_defense_resolution();
  this->test_flee_thresholds();
  this->test_combat_with_styles();
}

/*!
 * @brief   Actor defaults to BalancedStyle; set_strategy replaces it cleanly
*/
void TestStrategy::test_assign() {
  if (this->_granularity >= 1) { PROFILE_FUNCTION(); }
  PROFILE_NAMED("Strategy");

  Toon t("StratAssign");
  record(t.get_strategy() != nullptr,           "default strategy is null");
  record(std::string(t.get_strategy()->get_name()) == "Balanced",
         "default strategy is not BalancedStyle");

  t.set_strategy(new AggressiveStyle());
  record(std::string(t.get_strategy()->get_name()) == "Aggressive",
         "set_strategy did not replace the style");

  sprintf(buf, "%s [%s] %s", msgHead, "strategy assign", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   make_strategy produces the right concrete type for every StyleType
*/
void TestStrategy::test_factory() {
  if (this->_granularity >= 1) { PROFILE_FUNCTION(); }
  PROFILE_NAMED("Strategy");

  CombatStrategy* s;

  s = make_strategy(StyleType::BALANCED);
  record(std::string(s->get_name()) == "Balanced",   "factory: BALANCED wrong type"); delete s;

  s = make_strategy(StyleType::AGGRESSIVE);
  record(std::string(s->get_name()) == "Aggressive", "factory: AGGRESSIVE wrong type"); delete s;

  s = make_strategy(StyleType::DEFENSIVE);
  record(std::string(s->get_name()) == "Defensive",  "factory: DEFENSIVE wrong type"); delete s;

  s = make_strategy(StyleType::BERSERKER);
  record(std::string(s->get_name()) == "Berserker",  "factory: BERSERKER wrong type"); delete s;

  s = make_strategy(StyleType::COWARDLY);
  record(std::string(s->get_name()) == "Cowardly",   "factory: COWARDLY wrong type"); delete s;

  sprintf(buf, "%s [%s] %s", msgHead, "factory", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Over 1000 rolls, resolve_attack must produce at least one miss (0) and one crit (> base)
 *          for every style that has non-zero hit and crit rates
*/
void TestStrategy::test_attack_resolution() {
  if (this->_granularity >= 1) { PROFILE_FUNCTION(); }
  PROFILE_NAMED("Strategy");

  const int ROLLS = 1000;
  const int BASE  = 10;

  auto run = [&](CombatStrategy* s) {
    int misses = 0, crits = 0;
    for (int i = 0; i < ROLLS; i++) {
      int result = s->resolve_attack(BASE);
      if (result == 0)          misses++;
      if (result > BASE)        crits++;
    }
    bool got_miss = (s->hit_chance()  < 1.0f) ? misses > 0 : true;
    bool got_crit = (s->crit_chance() > 0.0f) ? crits  > 0 : true;
    record(got_miss, "resolve_attack: no misses observed over 1000 rolls");
    record(got_crit, "resolve_attack: no crits observed over 1000 rolls");
    delete s;
  };

  run(make_strategy(StyleType::BALANCED));
  run(make_strategy(StyleType::AGGRESSIVE));
  run(make_strategy(StyleType::DEFENSIVE));
  run(make_strategy(StyleType::BERSERKER));
  run(make_strategy(StyleType::COWARDLY));

  sprintf(buf, "%s [%s] %s", msgHead, "attack resolution", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Over 1000 rolls, resolve_defense must produce at least one dodge (0) for styles with
 *          non-zero dodge chance
*/
void TestStrategy::test_defense_resolution() {
  if (this->_granularity >= 1) { PROFILE_FUNCTION(); }
  PROFILE_NAMED("Strategy");

  const int ROLLS   = 1000;
  const int DAMAGE  = 20;

  auto run = [&](CombatStrategy* s) {
    int dodges = 0;
    for (int i = 0; i < ROLLS; i++) {
      if (s->resolve_defense(DAMAGE) == 0) dodges++;
    }
    bool got_dodge = (s->dodge_chance() > 0.0f) ? dodges > 0 : true;
    record(got_dodge, "resolve_defense: no dodges observed over 1000 rolls");
    delete s;
  };

  run(make_strategy(StyleType::BALANCED));
  run(make_strategy(StyleType::AGGRESSIVE));
  run(make_strategy(StyleType::DEFENSIVE));
  run(make_strategy(StyleType::BERSERKER));
  run(make_strategy(StyleType::COWARDLY));

  sprintf(buf, "%s [%s] %s", msgHead, "defense resolution", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Verify should_flee thresholds match the documented HP levels
*/
void TestStrategy::test_flee_thresholds() {
  if (this->_granularity >= 1) { PROFILE_FUNCTION(); }
  PROFILE_NAMED("Strategy");

  BalancedStyle    bal;
  AggressiveStyle  agg;
  DefensiveStyle   def;
  BerserkerStyle   ber;
  CowardlyStyle    cow;

  // Styles that never flee
  record(!bal.should_flee(1),  "Balanced should not flee");
  record(!agg.should_flee(1),  "Aggressive should not flee");
  record(!ber.should_flee(1),  "Berserker should not flee");

  // Defensive flees below 13 HP (~20% of 64)
  record(!def.should_flee(13), "Defensive should not flee at 13 HP");
  record( def.should_flee(12), "Defensive should flee at 12 HP");

  // Cowardly flees below 32 HP (~50% of 64)
  record(!cow.should_flee(32), "Cowardly should not flee at 32 HP");
  record( cow.should_flee(31), "Cowardly should flee at 31 HP");

  sprintf(buf, "%s [%s] %s", msgHead, "flee thresholds", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

/*!
 * @brief   Assign each style to both combatants in an EvE fight and verify combat terminates
*/
void TestStrategy::test_combat_with_styles() {
  if (this->_granularity >= 1) { PROFILE_FUNCTION(); }
  PROFILE_NAMED("Strategy");

  StyleType styles[] = {
    StyleType::BALANCED,
    StyleType::AGGRESSIVE,
    StyleType::DEFENSIVE,
    StyleType::BERSERKER,
    StyleType::COWARDLY
  };

  for (StyleType st : styles) {
    Toon* t1 = new Toon("S_T1");
    Toon* t2 = new Toon("S_T2");
    t1->set_strategy(make_strategy(st));
    t2->set_strategy(make_strategy(st));
    Combat* c = new Combat(t1, t2);
    while (c->inCombat()) { c->cycleCombat(); }
    // Combat must end — one dead or one fled
    bool ended = !t1->isAlive() || !t2->isAlive() ||
                 t1->get_combatstate() == FLEE || t2->get_combatstate() == FLEE;
    record(ended, "combat did not terminate with the assigned style");
    delete c; delete t1; delete t2;
  }

  sprintf(buf, "%s [%s] %s", msgHead, "combat with styles", msgTail);
  BaseCase::log->named_log(__FILENAME__, buf);
}

TestStrategy::~TestStrategy() { }
