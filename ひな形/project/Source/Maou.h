#pragma once

#include "EnemyBase.h"

class Maou
{
public:
    Maou();
    ~Maou();

    //void Update();
    void Draw(int x, int y);

    // –‚‰¤‚Ìs“®
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

    int maoimage;
    // ÅŒã‚Ég‚Á‚½‹Z–¼
    std::string lastActionName;
};