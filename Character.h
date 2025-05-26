#include "Item.h"
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

class Character {
    public:
    string name;
    int health;
    int damage;
    int attack_power;
    int level;
    //Item* inventory;


    virtual void attack(Character* opponent,  int damage) {};
    virtual void takeDamage(int damage) {};
    //void use_item(int index);
    //void pick_up_item(Item item);
    bool is_alive() {
        if (this->health > 0){
        return true;
    }
        return false;
    };

    // Getter and Setter for Name
    string getName() {return name;};
    void setName(string newName) {name = newName;};

    // Getter and Setter for health
    int getHealth() {return health;};
    void setHealth(int newHealth) {health = newHealth;};

    // Getter and Setter for damage
    int getDamage() {return damage;};
    void setDamage(int newDamage) {damage = newDamage;};

    // Getter and Setter for attack_power
    int getAttackPower() {return attack_power;};
    void setAttackPower(int newAttackPower) {attack_power = newAttackPower;};

    // Getter and Setter for level
    int getLevel() {return level;};
    void setLevel(int newLevel) {level = newLevel;};

    ~Character() {};
};

#endif
