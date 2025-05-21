#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include "Character.h"

using namespace std;

class Enemy : public Character {

    public:
    Enemy();
    Enemy(string name, int health, int level);

    void attack(Character* opponent,  int damage) override ;
    void takeDamage(int damage) override;
    
    ~Enemy() {};
};

#endif