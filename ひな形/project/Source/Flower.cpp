#include "Flower.h"
#include "DxLib.h"
#include <cstdlib>

Flower::Flower()
{
    HP = 240;
    Attack = 20;
    Skill = 30;

    flimage = LoadGraph("image/KAIBUTUHANA.png");

    lastActionName = "";
}

Flower::~Flower()
{
}

//void Flower::Update()
//{
//
//}

void Flower::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, flimage, true);
}

// 行動
int Flower::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "ツタ打ち";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "花魔の魅惑";

        return Skill;
    }
}

// 最後に使った技名
std::string Flower::GetLastActionName() const
{
    return lastActionName;
}

int Flower::GetHP() const
{
    return HP;
}

void Flower::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Flower::IsDead() const
{
    return HP <= 0;
}