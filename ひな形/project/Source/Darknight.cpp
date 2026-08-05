#include "Darknight.h"
#include "DxLib.h"
#include <cstdlib>

Darknight::Darknight()
{
    maxHP = 200;
    HP = maxHP;
    Attack = 10;
    Skill = 20;

    turnCount = 0;

    dnimage = LoadGraph("image/DARKNIGHT.png");

    lastActionName = "";
}

Darknight::~Darknight()
{
}

//void Darknight::Update()
//{
//
//}

void Darknight::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, dnimage, true);
}

// 行動
int Darknight::Act()
{
    // ターン数を増やす
    turnCount++;

    // HP割合（%）
    int hpRate = HP * 100 / maxHP;

    //３ターンごとに
    if (turnCount % 3 == 0)
    {
        lastActionName = "黒炎";
        return 50;
    }


    //HPが20%以下になったら
    if (hpRate <= 20)
    {
        lastActionName = "終焉";
        return 100;
    }


    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "ダークチェイン";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "深淵の一撃";

        return Skill;
    }
}

// 最後に使った技名
std::string Darknight::GetLastActionName() const
{
    return lastActionName;
}

int Darknight::GetHP() const
{
    return HP;
}

void Darknight::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Darknight::IsDead() const
{
    return HP <= 0;
}