#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include "Enemy.h"
#include "Item.h"
#include "Player.h"

// Represents a game level
class Level {
public:
    std::vector<Enemy> enemies;  
    std::vector<Item> items;     
    int levelNumber;             

    Level(int levelNumber);
    bool isCleared();  // Check if level is completed
    Enemy* getNextEnemy();
    void awardItem(Player* player);  // Award items to player
};

#endif