#include "Doragon.h"
#include "DxLib.h"
#include <cstdlib>

Doragon::Doragon()
{
    HP = 300;
    Attack = 20;
    Skill = 50;

    doraimage = LoadGraph("image/DORAGON.png");
}

Doragon::~Doragon()
{

}

//void Slime::Update()
//{
//
//}

void Doragon::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, doraimage, true);
}

// 行動
int Doragon::Act()
{
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "火球ブレス";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "滅却";

        return Skill;
    }
}

// 最後に使った技名
std::string Doragon::GetLastActionName() const
{
    return lastActionName;
}

int Doragon::GetHP() const
{
    return HP;
}

void Doragon::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Doragon::IsDead() const
{
    return HP <= 0;
}