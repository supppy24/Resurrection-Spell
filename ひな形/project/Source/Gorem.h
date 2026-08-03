#pragma once

#include "EnemyBase.h"

class Gorem
{
public:
    Gorem();
    ~Gorem();

    //void Update();
    void Draw(int x, int y);

    // ƒS[ƒŒƒ€‚Ìs“®
    int Act();

    // ÅŒã‚Ég‚Á‚½‹Z–¼‚ğæ“¾
    std::string GetLastActionName() const;

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int gorimage;

    // ÅŒã‚Ég‚Á‚½‹Z–¼
    std::string lastActionName;
};