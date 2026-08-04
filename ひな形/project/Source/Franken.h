#pragma once

#include "EnemyBase.h"
#include <string>

class Franken
{
public:
    Franken();
    ~Franken();

    //void Update();
    void Draw(int x, int y);

    // フランケンの行動
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

    int frimage;

    // 最後に使った技名
    std::string lastActionName;
};