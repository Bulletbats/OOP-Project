#include <iostream>
#include "Player.h"

using namespace std;

Player::Player(){
    name = "";
    health = 0;
    damage = 0;
    attack_power = 0;
    level = 0;
}

Player::Player(string name, int health, int level){
    this->name = name;
    this->health = health;
    this->level = level;
}

void Player::attack(Character* opponent, int damage) {
    opponent->takeDamage(damage);
}

void Player::takeDamage(int damage) {
    this->health -= damage;
    if (this->health < 0){
        this->health = 0;
    }
    cout << name << " takes " << damage << " damage. Remaining health: " << health << endl;
}