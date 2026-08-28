#include "Enemy.h"
#include "DxLib.h"
#include <cstdlib>

//--------------------------------
// コンストラクタ
//--------------------------------
Enemy::Enemy(int type)
{
    enemyType = type;
}


//--------------------------------
// HP取得
//--------------------------------
int Enemy::getHp() const
{
    switch (enemyType)
    {
    case 1:  return slime.GetHP();
    case 2:  return goblin.GetHP();
    case 3:  return doragon.GetHP();
    case 4:  return mimick.GetHP();
    case 5:  return ghost.GetHP();
    case 6:  return gorem.GetHP();
    case 7:  return majyo.GetHP();
    case 8:  return maou.GetHP();
    case 9:  return medusa.GetHP();
    case 10: return skall.GetHP();
    case 11: return anjel.GetHP();
    case 12: return darknight.GetHP();
    case 13: return devil.GetHP();
    case 14: return eiyuu.GetHP();
    case 15: return franken.GetHP();
    case 16: return gargoyle.GetHP();
    case 17: return flower.GetHP();
    case 18: return mino.GetHP();
    case 19: return shinigami.GetHP();
    case 20: return darkanjel.GetHP();
    case 21: return doragon2.GetHP();
    case 22: return doragon3.GetHP();
    }

    return 0;
}


//--------------------------------
// 名前取得
//--------------------------------
std::string Enemy::getName() const
{
    switch (enemyType)
    {
    case 1:  return "スライム";
    case 2:  return "ゴブリン";
    case 3:  return "ドラゴン";
    case 4:  return "ミミック";
    case 5:  return "ゴースト";
    case 6:  return "ゴーレム";
    case 7:  return "魔女";
    case 8:  return "魔王";
    case 9:  return "メデューサ";
    case 10: return "スカル";
    case 11: return "エンジェル";
    case 12: return "黒騎士";
    case 13: return "悪魔";
    case 14: return "堕ちた英雄";
    case 15: return "フランケン";
    case 16: return "ガーゴイル";
    case 17: return "化物花";
    case 18: return "ミノタウロス";
    case 19: return "死神";
    case 20: return "堕天使";
    case 21: return "ドラゴン2";
    case 22: return "ドラゴン3";
    }

    return "不明な敵";
}


//--------------------------------
// 画像描画
//--------------------------------
void Enemy::Draw(int x, int y)
{
    switch (enemyType)
    {
    case 1:
        slime.Draw(x, y);
        break;

    case 2:
        goblin.Draw(x, y);
        break;

    case 3:
        doragon.Draw(x, y);
        break;

    case 4:
        mimick.Draw(x, y);
        break;

    case 5:
        ghost.Draw(x, y);
        break;

    case 6:
        gorem.Draw(x, y);
        break;

    case 7:
        majyo.Draw(x, y);
        break;

    case 8:
        maou.Draw(x, y);
        break;

    case 9:
        medusa.Draw(x, y);
        break;

    case 10:
        skall.Draw(x, y);
        break;

    case 11:
        anjel.Draw(x, y);
        break;

    case 12:
        darknight.Draw(x, y);
        break;

    case 13:
        devil.Draw(x, y);
        break;

    case 14:
        eiyuu.Draw(x, y);
        break;

    case 15:
        franken.Draw(x, y);
        break;

    case 16:
        gargoyle.Draw(x, y);
        break;

    case 17:
        flower.Draw(x, y);
        break;

    case 18:
        mino.Draw(x, y);
        break;

    case 19:
        shinigami.Draw(x, y);
        break;

    case 20:
        darkanjel.Draw(x, y);
        break;

    case 21:
        doragon2.Draw(x, y);
        break;

    case 22:
        doragon3.Draw(x, y);
        break;
    }
}


