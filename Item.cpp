#include "Item.h"
#include "Player.h"
#include <iostream>

// Constructor for Item
Item::Item(std::string name, std::string type, int effectValue)
    : name(name), type(type), effectValue(effectValue) {}

// Apply item effects to a player
void Item::applyEffect(Player* player) {
    if (type == "heal") {
        player->setHealth(player->getHealth() + effectValue);  // Heal player
        std::cout << player->getName() << " uses " << name << " and heals for " << effectValue << " health.\n";
    } else if (type == "weapon") {
        player->setAttackPower(player->getAttackPower() + effectValue);  // Boost attack
        std::cout << player->getName() << " equips " << name << " and increases attack power by " << effectValue << ".\n";
    } else {
        std::cout << "Unknown item type: " << type << "\n";
    }
}