#ifndef ITEM_H
#define ITEM_H

#include <string>

class Player;  // Forward declaration

// Represents collectible items
class Item {
private:
    std::string name;
    std::string type;
    int effectValue;

public:
    Item(std::string name, std::string type, int effectValue);
    void applyEffect(Player* player);
    std::string get_name() const { return name; }
    std::string get_type() const { return type; }
    int get_effect_value() const { return effectValue; }
};


#endif
