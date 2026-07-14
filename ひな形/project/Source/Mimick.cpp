#include "Mimick.h"
#include "DxLib.h"
#include <cstdlib>

Mimick::Mimick()
{
    HP = 20;
    Attack = 2;
    Skill = 5;

    mimiimage = LoadGraph("image/MIMICK.png");
}

Mimick::~Mimick()
{

}

//void Slime::Update()
//{
//
//}

void Mimick::Draw()
{
    DrawGraph(500, 500, 0, true);
}

// 行動
int Mimick::Act()
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

int Mimick::GetHP() const
{
    return HP;
}

void Mimick::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Mimick::IsDead() const
{
    return HP <= 0;
}