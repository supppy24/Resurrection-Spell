#include "Enemy.h"

#include <cstdlib>

Enemy::Enemy()
    : hp(75),
    attackPower(7),
    skillPower(15)
{
}

int Enemy::getHp() const
{
    return hp;
}

void Enemy::takeDamage(int damage)
{
    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }
}

int Enemy::act()
{
    int enemyCommand = rand() % 2;

    if (enemyCommand == 0)
    {
        return attackPower;
    }

    return skillPower;
}

bool Enemy::isDead() const
{
    return hp <= 0;
}