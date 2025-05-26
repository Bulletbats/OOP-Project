#include <iostream>
#include "Player.h"

using namespace std;

Player::Player()
{
    name = "";
    health = 0;
    damage = 0;
    attack_power = 0;
    level = 0;
}

Player::Player(string name, int health, int level)
{
    this->name = name;
    this->health = health;
    this->level = level;
}

void Player::attack(Character *opponent, int damage)
{
    opponent->takeDamage(damage);
}

void Player::takeDamage(int damage)
{
    this->health -= damage;
    if (this->health < 0)
    {
        this->health = 0;
    }
    cout << name << " takes " << damage << " damage. Remaining health: " << health << endl;
}

void Player::addItem(const Item &item)
{
    inventory.push_back(item);
    std::cout << "[INFO] " << item.get_name() << " added to " << this->getName() << " inventory.\n";
}

void Player::printInventory() const
{
    if (inventory.empty())
    {
        std::cout << "[INFO] Inventory is empty.\n";
        return;
    }
    std::cout << "[Inventory]\n";
    for (size_t i = 0; i < inventory.size(); ++i)
    {
        std::cout << i + 1 << ". " << inventory[i].get_name() << " (" << inventory[i].get_type() << ", Effect: " << inventory[i].get_effect_value() << ")\n";
    }
}