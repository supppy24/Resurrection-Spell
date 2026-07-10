#include "Majyo.h"
#include <cstdlib>

Majyo::Majyo()
{
    HP = 20;
    Attack = 2;
    Skill = 5;
}

Majyo::~Majyo()
{

}

//void Slime::Update()
//{
//
//}

void Majyo::Draw()
{

}

// 行動
int Majyo::Act()
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

int Majyo::GetHP() const
{
    return HP;
}

void Majyo::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Majyo::IsDead() const
{
    return HP <= 0;
}