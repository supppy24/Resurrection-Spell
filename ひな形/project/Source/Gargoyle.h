#pragma once

#include "EnemyBase.h"
#include <string>

class Gargoyle
{
public:
    Gargoyle();
    ~Gargoyle();

    //void Update();
    void Draw(int x, int y);

    // ƒK[ƒSƒCƒ‹‚Ìs“®
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

    int gaimage;

    // ÅŒã‚Ég‚Á‚½‹Z–¼
    std::string lastActionName;
};