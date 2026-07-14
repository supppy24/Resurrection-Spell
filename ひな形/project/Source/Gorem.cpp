#include "Gorem.h"
#include "DxLib.h"
#include <cstdlib>

Gorem::Gorem()
{
    HP = 20;
    Attack = 2;
    Skill = 5;

    gorimage = LoadGraph("image/GOREM.png");
}

Gorem::~Gorem()
{

}

//void Slime::Update()
//{
//
//}

void Gorem::Draw()
{
    DrawGraph(500, 500, 0, true);
}

// 行動
int Gorem::Act()
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

int Gorem::GetHP() const
{
    return HP;
}

void Gorem::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Gorem::IsDead() const
{
    return HP <= 0;
}