#include <iostream>
#include "Enemy.h"

using namespace std;

Enemy::Enemy(){
    name = "";
    health = 0;
    damage = 0;
    attack_power = 0;
    level = 0;
}

Enemy::Enemy(string name, int health, int level){
    this->name = name;
    this->health = health;
    this->level = level;
}

void Enemy::attack(Character* opponent, int damage) {
    opponent->takeDamage(damage);
}

void Enemy::takeDamage(int damage) {
    this->health -= damage;
    if (this->health < 0){
        this->health = 0;
    }
    cout << name << " takes " << damage << " damage. Remaining health: " << health << endl;
}