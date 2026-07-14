#include "Goblin.h"
#include "DxLib.h"
#include <cstdlib>

Goblin::Goblin()
{
    HP = 20;
    Attack = 2;
    Skill = 5;

    gobimage = LoadGraph("image/GOBLIN.png");
}

Goblin::~Goblin()
{

}

//void Slime::Update()
//{
//
//}

void Goblin::Draw()
{
    DrawGraph(500, 500, 0, true);
}

// 行動
int Goblin::Act()
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

int Goblin::GetHP() const
{
    return HP;
}

void Goblin::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Goblin::IsDead() const
{
    return HP <= 0;
}