#include "Gorem.h"
#include "DxLib.h"
#include <cstdlib>

Gorem::Gorem()
{
    HP = 80;
    Attack = 3;
    Skill = 15;

    gorimage = LoadGraph("image/GOLEM.png");
}

Gorem::~Gorem()
{

}

//void Slime::Update()
//{
//
//}

void Gorem::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, gorimage, true);
}

// 行動
int Gorem::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "殴る";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "ふみつけ";

        return Skill;
    }
}

// 最後に使った技名
std::string Gorem::GetLastActionName() const
{
    return lastActionName;
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