#include "xcombat.h"

Combat::Combat() {}
Combat::Combat(Toon& combatant1, Toon& combatant2) { 
    // Check Health State
    if (combatant1.get_health() < 1 && combatant2.get_health() < 1) {
        exit(-1);
    }
    // Check Combat State
    if (!combatant1.isAlive() || !combatant2.isAlive()) {
        exit(-1);
    }
    // Set Combat State
    combatant1.set_combat_fight();
    combatant2.set_combat_fight();
    printf("%d fighting %d\n", combatant1.get_id(), combatant2.get_id());
}

Combat::Combat(Player& combatant1, Toon& combatant2) { }

Combat::Combat(Player& combatant1, Player& combatant2) { }

Combat::~Combat() {}