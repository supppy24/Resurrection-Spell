#pragma once

#include <string>

class Maou
{
public:
    Maou();
    ~Maou();

    // 描画
    void Draw(int x, int y);

    // 行動
    int Act();

    // 最後に使った技名
    std::string GetLastActionName() const;

    // HP関連
    int GetHP() const;
    void TakeDamage(int damage);
    bool IsDead() const;

private:
    int HP;
    int maxHP;

    int Attack; // 通常攻撃力
    int Skill;  // スキル攻撃力

    int turnCount; // 行動ターン数

    int maoimage;

    // 最後に使った技名
    std::string lastActionName;
};