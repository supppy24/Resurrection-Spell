#pragma once

#include "EnemyBase.h"
#include <string>

class Goblin
{
public:
    Goblin();
    ~Goblin();

    //void Update();
    void Draw(int x, int y);

    // ƒSƒuƒŠƒ“‚Ìs“®
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

    int gobimage;

    // ÅŒã‚Ég‚Á‚½‹Z–¼
    std::string lastActionName;
};