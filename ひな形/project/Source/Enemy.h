#ifndef ENEMY_H
#define ENEMY_H

#include <memory>

#include "Slime.h"
#include "Goblin.h"
#include "Dragon.h"
#include "Mimick.h"
#include "Ghost.h"
#include "Gorem.h"
#include "Majyo.h"
#include "Maou.h"
#include "Medusa.h"
#include "Skall.h"

class Enemy
{
public:

    Enemy(int type = 1);

    void Update();
    void Draw();

    int Act();

    void TakeDamage(int damage);

    bool IsDead();

    int GetHP();

    int GetImage();

    const char* GetName();

private:

    int enemyType;

    // ç°êÌÇ¡ÇƒÇ¢ÇÈìG
    Slime slime;
    Goblin goblin;
    Doragon dragon;
    Mimick mimick;
    Ghost ghost;
    Gorem gorem;
    Majyo majyo;
    Maou maou;
    Medusa medusa;
    Skall skall;
};

#endif