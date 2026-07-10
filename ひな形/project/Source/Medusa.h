#pragma once

#include "EnemyBase.h"

class Medusa
{
public:
    Medusa();
    ~Medusa();

    //void Update();
    void Draw();

    // メドゥーサの行動
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int medimage;
};