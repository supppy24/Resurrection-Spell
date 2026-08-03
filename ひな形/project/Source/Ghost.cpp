#include "Ghost.h"
#include "DxLib.h"
#include <cstdlib>

Ghost::Ghost()
{
    HP = 50;
    Attack = 2;
    Skill = 7;

    ghoimage = LoadGraph("image/GHOST.png");
}

Ghost::~Ghost()
{

}

//void Slime::Update()
//{
//
//}

void Ghost::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, ghoimage, true);
}

// 行動
int Ghost::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "おちょくる";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "おどろかす";

        return Skill;
    }
}

// 最後に使った技名
std::string Ghost::GetLastActionName() const
{
    return lastActionName;
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