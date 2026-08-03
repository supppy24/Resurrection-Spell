#pragma once

#include "EnemyBase.h"

class Doragon
{
public:
    Doragon();
    ~Doragon();

    //void Update();
    void Draw(int x, int y);

    // ƒhƒ‰ƒSƒ“‚Ìs“®
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

    int doraimage;

    // ÅŒã‚Ég‚Á‚½‹Z–¼
    std::string lastActionName;
};