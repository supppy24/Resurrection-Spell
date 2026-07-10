#pragma once

#include "EnemyBase.h"

class Mimick
{
public:
    Mimick();
    ~Mimick();

    //void Update();
    void Draw();

    // ミミックの行動
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int mimiimage;
};