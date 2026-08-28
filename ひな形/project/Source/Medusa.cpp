#include "Medusa.h"
#include "DxLib.h"
#include <cstdlib>

Medusa::Medusa()
{
    maxHP = 200;
    HP = maxHP;
    Attack = 10;
    Skill = 25;

    turnCount = 0;

    medimage = LoadGraph("image/MEDUSA.png");
}

Medusa::~Medusa()
{

}

//void Slime::Update()
//{
//
//}

void Medusa::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, medimage, true);
}

// 行動
int Medusa::Act()
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
        lastActionName = "魅惑の蛇";
        return 50;
    }

    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "ヘビのしっぽ";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "石化ビーム";

        return Skill;
    }
}

// 最後に使った技名
std::string Medusa::GetLastActionName() const
{
    return lastActionName;
}

int Medusa::GetHP() const
{
    return HP;
}

void Medusa::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Medusa::IsDead() const
{
    return HP <= 0;
}