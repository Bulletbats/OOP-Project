#ifndef COMBATSYSTEM_H
#define COMBATSYSTEM_H

#include "Player.h"
#include "Enemy.h"

// Manages turn-based combat
class CombatSystem {
public:
    bool resolveCombat(Player* player, Enemy* enemy);  // Resolve a combat round
    void displayCombatStatus(Player* player, Enemy* enemy);  // Show combat status
};

#endif