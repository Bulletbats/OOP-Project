#include <iostream>
#include "Player.h"
#include "Enemy.h"
#include "Item.h"
#include "Game.h"

using namespace std;

int main() {
    
    Player* p1 = new Player("Leo", 100, 10);
    Enemy* e1 = new Enemy("enemy", 200, 20);
    Item i("healing pot", "heal", 50);

    p1->attack(e1,50);
    p1->takeDamage(20);
    p1->addItem(i);

    Game game;
    game.displayStatus();
    
    cout << "" << endl;
    
    return 0;
}
