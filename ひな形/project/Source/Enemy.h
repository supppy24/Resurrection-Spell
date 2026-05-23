#ifndef ENEMY_H
#define ENEMY_H

class Enemy
{
private:
    int hp;

    int attackPower;
    int skillPower;

public:
    Enemy();

    int getHp() const;

    void takeDamage(int damage);

    int act();

    bool isDead() const;
};

#endif