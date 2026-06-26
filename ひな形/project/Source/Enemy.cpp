#include "Enemy.h"
#include "DxLib.h"
#include <cstdlib>

Enemy::Enemy(int type)
{
    switch (type)
    {
    case 1:
        name = "スライム";
        hp = 75;
        attackPower = 7;
        skillPower = 15;
        break;

    case 2:
        name = "ゴブリン";
        hp = 120;
        attackPower = 10;
        skillPower = 20;
        break;

    case 3:
        name = "ドラゴン";
        hp = 200;
        attackPower = 18;
        skillPower = 35;
        break;

    default:
        name = "スライム";
        hp = 75;
        attackPower = 7;
        skillPower = 15;
        break;
    }
}

int Enemy::getHp() const
{
    return hp;
}

std::string Enemy::getName() const
{
    return name;
}

void Enemy::takeDamage(int damage)
{
    hp -= damage;
    if (hp < 0) hp = 0;
}

int Enemy::act()
{
    return (rand() % 2 == 0) ? attackPower : skillPower;
}

bool Enemy::isDead() const
{
    return hp <= 0;
}