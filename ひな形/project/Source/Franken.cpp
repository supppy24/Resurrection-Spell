#include "Franken.h"
#include "DxLib.h"
#include <cstdlib>

Franken::Franken()
{
    maxHP = 120;
    HP = maxHP;
    Attack = 20;
    Skill = 25;

    turnCount = 0;

    frimage = LoadGraph("image/FRANKEN.png");

    lastActionName = "";
}

Franken::~Franken()
{
}

//void Franken::Update()
//{
//
//}

void Franken::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, frimage, true);
}

// 行動
int Franken::Act()
{
    // ターン数を増やす
    turnCount++;

    // HP割合（%）
    int hpRate = HP * 100 / maxHP;

    //--------------------------------
    // 5ターンごとに必殺技
    //--------------------------------
    if (turnCount % 5 == 0)
    {
        lastActionName = "フランケンアタック";
        return 45;
    }

    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "怪力パンチ";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "大暴れ";

        return Skill;
    }
}

// 最後に使った技名
std::string Franken::GetLastActionName() const
{
    return lastActionName;
}

int Franken::GetHP() const
{
    return HP;
}

void Franken::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Franken::IsDead() const
{
    return HP <= 0;
}