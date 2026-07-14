#include "Medusa.h"
#include "DxLib.h"
#include <cstdlib>

Medusa::Medusa()
{
    HP = 20;
    Attack = 2;
    Skill = 5;

    medimage = LoadGraph("image/MEDUSA.png");
}

Medusa::~Medusa()
{

}

//void Slime::Update()
//{
//
//}

void Medusa::Draw()
{
    DrawGraph(500, 500, 0, true);
}

// 行動
int Medusa::Act()
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