#pragma once

#include "EnemyBase.h"
#include <string>

class Devil
{
public:
    Devil();
    ~Devil();

    //void Update();
    void Draw(int x, int y);

    // ˆ«–‚‚Ìs“®
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

    int deimage;

    // ÅŒã‚Ég‚Á‚½‹Z–¼
    std::string lastActionName;
}; 
