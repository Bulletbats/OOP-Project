#include <string>
#include <vector>
#include "Item.h"
#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
using namespace std;

class Character {
protected:
    std::string name;
    int health;
    int damage;
    int attack_power;
    int level;
    std::vector<Item> inventory;  // Added inventory

public:
    virtual ~Character() {}

    virtual void attack(Character* opponent, int damage) = 0;
    virtual void takeDamage(int damage) = 0;

    std::string getName() const { return name; }
    void setName(const std::string& newName) { name = newName; }

    int getHealth() const { return health; }
    void setHealth(int newHealth) { health = newHealth; }

    int getDamage() const { return damage; }
    void setDamage(int newDamage) { damage = newDamage; }

    int getAttackPower() const { return attack_power; }
    void setAttackPower(int newAttackPower) { attack_power = newAttackPower; }

    int getLevel() const { return level; }
    void setLevel(int newLevel) { level = newLevel; }

    bool is_alive() const { return health > 0; }

    // Item methods
    void addItem(const Item& item) { inventory.push_back(item); }

    void useItem(int index) {
        if (index >= 0 && index < inventory.size()) {
            inventory[index].applyEffect(this);
            inventory.erase(inventory.begin() + index);
        }
    }

    std::vector<Item>& getInventory() { return inventory; }
};

#endif
