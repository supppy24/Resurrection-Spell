#include "Player.h"

Player::Player()
    : hp(50),
    maxHp(50),
    mp(30),
    attackPower(5),
    skillPower(15),
    healPower(15),
    usedResurrection(false)
{
}

int Player::getHp() const
{
    return hp;
}

int Player::getMaxHp() const
{
    return maxHp;
}

int Player::getMp() const
{
    return mp;
}

bool Player::isDead() const
{
    return hp <= 0;
}

bool Player::hasUsedResurrection() const
{
    return usedResurrection;
}

void Player::attack(Enemy& enemy)
{
    enemy.takeDamage(attackPower);
}

bool Player::skill(Enemy& enemy)
{
    if (mp < 7)
    {
        return false;
    }

    enemy.takeDamage(skillPower);

    mp -= 7;

    return true;
}

bool Player::heal()
{
    if (mp < 3)
    {
        return false;
    }

    hp += healPower;

    if (hp > maxHp)
    {
        hp = maxHp;
    }

    mp -= 3;

    return true;
}

bool Player::resurrect()
{
    if (usedResurrection)
    {
        return false;
    }

    hp = maxHp;

    usedResurrection = true;

    return true;
}

void Player::takeDamage(int damage)
{
    hp -= damage;

    if (hp < 0)
    {
        hp = 0;
    }
}