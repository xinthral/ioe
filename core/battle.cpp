/*! 
 * @class   Battle battle.h battle.cpp
 * @brief   Interweaving combat events
 */
#include "battle.h"

/*! 
 * @brief   Default Constructor
*/
Battle::Battle() {}

/*! 
 * @overload
 * @brief   Player v Team Constructor
*/
Battle::Battle(int size, Player* player, std::vector<Toon*>& team) {
    Toon* t, * v;
    Combat* cc;
    while (team.size() > 1) {
		t = team[team.size() - 1];
		team.pop_back();
		v = team[team.size() - 1];
		team.pop_back();
		cc = new Combat(*t, *v);
		cc->begin_combat();
	}

	cc = new Combat(*player, *t);
	cc->begin_combat();
	
}

/*! 
 * @brief   Default Deconstructor
*/
Battle::~Battle() {}