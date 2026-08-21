#include "Doragon3.h"
#include "DxLib.h"
#include <cstdlib>

Doragon3::Doragon3()
{
    maxHP = 300;
    HP = maxHP;
    Attack = 20;
    Skill = 50;

    dora3image = LoadGraph("image/SILVERDRAGON.png");
}

Doragon3::~Doragon3()
{

}

//void Slime::Update()
//{
//
//}

void Doragon3::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, dora3image, true);
}

// 行動
int Doragon3::Act()
{
    // ターン数を増やす
    turnCount++;

    // HP割合（%）
    int hpRate = HP * 100 / maxHP;

    //--------------------------------
    // 3ターンごとに必殺技
    //--------------------------------
    if (turnCount % 3 == 0)
    {
        lastActionName = "シルバーフレイム";
        return 80;
    }

    //--------------------------------
    // HP30%以下
    //--------------------------------
    if (hpRate <= 30)
    {
        int action = rand() % 3;

        switch (action)
        {
        case 0:
            lastActionName = "銀翼ブレス";
            return 50;

        case 1:
            lastActionName = "銀の伊吹";
            return 80;

        case 2:
            lastActionName = "天雷";
            return 100;
        }
    }


    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "シルバーブレス";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "銀龍ノ咆哮";

        return Skill;
    }
}

// 最後に使った技名
std::string Doragon3::GetLastActionName() const
{
    return lastActionName;
}

int Doragon3::GetHP() const
{
    return HP;
}

void Doragon3::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Doragon3::IsDead() const
{
    return HP <= 0;
}