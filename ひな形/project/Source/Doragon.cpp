#include "Doragon.h"
#include <cstdlib>

Doragon::Doragon()
{
    HP = 20;
    Attack = 2;
    Skill = 5;
}

Doragon::~Doragon()
{

}

//void Slime::Update()
//{
//
//}

void Doragon::Draw()
{

}

// 行動
int Doragon::Act()
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

int Doragon::GetHP() const
{
    return HP;
}

void Doragon::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Doragon::IsDead() const
{
    return HP <= 0;
}