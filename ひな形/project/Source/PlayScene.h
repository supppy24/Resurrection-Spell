#pragma once

#include <vector>
#include <string>

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

    // プレイヤーと敵
    Player player;
    Enemy enemy;

    // 敵の種類
    int enemyType;

    // コマンド画像
    int kImage;

    // 敵出現メッセージ
    bool newEnemyMessage;
    int messageTimer;

    // ゲーム終了フラグ
    bool isGameOver;

    // プレイヤーターンかどうか
    bool isPlayerTurn;

    // キー入力
    bool oldKey1;
    bool oldKey2;
    bool oldKey3;
    bool oldKey4;

    // バトルログ
    // 最新6件を表示する
    std::vector<std::string> battleLog;

    // ログを追加する関数
    void AddLog(const std::string& text);
};