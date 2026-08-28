#include "Mimick.h"
#include "DxLib.h"
#include <cstdlib>

Mimick::Mimick()
{
    maxHP = 10;
    HP = maxHP;
    Attack = 0;
    Skill = 20;

    turnCount = 0;

    mimiimage = LoadGraph("image/MIMICK.png");
}

Mimick::~Mimick()
{

}

//void Slime::Update()
//{
//
//}

void Mimick::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, mimiimage, true);
}

// 行動
int Mimick::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "こちらを見て笑っている";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "べろべろばぁ";

        return Skill;
    }
}

// 最後に使った技名
std::string Mimick::GetLastActionName() const
{
    return lastActionName;
}

int Mimick::GetHP() const
{
    return HP;
}

void Mimick::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Mimick::IsDead() const
{
    return HP <= 0;
}