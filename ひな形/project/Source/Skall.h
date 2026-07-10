#pragma once

#include "EnemyBase.h"

class Skall
{
public:
    Skall();
    ~Skall();

    //void Update();
    void Draw();

    // ƒXƒJƒ‹‚Ìs“®
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int skaimage;
};