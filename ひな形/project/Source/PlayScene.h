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
    //背景画像
    int haikei;

    // 報酬画面画像
    int rewardImage;

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

    // ゲーム終了
    bool isGameOver;

    // プレイヤーターン
    bool isPlayerTurn;

    // キー入力
    bool oldKey1;
    bool oldKey2;
    bool oldKey3;
    bool oldKey4;

    //------------------------
    // ゲーム状態
    //------------------------
    enum class GameState
    {
        Battle,
        Reward
    };

    GameState gameState;

    // 報酬画面に入った直後か
    bool rewardWaitRelease;

    // バトルログ
    std::vector<std::string> battleLog;

    // ログ追加
    void AddLog(const std::string& text);

    // ステージ読み込み
    void LoadStage(int stage);

    // 報酬適用
    void ApplyReward(int choice);

    // 経過ターン数
    int turnCount;

    // 現在の階層（1階から表示用）
    int floorNumber;
};