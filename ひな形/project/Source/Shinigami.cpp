#include "Shinigami.h"
#include "DxLib.h"
#include <cstdlib>

Shinigami::Shinigami()
{
    HP = 80;
    Attack = 10;
    Skill = 25;

    shiimage = LoadGraph("image/SHINIGAMI.png");

    lastActionName = "";
}

Shinigami::~Shinigami()
{
}

//void Shinigami::Update()
//{
//
//}

void Shinigami::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, shiimage, true);
}

// 行動
int Shinigami::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "死神の鎌";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "デットバットエンド";

        return Skill;
    }
}

// 最後に使った技名
std::string Shinigami::GetLastActionName() const
{
    return lastActionName;
}

int Shinigami::GetHP() const
{
    return HP;
}

void Shinigami::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Shinigami::IsDead() const
{
    return HP <= 0;
}