//--------------------------------
// ダメージ
//--------------------------------
void Enemy::takeDamage(int damage)
{
    switch (enemyType)
    {
    case 1:
        slime.TakeDamage(damage);
        break;

    case 2:
        goblin.TakeDamage(damage);
        break;

    case 3:
        doragon.TakeDamage(damage);
        break;

    case 4:
        mimick.TakeDamage(damage);
        break;

    case 5:
        ghost.TakeDamage(damage);
        break;

    case 6:
        gorem.TakeDamage(damage);
        break;

    case 7:
        majyo.TakeDamage(damage);
        break;

    case 8:
        maou.TakeDamage(damage);
        break;

    case 9:
        medusa.TakeDamage(damage);
        break;

    case 10:
        skall.TakeDamage(damage);
        break;

    case 11:
        anjel.TakeDamage(damage);
        break;

    case 12:
        darknight.TakeDamage(damage);
        break;

    case 13:
        devil.TakeDamage(damage);
        break;

    case 14:
        eiyuu.TakeDamage(damage);
        break;

    case 15:
        franken.TakeDamage(damage);
        break;

    case 16:
        gargoyle.TakeDamage(damage);
        break;

    case 17:
        flower.TakeDamage(damage);
        break;

    case 18:
        mino.TakeDamage(damage);
        break;

    case 19:
        shinigami.TakeDamage(damage);
        break;

    case 20:
        darkanjel.TakeDamage(damage);
        break;

    case 21:
        doragon2.TakeDamage(damage);
        break;

    case 22:
        doragon3.TakeDamage(damage);
        break;
    }
}


//--------------------------------
// 敵の行動
//--------------------------------
int Enemy::act()
{
    switch (enemyType)
    {
    case 1:
        return slime.Act();

    case 2:
        return goblin.Act();

    case 3:
        return doragon.Act();

    case 4:
        return mimick.Act();

    case 5:
        return ghost.Act();

    case 6:
        return gorem.Act();

    case 7:
        return majyo.Act();

    case 8:
        return maou.Act();

    case 9:
        return medusa.Act();

    case 10:
        return skall.Act();

    case 11:
        return anjel.Act();

    case 12:
        return darknight.Act();

    case 13:
        return devil.Act();

    case 14:
        return eiyuu.Act();

    case 15:
        return franken.Act();

    case 16:
        return gargoyle.Act();

    case 17:
        return flower.Act();

    case 18:
        return mino.Act();

    case 19:
        return shinigami.Act();

    case 20:
        return darkanjel.Act();

    case 21:
        return doragon2.Act();

    case 22:
        return doragon3.Act();
    }

    return 0;
}


//--------------------------------
// 最後に使った技名
//--------------------------------
std::string Enemy::getLastActionName() const
{
    switch (enemyType)
    {
    case 1:
        return slime.GetLastActionName();

    case 2:
        return goblin.GetLastActionName();

    case 3:
        return doragon.GetLastActionName();

    case 4:
        return mimick.GetLastActionName();

    case 5:
        return ghost.GetLastActionName();

    case 6:
        return gorem.GetLastActionName();

    case 7:
        return majyo.GetLastActionName();

    case 8:
        return maou.GetLastActionName();

    case 9:
        return medusa.GetLastActionName();

    case 10:
        return skall.GetLastActionName();

    case 11:
        return anjel.GetLastActionName();

    case 12:
        return darknight.GetLastActionName();

    case 13:
        return devil.GetLastActionName();

    case 14:
        return eiyuu.GetLastActionName();

    case 15:
        return franken.GetLastActionName();

    case 16:
        return gargoyle.GetLastActionName();

    case 17:
        return flower.GetLastActionName();

    case 18:
        return mino.GetLastActionName();

    case 19:
        return shinigami.GetLastActionName();

    case 20:
        return darkanjel.GetLastActionName();

    case 21:
        return doragon2.GetLastActionName();

    case 22:
        return doragon3.GetLastActionName();
    }

    return "攻撃";
}


//--------------------------------
// 死亡判定
//--------------------------------
bool Enemy::isDead() const
{
    return getHp() <= 0;
}