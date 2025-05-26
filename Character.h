#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <vector>
#include <iostream>
#include "Item.h"

class Character {
protected:
    std::string name;
    int health;
    int damage;
    int attack_power;
    int level;
    std::vector<Item> inventory;

public:
    virtual ~Character() {}

    // Abstract combat functions
    virtual void attack(Character* opponent, int damage) = 0;
    virtual void takeDamage(int damage) = 0;

    // Basic getters and setters
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

    // Inventory commands
    void addItem(const Item& item) {
        inventory.push_back(item);
        std::cout << "[INFO] " << item.get_name() << " added to inventory.\n";
    }

    void useItem(int index) {
        if (index >= 0 && index < inventory.size()) {
            inventory[index].applyEffect(this);
            inventory.erase(inventory.begin() + index);
        } else {
            std::cout << "[ERROR] Invalid item index.\n";
        }
    }

    void printInventory() const {
        if (inventory.empty()) {
            std::cout << "[INFO] Inventory is empty.\n";
            return;
        }
        std::cout << "[Inventory]\n";
        for (size_t i = 0; i < inventory.size(); ++i) {
            std::cout << i + 1 << ". " << inventory[i].get_name() << " (" << inventory[i].get_type() << ", Effect: " << inventory[i].get_effect_value() << ")\n";
        }
    }

    std::vector<Item>& getInventory() {
        return inventory;
    }

    // Status print
    void printStatus() const {
        std::cout << "[Status] " << name << " - HP: " << health << ", ATK: " << attack_power << ", Level: " << level << "\n";
    }
};

#endif
