#include "Gargoyle.h"
#include "DxLib.h"
#include <cstdlib>

Gargoyle::Gargoyle()
{
    maxHP = 180;
    HP = maxHP;
    Attack = 12;
    Skill = 15;

    turnCount = 0;

    gaimage = LoadGraph("image/GARGOYLE.png");

    lastActionName = "";
}

Gargoyle::~Gargoyle()
{
}

//void Gargoyle::Update()
//{
//
//}

void Gargoyle::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, gaimage, true);
}

// 行動
int Gargoyle::Act()
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
        lastActionName = "乱れ急降下";
        return 80;
    }

    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "石爪";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "急降下突撃";

        return Skill;
    }
}

// 最後に使った技名
std::string Gargoyle::GetLastActionName() const
{
    return lastActionName;
}

int Gargoyle::GetHP() const
{
    return HP;
}

void Gargoyle::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Gargoyle::IsDead() const
{
    return HP <= 0;
}