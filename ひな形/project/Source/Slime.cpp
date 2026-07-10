#include "Slime.h"
#include <cstdlib>

Slime::Slime()
{
    HP = 20;
    Attack = 2;
    Skill = 5;
}

Slime::~Slime()
{

}

//void Slime::Update()
//{
//
//}

void Slime::Draw()
{

}

// 行動
int Slime::Act()
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