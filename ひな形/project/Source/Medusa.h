#pragma once

#include "EnemyBase.h"

class Medusa
{
public:
    Medusa();
    ~Medusa();

    //void Update();
    void Draw(int x, int y);

    // メドゥーサの行動
    int Act();

    // 最後に使った技名を取得
    std::string GetLastActionName() const;

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int Attack;
    int Skill;

    int medimage;

    // 最後に使った技名
    std::string lastActionName;
};