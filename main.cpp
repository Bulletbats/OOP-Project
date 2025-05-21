#include <iostream>
#include "Player.h"
#include "Enemy.h"

using namespace std;

int main() {
    
    Player p1("Leo", 100, 10);
    Enemy e1("enemy", 200, 20);
    p1.attack(&e1,50);
    p1.takeDamage(20);
    cout << "" << endl;
    
    return 0;
}
