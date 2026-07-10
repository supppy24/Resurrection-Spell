#include "Maou.h"
#include <cstdlib>

Maou::Maou()
{
    HP = 20;
    Attack = 2;
    Skill = 5;
}

Maou::~Maou()
{

}

//void Slime::Update()
//{
//
//}

void Maou::Draw()
{

}

// 行動
int Maou::Act()
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

int Maou::GetHP() const
{
    return HP;
}

void Maou::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Maou::IsDead() const
{
    return HP <= 0;
}