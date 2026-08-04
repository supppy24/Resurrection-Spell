#pragma once

#include "EnemyBase.h"
#include <string>

class Shinigami
{
public:
    Shinigami();
    ~Shinigami();

    //void Update();
    void Draw(int x, int y);

    // 死神の行動
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

    int shiimage;

    // 最後に使った技名
    std::string lastActionName;
};