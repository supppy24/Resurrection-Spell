#include "Skall.h"
#include "DxLib.h"
#include <cstdlib>

Skall::Skall()
{
    HP = 20;
    Attack = 2;
    Skill = 5;

    skaimage = LoadGraph("image/SKALL.png");
}

Skall::~Skall()
{

}

//void Slime::Update()
//{
//
//}

void Skall::Draw()
{
    DrawGraph(500, 500, 0, true);
}

// 行動
int Skall::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        return Attack;
    }
    else
    {
        return Skill;
    }
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