#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Level.h"
#include "CombatSystem.h"
#include <vector>

// Manages the overall game
class Game {
public:
    Player player;
    std::vector<Level> levels;
    int currentLevel;
    bool gameOver;
    CombatSystem combatSystem;

    Game();
    void startGame();  // Start the game loop
    void displayStatus();  // Show player status
};

#endif