#ifndef PLAYER_H
#define PLAYER_H

#include "Enemy.h"

class Player
{
private:
    int hp;
    int maxHp;
    int mp;

    int attackPower;
    int skillPower;
    int healPower;

    bool usedResurrection;

public:
    Player();

    int getHp() const;
    int getMaxHp() const;
    int getMp() const;

    bool isDead() const;
    bool hasUsedResurrection() const;

    void attack(Enemy& enemy);
    bool skill(Enemy& enemy);

    bool heal();
    bool resurrect();

    void takeDamage(int damage);
};

#endif