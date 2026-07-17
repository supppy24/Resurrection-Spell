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

    // プレイヤー
    Player player;

    // 現在出現している敵
    std::vector<Enemy> enemies;

    // ステージごとの敵
    std::vector<std::vector<int>> stages;

    // 現在のステージ番号
    int currentStage;

    // コマンド画像
    int kImage;

    // 敵出現メッセージ
    bool newEnemyMessage;
    int messageTimer;

    // ゲーム終了
    bool isGameOver;

    // プレイヤーターン
    bool isPlayerTurn;

    // キー入力
    bool oldKey1;
    bool oldKey2;
    bool oldKey3;
    bool oldKey4;

    // バトルログ
    std::vector<std::string> battleLog;

    // ログ追加
    void AddLog(const std::string& text);

    // ステージ読み込み
    void LoadStage(int stage);
};