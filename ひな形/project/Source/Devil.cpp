#include "Devil.h"
#include "DxLib.h"
#include <cstdlib>

Devil::Devil()
{
    HP = 50;
    Attack = 10;
    Skill = 25;

    deimage = LoadGraph("image/DEVIL.png");

    lastActionName = "";
}

Devil::~Devil()
{
}

//void Devil::Update()
//{
//
//}

void Devil::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, deimage, true);
}

// 行動
int Devil::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "ナイトメア";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "アビスゲート";

        return Skill;
    }
}

// 最後に使った技名
std::string Devil::GetLastActionName() const
{
    return lastActionName;
}

int Devil::GetHP() const
{
    return HP;
}

void Devil::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Devil::IsDead() const
{
    return HP <= 0;
}