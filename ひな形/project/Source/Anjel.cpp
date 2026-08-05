#include "Anjel.h"
#include "DxLib.h"
#include <cstdlib>

Anjel::Anjel()
{
    maxHP = 100;
    HP = maxHP;
    Attack = 5;
    Skill = 10;

    turnCount = 0;

    animage = LoadGraph("image/ANJEL.png");

    lastActionName = "";
}

Anjel::~Anjel()
{
}

//void Anjel::Update()
//{
//
//}

void Anjel::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, animage, true);
}

// 行動
int Anjel::Act()
{

    // ターン数を増やす
    turnCount++;

    // HP割合（%）
    int hpRate = HP * 100 / maxHP;

    //３ターンごとに
    if (turnCount % 3 == 0)
    {
        lastActionName = "ホワイトジャッジメント";
        return 80;
    }

    //HPが10%以下になったら
    if (hpRate <= 10) 
    {
        lastActionName = "最後の審判";
        return 120;
    }

    //通常行動
    // 0なら通常攻撃、1ならスキル
    int action = rand() % 2;

    if (action == 0)
    {
        // 通常攻撃名を保存
        lastActionName = "天使の癒し";

        return Attack;
    }
    else
    {
        // スキル名を保存
        lastActionName = "天使の罰";

        return Skill;
    }
}

// 最後に使った技名
std::string Anjel::GetLastActionName() const
{
    return lastActionName;
}

int Anjel::GetHP() const
{
    return HP;
}

void Anjel::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Anjel::IsDead() const
{
    return HP <= 0;
}