#include "Level.h"

// Constructor: Initialize level with enemies and items
Level::Level(int levelNumber) : levelNumber(levelNumber) {
    if (levelNumber == 1) {
        enemies.push_back(Enemy("Skeleton", 50, 1));
        enemies.back().setAttackPower(5);  // Set Skeleton's attack
        enemies.push_back(Enemy("Goblin", 40, 1));
        enemies.back().setAttackPower(4);  // Set Goblin's attack
        items.push_back(Item("Health Potion", "heal", 20));
    } else if (levelNumber == 2) {
        enemies.push_back(Enemy("Orc", 60, 2));
        enemies.back().setAttackPower(6);  // Set Orc's attack
        enemies.push_back(Enemy("Troll", 70, 2));
        enemies.back().setAttackPower(7);  // Set Troll's attack
        items.push_back(Item("Sword", "weapon", 10));
    } else if (levelNumber == 3) {
        enemies.push_back(Enemy("Dragon", 100, 3, true));
        enemies.back().setAttackPower(15);  // Set Dragon's attack
        items.push_back(Item("Health Potion", "heal", 50));
    }
}

// Check if all enemies are defeated
bool Level::isCleared() {
    return enemies.empty();
}

// Get the next enemy to fight
Enemy* Level::getNextEnemy() {
    if (!enemies.empty()) return &enemies[0];
    return nullptr;
}

// Award all items in the level to the player
void Level::awardItem(Player* player) {
    for (auto& item : items) player->addItem(item);
    items.clear();  // Clear items after awarding
}