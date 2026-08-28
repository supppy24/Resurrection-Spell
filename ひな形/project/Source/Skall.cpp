#include "Skall.h"
#include "DxLib.h"
#include <cstdlib>

Skall::Skall()
{
    maxHP = 25;
    HP = maxHP;
    Attack = 10;
    Skill = 20;

    int turnCount; // 行動ターン数

    skaimage = LoadGraph("image/SKALL.png");
}

Skall::~Skall()
{

}

//void Slime::Update()
//{
//
//}

void Skall::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, skaimage, true);
}

// 行動
int Skall::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "ボーンアタック";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "骨投げ";

        return Skill;
    }
}

// 最後に使った技名
std::string Skall::GetLastActionName() const
{
    return lastActionName;
}


int Skall::GetHP() const
{
    return HP;
}

void Skall::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Skall::IsDead() const
{
    return HP <= 0;
}