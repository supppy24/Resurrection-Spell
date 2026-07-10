#pragma once

#include "EnemyBase.h"

class Goblin
{
public:
    Goblin();
    ~Goblin();

    //void Update();
    void Draw();

    // ƒSƒuƒŠƒ“‚Ìs“®
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int gobimage;
};