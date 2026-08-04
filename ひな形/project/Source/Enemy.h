#pragma once

#include <string>

#include "Slime.h"
#include "Goblin.h"
#include "Doragon.h"
#include "Mimick.h"
#include "Ghost.h"
#include "Gorem.h"
#include "Majyo.h"
#include "Maou.h"
#include "Medusa.h"
#include "Skall.h"
#include "Anjel.h"
#include "Darknight.h"
#include "Devil.h"
#include "Eiyuu.h"
#include "Franken.h"
#include "Gargoyle.h"
#include "Flower.h"
#include "Minotauros.h"
#include "Shinigami.h"


class Enemy
{
private:

    // 現在出現している敵番号
    int enemyType;


    // 各敵クラス
    Slime slime;
    Goblin goblin;
    Doragon doragon;
    Mimick mimick;
    Ghost ghost;
    Gorem gorem;
    Majyo majyo;
    Maou maou;
    Medusa medusa;
    Skall skall;
    Anjel anjel;
    Darknight darknight;
    Devil devil;
    Eiyuu eiyuu;
    Franken franken;
    Gargoyle gargoyle;
    Flower flower;
    Minotauros mino;
    Shinigami shinigami;

public:

    Enemy(int type = 1);


    // HP取得
    int getHp() const;


    // 名前取得
    std::string getName() const;


    // ダメージを受ける
    void takeDamage(int damage);


    // 敵の行動
    int act();

    // 最後に使った技名
    std::string getLastActionName() const;


    // 死亡判定
    bool isDead() const;


    // 画像取得
    void Draw(int x, int y);

};