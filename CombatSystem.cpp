#include "CombatSystem.h"
#include <iostream>
#include <vector>

// Display current combat status
void CombatSystem::displayCombatStatus(Player* player, Enemy* enemy) {
    std::cout << "\nCombat Status:\n";
    std::cout << player->getName() << " Health: " << player->getHealth() << "\n";
    std::cout << enemy->getName() << " Health: " << enemy->getHealth() << "\n";
}

// Resolve combat between player and enemy
bool CombatSystem::resolveCombat(Player* player, Enemy* enemy) {
    while (player->is_alive() && enemy->is_alive()) {
        displayCombatStatus(player, enemy);
        std::cout << "Choose action: 1. Attack 2. Use Item\n";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            player->attack(enemy, player->getAttackPower());  // Player attacks
        } else if (choice == 2) {
            if (player->inventory.empty()) {
                std::cout << "No items in inventory.\n";
            } else {
                std::cout << "Inventory:\n";
                for (size_t i = 0; i < player->inventory.size(); ++i) {
                    std::cout << i + 1 << ". " << player->inventory[i].name << "\n";
                }
                std::cout << "Choose item to use: ";
                int itemIndex;
                std::cin >> itemIndex;
                if (itemIndex >= 1 && itemIndex <= player->inventory.size()) {
                    player->useItem(itemIndex - 1);  // Use selected item
                } else {
                    std::cout << "Invalid choice.\n";
                }
            }
        } else {
            std::cout << "Invalid choice.\n";
        }
        if (enemy->is_alive()) {
            enemy->attack(player, enemy->getAttackPower());  // Enemy retaliates
        }
    }
    return player->is_alive();  // Return true if player survives
}