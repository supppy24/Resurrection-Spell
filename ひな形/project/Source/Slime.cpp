#include "Slime.h"
#include "DxLib.h"
#include <cstdlib>

Slime::Slime()
{
    maxHP = 20;
    HP = maxHP;
    Attack = 2;
    Skill = 5;

    turnCount = 0;
    
    slimage = LoadGraph("image/SLIME.png");

    lastActionName = "";
}

Slime::~Slime()
{
}

//void Slime::Update()
//{
//
//}

void Slime::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, slimage, true);
}

// 行動
int Slime::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "たいあたり";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "スライムボール";

        return Skill;
    }
}

// 最後に使った技名
std::string Slime::GetLastActionName() const
{
    return lastActionName;
}

int Slime::GetHP() const
{
    return HP;
}

void Slime::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Slime::IsDead() const
{
    return HP <= 0;
}