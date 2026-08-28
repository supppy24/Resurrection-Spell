#include "Goblin.h"
#include "DxLib.h"
#include <cstdlib>

Goblin::Goblin()
{
    maxHP = 30;
    HP = maxHP;
    Attack = 4;
    Skill = 5;

    gobimage = LoadGraph("image/GOBLIN.png");

    lastActionName = "";
}

Goblin::~Goblin()
{
}

//void Goblin::Update()
//{
//
//}

void Goblin::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, gobimage, true);
}

// 行動
int Goblin::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名
        lastActionName = "こんぼうなぐり";

        return Attack;
    }
    else
    {
        // スキル名
        lastActionName = "ゴブリンパンチ";

        return Skill;
    }
}

// 最後に使った技名
std::string Goblin::GetLastActionName() const
{
    return lastActionName;
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