#include "Eiyuu.h"
#include "DxLib.h"
#include <cstdlib>

Eiyuu::Eiyuu()
{
    maxHP = 700;
    HP = maxHP;
    Attack = 5;
    Skill = 10;

    turnCount = 0;

    eiimage = LoadGraph("image/DARKEIYUU.png");

    lastActionName = "";
}

Eiyuu::~Eiyuu()
{
}

//void Eiyuu::Update()
//{
//
//}

void Eiyuu::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, eiimage, true);
}

// 行動
int Eiyuu::Act()
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
        lastActionName = "漆黒の斬撃";
        return 80;
    }

    //--------------------------------
    // HP30%以下
    //--------------------------------
    if (hpRate <= 30)
    {
        int action = rand() % 3;

        switch (action)
        {
        case 0:
            lastActionName = "ダーク";
            return 50;

        case 1:
            lastActionName = "英雄の剣";
            return 70;

        case 2:
            lastActionName = "堕ちた光";
            return 95;
        }
    }
    //HPが10%以下になったら
    if (hpRate <= 10)
    {
        lastActionName = "最後の光";
        return 200;
    }

    //--------------------------------
    // 通常フェーズ
    //--------------------------------
    int action = rand() % 2;

    if (action == 0)
    {
        lastActionName = "連続斬り";
        return Attack;
    }
    else
    {
        lastActionName = "闇の力";
        return Skill;
    }
}

// 最後に使った技名
std::string Eiyuu::GetLastActionName() const
{
    return lastActionName;
}

int Eiyuu::GetHP() const
{
    return HP;
}

void Eiyuu::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Eiyuu::IsDead() const
{
    return HP <= 0;
}