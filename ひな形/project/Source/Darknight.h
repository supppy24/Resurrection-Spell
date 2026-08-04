#pragma once

#include "EnemyBase.h"
#include <string>

class Darknight
{
public:
    Darknight();
    ~Darknight();

    //void Update();
    void Draw(int x, int y);

    // •‹Rm‚Ìs“®
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

    int dnimage;

    // ÅŒã‚Ég‚Á‚½‹Z–¼
    std::string lastActionName;
}; 
#pragma once
