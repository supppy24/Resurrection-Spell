#include "Slime.h"
#include "DxLib.h"
#include <cstdlib>

Slime::Slime()
{
    HP = 20;
    Attack = 2;
    Skill = 5;
    slimage = LoadGraph("image/SLIME.png");
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
    //DrawRotaGraph(500,300,0.5,0.0,slimage,true);
    DrawExtendGraph(x, y, x + 128, y + 128, slimage, true);
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