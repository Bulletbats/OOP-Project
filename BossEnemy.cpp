#include "BossEnemy.h"
#include <iostream>

BossEnemy::BossEnemy(std::string name, int health, int level)
    : Enemy(name, health, level, true) { // mark as boss
    setAttackPower(getAttackPower() + 5);  // stronger attack
}

void BossEnemy::specialAttack(Character* target) {
    std::cout << get_name() << " uses a devastating special attack!" << std::endl;
    target->takeDamage(getAttackPower() * 2);  // Double damage
}

