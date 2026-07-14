#pragma once

#include "EnemyBase.h"

class Ghost
{
public:
    Ghost();
    ~Ghost();

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

    int ghoimage;
};