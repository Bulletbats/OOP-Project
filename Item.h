#ifndef ITEM_H
#define ITEM_H

#include <string>

class Player;  // Forward declaration

// Represents collectible items
class Item {
public:
    std::string name;       
    std::string type;       
    int effectValue;        

    Item(std::string name, std::string type, int effectValue);
    void applyEffect(Player* player);  // Apply item effect to player
};

#endif