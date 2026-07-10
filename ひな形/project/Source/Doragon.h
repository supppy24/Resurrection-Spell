#pragma once

#include "EnemyBase.h"

class Doragon
{
public:
    Doragon();
    ~Doragon();

    //void Update();
    void Draw();

    // ゴーストの行動
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int doraimage;
};