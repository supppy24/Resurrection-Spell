#pragma once

#include "EnemyBase.h"

class Doragon2
{
public:
    Doragon2();
    ~Doragon2();

    //void Update();
    void Draw(int x, int y);

    // ドラゴンの行動
    int Act();

    // 最後に使った技名を取得
    std::string GetLastActionName() const;

    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int maxHP;
    int Attack;
    int Skill;

    int turnCount; // 行動ターン数

    int dora2image;

    // 最後に使った技名
    std::string lastActionName;
};