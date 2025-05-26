#ifndef BOSSENEMY_H
#define BOSSENEMY_H

#include "Enemy.h"

class BossEnemy : public Enemy {
public:
    BossEnemy(std::string name, int health, int level);
    void specialAttack(Character* target);
};

#endif
