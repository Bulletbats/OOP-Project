#include "Game.h"
#include <iostream>

// Constructor: Initialize game state
Game::Game() : currentLevel(0), gameOver(false) {
    Player player("Hero", 100, 1);
    player.setAttackPower(10);
    levels.push_back(Level(1));
    levels.push_back(Level(2));
    levels.push_back(Level(3));
}

// Run the main game loop
void Game::startGame() {
    std::cout << "Welcome to the Roguelike RPG Game!\n";
    while (!gameOver && currentLevel < levels.size()) {
        Level& level = levels[currentLevel];
        std::cout << "\nEntering Level " << level.getLevelNumber() << "\n";
        while (!level.isCleared() && !gameOver) {
            Enemy* enemy = level.getNextEnemy();
            if (enemy != nullptr) {
                bool playerWon = combatSystem.resolveCombat(&player, enemy);
                if (playerWon) {
                    std::cout << "You defeated " << enemy->getName() << "!\n";
                    level.getEnemies().erase(level.getEnemies().begin());  // Remove defeated enemy
                } else {
                    std::cout << "You were defeated by " << enemy->getName() << ".\n";
                    gameOver = true;
                }
            }
        }
        if (level.isCleared()) {
            std::cout << "You cleared Level " << level.getLevelNumber() << "!\n";
            level.awardItems(&player);  // Award items for level completion
            currentLevel++;
        }
    }
    if (currentLevel == levels.size()) {
        std::cout << "\nCongratulations! You have cleared all levels and won the game!\n";
    } else {
        std::cout << "\nGame Over. Better luck next time!\n";
    }
}

// Display player's current status
void Game::displayStatus() {
    std::cout << "Player: " << player.getName() << ", Health: " << player.getHealth() 
              << ", Attack Power: " << player.getAttackPower() << ", Level: " << player.getLevel() << "\n";
}