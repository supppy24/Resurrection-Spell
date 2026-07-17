#pragma once

#include "EnemyBase.h"

class Slime
{
public:
    Slime();
    ~Slime();

    //void Update();
    void Draw(int x, int y);

    // ƒXƒ‰ƒCƒ€‚Ìs“®
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int slimage;
};