#include "Majyo.h"
#include "DxLib.h"
#include <cstdlib>

Majyo::Majyo()
{
    maxHP = 200;
    HP = maxHP;
    Attack = 3;
    Skill = 45;

    turnCount = 0;

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
    // ターン数を増やす
    turnCount++;

    // HP割合（%）
    int hpRate = HP * 100 / maxHP;

    //３ターンごとに
    if (turnCount % 3 == 0)
    {
        lastActionName = "混合魔法";
        return 80;
    }

    //HPが10%以下になったら
    if (hpRate <= 10)
    {
        lastActionName = "最終禁断魔法";
        return 120;
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
            lastActionName = "ギガファイア";
            return 60;

        case 1:
            lastActionName = "ギガサンダー";
            return 60;

        case 2:
            lastActionName = "ギガアイス";
            return 60;
        }
    }

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
        lastActionName = "アイス";

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