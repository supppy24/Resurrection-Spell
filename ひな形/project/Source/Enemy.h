#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy
{
private:
    int hp;
    int attackPower;
    int skillPower;

    std::string name;
    int image;

public:
    Enemy(int type = 1);

    int getHp() const;
    std::string getName() const;
    int getImage() const;

    void takeDamage(int damage);
    int act();
    bool isDead() const;
};

#endif