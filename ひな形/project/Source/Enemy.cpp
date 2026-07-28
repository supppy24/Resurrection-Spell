#include "Enemy.h"
#include "DxLib.h"
#include <cstdlib>


Enemy::Enemy(int type)
{
    enemyType = type;
}


//--------------------------------
// HPæ“¾
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
// –¼‘Oæ“¾
//--------------------------------
std::string Enemy::getName() const
{

    switch (enemyType)
    {

    case 1:
        return "ƒXƒ‰ƒCƒ€";


    case 2:
        return "ƒSƒuƒŠƒ“";


    case 3:
        return "ƒhƒ‰ƒSƒ“";


    case 4:
        return "ƒ~ƒ~ƒbƒN";


    case 5:
        return "ƒS[ƒXƒg";


    case 6:
        return "ƒS[ƒŒƒ€";


    case 7:
        return "–‚—";


    case 8:
        return "–‚‰¤";


    case 9:
        return "ƒƒfƒ…[ƒT";


    case 10:
        return "ƒXƒJƒ‹";

    }


    return " ";
}



//--------------------------------
// ‰æ‘œæ“¾
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

        doragon.Draw();

        break;


    case 4:

        mimick.Draw();

        break;


    case 5:

        ghost.Draw();

        break;


    case 6:

        gorem.Draw();

        break;


    case 7:

        majyo.Draw();

        break;


    case 8:

        maou.Draw();

        break;


    case 9:

        medusa.Draw();

        break;


    case 10:

        skall.Draw();

        break;

    }

}



//--------------------------------
// ƒ_ƒ[ƒW
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
// “G‚Ìs“®
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
// ÅŒã‚Ég‚Á‚½‹Z–¼
//--------------------------------
std::string Enemy::getLastActionName() const
{
    switch (enemyType)
    {
    case 1:
        return slime.GetLastActionName();

    case 2:
        return goblin.GetLastActionName();

        // ‚Ü‚¾–¢‘Î‰‚Ì“G
    case 3:
        return "UŒ‚";

    case 4:
        return "UŒ‚";

    case 5:
        return "UŒ‚";

    case 6:
        return "UŒ‚";

    case 7:
        return "UŒ‚";

    case 8:
        return "UŒ‚";

    case 9:
        return "UŒ‚";

    case 10:
        return "UŒ‚";
    }

    return "UŒ‚";
}

//--------------------------------
// €–S”»’è
//--------------------------------
bool Enemy::isDead() const
{

    return getHp() <= 0;

}