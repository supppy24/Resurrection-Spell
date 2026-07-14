#include "Ghost.h"
#include "DxLib.h"
#include <cstdlib>

Ghost::Ghost()
{
    HP = 20;
    Attack = 2;
    Skill = 5;

    ghoimage = LoadGraph("image/GHOST.png");
}

Ghost::~Ghost()
{

}

//void Slime::Update()
//{
//
//}

void Ghost::Draw()
{
    DrawGraph(500, 500, 0, true);
}

// 行動
int Ghost::Act()
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

int Ghost::GetHP() const
{
    return HP;
}

void Ghost::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Ghost::IsDead() const
{
    return HP <= 0;
}