#pragma once

#include "EnemyBase.h"

class Maou
{
public:
    Maou();
    ~Maou();

    //void Update();
    void Draw();

    // ñÇâ§ÇÃçsìÆ
    int Act();

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int maoimage;
};