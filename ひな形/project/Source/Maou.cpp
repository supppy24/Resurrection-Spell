#include "Maou.h"
#include "DxLib.h"
#include <cstdlib>

Maou::Maou()
{
    HP = 500;
    Attack = 20;
    Skill = 50;

    maoimage = LoadGraph("image/MAOU.png");
}

Maou::~Maou()
{

}

//void Slime::Update()
//{
//
//}

void Maou::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, maoimage, true);
}

// 行動
int Maou::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "漆黒の炎";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "闇の波動";

        return Skill;
    }
}

// 最後に使った技名
std::string Maou::GetLastActionName() const
{
    return lastActionName;
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