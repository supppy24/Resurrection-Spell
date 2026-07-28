#pragma once

#include "EnemyBase.h"
#include <string>

class Slime
{
public:
    Slime();
    ~Slime();

    //void Update();
    void Draw(int x, int y);

    // スライムの行動
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

    int slimage;

    // 最後に使った技名
    std::string lastActionName;
};