#include "Majyo.h"
#include "DxLib.h"
#include <cstdlib>

Majyo::Majyo()
{
    HP = 100;
    Attack = 3;
    Skill = 45;

    majimage = LoadGraph("image/MAJYO.png");
}

Majyo::~Majyo()
{

}

//void Slime::Update()
//{
//
//}

void Majyo::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, majimage, true);
}

// 行動
int Majyo::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "ファイア";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "禁断の魔法";

        return Skill;
    }
}

// 最後に使った技名
std::string Majyo::GetLastActionName() const
{
    return lastActionName;
}

int Majyo::GetHP() const
{
    return HP;
}

void Majyo::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Majyo::IsDead() const
{
    return HP <= 0;
}