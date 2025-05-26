#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>
#include "Enemy.h"
#include "Item.h"
#include "Player.h"

// Represents a single level in the game
class Level {
private:
    int levelNumber;                      // Level index
    std::vector<Enemy*> enemies;         // Dynamic list of enemies
    std::vector<Item> items;             // Collectible items in the level

public:
    Level(int number);
    ~Level();                            // Properly clean up dynamically allocated memory

    bool isCleared() const;              // Check if level is completed (no alive enemies)
    Enemy* getNextEnemy();               // Return pointer to next alive enemy
    void awardItems(Player* player); // Give level items to player
    void displayLevelInfo() const;       // Display summary of level

    // For testing or future saving:
    int getEnemyCount() const;
    int getItemCount() const;

    std::vector<Enemy*> getEnemies() {return enemies;};
    int getLevelNumber() {return levelNumber;};
};

#endif
