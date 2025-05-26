#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "Character.h"

using namespace std;

class Player : public Character
{

public:
    Player();
    Player(string name, int health, int level);

    void attack(Character *opponent, int damage) override;
    void takeDamage(int damage) override;

    void addItem(const Item &item) override;
    void printInventory() const override;

    ~Player() {};
};

#endif