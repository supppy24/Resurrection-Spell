#include "Minotauros.h"
#include "DxLib.h"
#include <cstdlib>

Minotauros::Minotauros()
{
    maxHP = 300;
    HP = maxHP;
    Attack = 20;
    Skill = 45;

    turnCount = 0;

    miimage = LoadGraph("image/MINOTAUROSU.png");

    lastActionName = "";
}

Minotauros::~Minotauros()
{
}

//void Minotauros::Update()
//{
//
//}

void Minotauros::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, miimage, true);
}

// 行動
int Minotauros::Act()
{
    // ターン数を増やす
    turnCount++;

    // HP割合（%）
    int hpRate = HP * 100 / maxHP;

    //--------------------------------
    // 5ターンごとに必殺技
    //--------------------------------
    if (turnCount % 5 == 0)
    {
        lastActionName = "超大暴れ";
        return 70;
    }

    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "大斧斬り";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "ギガスマッシュ";

        return Skill;
    }
}

// 最後に使った技名
std::string Minotauros::GetLastActionName() const
{
    return lastActionName;
}

int Minotauros::GetHP() const
{
    return HP;
}

void Minotauros::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Minotauros::IsDead() const
{
    return HP <= 0;
}