#pragma once

#include "EnemyBase.h"
#include <string>

class Minotauros
{
public:
    Minotauros();
    ~Minotauros();

    //void Update();
    void Draw(int x, int y);

    // ミノタウロスの行動
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

    int miimage;

    // 最後に使った技名
    std::string lastActionName;
};