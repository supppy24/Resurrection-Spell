#include "Enemy.h"
#include "DxLib.h"
#include <cstdlib>


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

    case 1:
        return slime.GetHP();


    case 2:
        return goblin.GetHP();


    case 3:
        return doragon.GetHP();


    case 4:
        return mimick.GetHP();


    case 5:
        return ghost.GetHP();


    case 6:
        return gorem.GetHP();


    case 7:
        return majyo.GetHP();


    case 8:
        return maou.GetHP();


    case 9:
        return medusa.GetHP();


    case 10:
        return skall.GetHP();

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

    case 1:
        return "スライム";


    case 2:
        return "ゴブリン";


    case 3:
        return "ドラゴン";


    case 4:
        return "ミミック";


    case 5:
        return "ゴースト";


    case 6:
        return "ゴーレム";


    case 7:
        return "魔女";


    case 8:
        return "魔王";


    case 9:
        return "メデューサ";


    case 10:
        return "スカル";

    }


    return " ";
}



//--------------------------------
// 画像取得
//--------------------------------
void Enemy::Draw(int x, int y)
{

    switch (enemyType)
    {

    case 1:

        slime.Draw(x,y);

        break;


    case 2:

        goblin.Draw(x,y);

        break;


    case 3:

        doragon.Draw(x,y);

        break;


    case 4:

        mimick.Draw(x,y);

        break;


    case 5:

        ghost.Draw(x,y);

        break;


    case 6:

        gorem.Draw(x,y);

        break;


    case 7:

        majyo.Draw(x,y);

        break;


    case 8:

        maou.Draw(x,y);

        break;


    case 9:

        medusa.Draw(x,y);

        break;


    case 10:

        skall.Draw(x,y);

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