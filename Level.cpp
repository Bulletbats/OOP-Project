#include "Level.h"
#include <iostream>
#include "BossEnemy.h"

Level::Level(int number) : levelNumber(number) {
    if (levelNumber == 1) {
        enemies.push_back(new Enemy("Skeleton", 50, 1));
        enemies.back()->setAttackPower(5);
        enemies.push_back(new Enemy("Goblin", 40, 1));
        enemies.back()->setAttackPower(4);
        items.push_back(Item("Health Potion", "heal", 20));
    } else if (levelNumber == 2) {
        enemies.push_back(new Enemy("Orc", 60, 2));
        enemies.back()->setAttackPower(6);
        enemies.push_back(new Enemy("Troll", 70, 2));
        enemies.back()->setAttackPower(7);
        items.push_back(Item("Sword", "weapon", 10));
    } else if (levelNumber == 3) {
        enemies.push_back(new Enemy("Dragon", 100, 3, true));
        enemies.back()->setAttackPower(15);
        items.push_back(Item("Mega Potion", "heal", 50));
    }
}

Level::~Level() {
    for (Enemy* e : enemies) {
        delete e;
    }
    enemies.clear();
}

bool Level::isCleared() const {
    for (Enemy* e : enemies) {
        if (e->is_alive()) return false;
    }
    return true;
}

Enemy* Level::getNextEnemy() {
    for (Enemy* e : enemies) {
        if (e->is_alive()) return e;
    }
    return nullptr;
}

void Level::awardItemsToPlayer(Player* player) {
    for (auto& item : items) {
        player->addItem(item);
    }
    items.clear();
}

void Level::displayLevelInfo() const {
    std::cout << "Level " << levelNumber << " Summary:\n";
    std::cout << "Enemies remaining: ";
    for (const auto& e : enemies) {
        if (e->is_alive()) std::cout << e->get_name() << " ";
    }
    std::cout << "\nItems available: ";
    for (const auto& item : items) {
        std::cout << item.get_name() << " ";
    }
    std::cout << "\n";
}

int Level::getEnemyCount() const {
    return enemies.size();
}

int Level::getItemCount() const {
    return items.size();
}
