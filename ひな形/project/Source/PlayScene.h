#pragma once

#include "../Library/SceneBase.h"

#include "Player.h"
#include "Enemy.h"

class PlayScene : public SceneBase
{
public:
    PlayScene();
    ~PlayScene();

    void Update() override;
    void Draw() override;

private:
    Player player;
    Enemy enemy;

    bool isGameOver;
    bool isPlayerTurn;

    bool oldKey1;
    bool oldKey2;
    bool oldKey3;
    bool oldKey4;
};