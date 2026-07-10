#pragma once

#include "EnemyBase.h"

class Majyo
{
public:
    Majyo();
    ~Majyo();

    //void Update();
    void Draw();

    // –‚—‚Ìs“®
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int majimage;
};