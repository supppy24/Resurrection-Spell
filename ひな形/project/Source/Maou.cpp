#include "Maou.h"
#include "DxLib.h"
#include <cstdlib>

//--------------------------------
// コンストラクタ
//--------------------------------
Maou::Maou()
{
    maxHP = 500;
    HP = maxHP;

    Attack = 20;
    Skill = 30;

    turnCount = 0;

    maoimage = LoadGraph("image/MAOU.png");
}

//--------------------------------
// デストラクタ
//--------------------------------
Maou::~Maou()
{
}

//--------------------------------
// 描画
//--------------------------------
void Maou::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, maoimage, true);
}

//--------------------------------
// 行動
//--------------------------------
int Maou::Act()
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
        lastActionName = "滅び行く世界";
        return 50;
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
            lastActionName = "終焉の炎";
            return 50;

        case 1:
            lastActionName = "終焉の波動";
            return 80;

        case 2:
            lastActionName = "終焉の儀式";
            return 80;
        }
    }

    //HPが10%以下になったら
    if (hpRate <= 10)
    {
        lastActionName = "闇の裁き";
        return 120;
    }

    //--------------------------------
    // 通常フェーズ
    //--------------------------------
    int action = rand() % 2;

    if (action == 0)
    {
        lastActionName = "漆黒の炎";
        return Attack;
    }
    else
    {
        lastActionName = "闇の波動";
        return Skill;
    }
}

//--------------------------------
// 最後に使った技名
//--------------------------------
std::string Maou::GetLastActionName() const
{
    return lastActionName;
}

//--------------------------------
// HP取得
//--------------------------------
int Maou::GetHP() const
{
    return HP;
}

//--------------------------------
// ダメージ処理
//--------------------------------
void Maou::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

//--------------------------------
// 死亡判定
//--------------------------------
bool Maou::IsDead() const
{
    return HP <= 0;
}