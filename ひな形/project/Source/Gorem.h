#pragma once

#include "EnemyBase.h"

class Gorem
{
public:
    Gorem();
    ~Gorem();

    //void Update();
    void Draw();

    // ƒS[ƒŒƒ€‚Ìs“®
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int gorimage;
};