#include <ctime>
#include <vector>
#include <string>

#include "DxLib.h"

#include "../Library/SceneManager.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
    haikei = LoadGraph("image/HAIKEI2.png");
    kImage = LoadGraph("image/Komando.jpg");
    rewardImage = LoadGraph("image/Reward.png");
    gameOverImage = LoadGraph("image/GAMEOVER.png");
    gameClearImage = LoadGraph("image/GAMECLEAR.png");

    srand((unsigned int)time(nullptr));

    isGameOver = false;
    isPlayerTurn = true;

    gameOverStartTime = 0;
    gameClearStartTime = 0;

    oldKey1 = false;
    oldKey2 = false;
    oldKey3 = false;
    oldKey4 = false;

    // ゲーム状態
    gameState = GameState::Battle;

    // 入力待ち
    rewardWaitRelease = false;

    // ステージ番号
    currentStage = 0;

    // ステージ設定
    stages =
    {
        //5階層ごとに中ボス立ち位置、10階層ごとに大ボス立ち位置
        {1},
        {2},
        {10},
        {5},
        {18},//5
        {4},
        {1,2},
        {6},
        {17},
        {9},//10
        {5},
        {15},
        {16},
        {10,5},
        {12},//15
        {4},
        {2,17},
        {11},
        {20},
        {11,20},//20
        {4},
        {13},
        {19},
        {6,15},
        {7},//25
        {3},
        {21},
        {22},
        {8},
        {14},//30
    };

    LoadStage(currentStage);

    battleLog.clear();
    AddLog("敵が現れた！");

    // 経過ターン
    turnCount = 1;

    // 現在の階層
    floorNumber = 1;
}

PlayScene::~PlayScene()
{
}

void PlayScene::LoadStage(int stage)
{
    enemies.clear();

    for (int type : stages[stage])
    {
        enemies.push_back(Enemy(type));
    }
}

void PlayScene::Update()
{
    if (CheckHitKey(KEY_INPUT_T))
    {
        SceneManager::ChangeScene("TITLE");
    }

    if (isGameOver)
    {
        // GAME OVERになってから3秒経過したか
        if (GetNowCount() - gameOverStartTime >= 3000)
        {
            SceneManager::ChangeScene("TITLE");
        }

        return;
    }

    if (isGameClear)
    {
        // GAME CLEARになってから5秒経過
        if (GetNowCount() - gameClearStartTime >= 5000)
        {
            SceneManager::ChangeScene("TITLE");
        }

        return;
    }

    //------------------------
    // 報酬画面
    //------------------------
    if (gameState == GameState::Reward)
    {
        // キーが離されるまで待つ
        if (rewardWaitRelease)
        {
            if (!CheckHitKey(KEY_INPUT_1) &&
                !CheckHitKey(KEY_INPUT_2) &&
                !CheckHitKey(KEY_INPUT_3))
            {
                rewardWaitRelease = false;
            }

            return;
        }

        if (CheckHitKey(KEY_INPUT_1))
        {
            ApplyReward(1);
        }
        else if (CheckHitKey(KEY_INPUT_2))
        {
            ApplyReward(2);
        }
        else if (CheckHitKey(KEY_INPUT_3))
        {
            ApplyReward(3);
        }

        return;
    }

    //------------------------
 // プレイヤーターン
 //------------------------
    if (isPlayerTurn)
    {
        //--------------------------
        // 1 攻撃
        //--------------------------
        bool key1 = CheckHitKey(KEY_INPUT_1);

        if (key1 && !oldKey1)
        {
            if (!enemies.empty())
            {
                player.attack(enemies[0]);

                AddLog("プレイヤーの攻撃！");

                if (enemies[0].isDead())
                {
                    AddLog(enemies[0].getName() + "を倒した！");
                    enemies.erase(enemies.begin());
                }

                isPlayerTurn = false;
            }
        }

        oldKey1 = key1;

        //--------------------------
        // 2 スキル
        //--------------------------
        bool key2 = CheckHitKey(KEY_INPUT_2);

        if (key2 && !oldKey2)
        {
            if (!enemies.empty())
            {
                if (player.skill(enemies[0]))
                {
                    AddLog("スキルをつかった！");

                    if (enemies[0].isDead())
                    {
                        AddLog(enemies[0].getName() + "を倒した！");
                        enemies.erase(enemies.begin());
                    }

                    isPlayerTurn = false;
                }
                else
                {
                    AddLog("MPが足りない！");
                }
            }
        }

        oldKey2 = key2;

        //--------------------------
        // 3 防御
        //--------------------------
        bool key3 = CheckHitKey(KEY_INPUT_3);

        if (key3 && !oldKey3)
        {
            player.defend();

            AddLog("ぼうぎょした！");

            isPlayerTurn = false;
        }

        oldKey3 = key3;

        //--------------------------
        // 4 復活
        //--------------------------
        bool key4 = CheckHitKey(KEY_INPUT_4);

        if (key4 && !oldKey4)
        {
            if (player.resurrect())
            {
                AddLog("ふっかつのじゅもんを となえた！");
                isPlayerTurn = false;
            }
            else
            {
                AddLog("ふっかつのじゅもんは もう使えない！");
            }
        }

        oldKey4 = key4;
    }

    //------------------------
    // 敵ターン
    //------------------------
    else
    {
        for (auto& enemy : enemies)
        {
            int damage = enemy.act();

            player.takeDamage(damage);

            AddLog(enemy.getName() + "の" +
                enemy.getLastActionName() + "！");

            AddLog(std::to_string(damage) + "ダメージ！");

        }

        if (player.isDead())
        {
            AddLog("プレイヤーは倒れた...");
            isGameOver = true;

            // ゲームオーバーになった瞬間の時間を記録
            gameOverStartTime = GetNowCount();
        }

        // 敵ターン終了 → 次のターンへ
        turnCount++;

        isPlayerTurn = true;
    }

    //------------------------
    // 全滅したら報酬画面へ
    //------------------------
    if (enemies.empty())
    {
        // 最後の階層ならゲームクリア
        if (currentStage == stages.size() - 1)
        {
            AddLog("ゲームクリア！");

            isGameClear = true;
            gameClearStartTime = GetNowCount();

            return;
        }

        // 最後の階層ではない場合は報酬画面
        gameState = GameState::Reward;
        isPlayerTurn = false;
        rewardWaitRelease = true;

        AddLog("報酬を選択してください");

        return;
    }
}

void PlayScene::Draw()
{
    //--------------------------------------------------
    // 報酬画面
    //--------------------------------------------------
    if (gameState == GameState::Reward)
    {
        DrawExtendGraph(
            0, 0,
            1280, 720,
            rewardImage,
            TRUE
        );

        return;
    }

    //--------------------------------------------------
    // 色
    //--------------------------------------------------
    int white = GetColor(255, 255, 255);
    int yellow = GetColor(255, 220, 80);
    int gold = GetColor(180, 140, 60);
    int darkPanel = GetColor(10, 15, 20);

    //--------------------------------------------------
    // ① 背景
    //--------------------------------------------------
    DrawExtendGraph(
        0, 0,
        1280, 720,
        haikei,
        TRUE
    );

    //--------------------------------------------------
    // ② 上部 Floor / Turn
    //--------------------------------------------------

    // 半透明パネル
    SetDrawBlendMode(DX_BLENDMODE_ALPHA, 190);

    DrawBox(
        1010, 20,
        1255, 100,
        darkPanel,
        TRUE
    );

    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

    // 枠
    DrawBox(
        1010, 20,
        1255, 100,
        gold,
        FALSE
    );

    // Floor
    DrawFormatString(
        1030, 35,
        white,
        "Floor : %d F",
        floorNumber
    );

    // Turn
    DrawFormatString(
        1030, 65,
        white,
        "Turn  : %d",
        turnCount
    );


    //--------------------------------------------------
    // ③ 敵
    //--------------------------------------------------

    for (int i = 0; i < enemies.size(); i++)
    {
        // 敵の位置
        int enemyX = 300 + i * 300;
        int enemyY = 50;

        enemies[i].Draw(enemyX, enemyY);

        //--------------------------------------------------
        // 敵情報パネル
        //--------------------------------------------------

        int panelX = enemyX + 80;
        int panelY = 285;

        SetDrawBlendMode(
            DX_BLENDMODE_ALPHA,
            200
        );

        DrawBox(
            panelX,
            panelY,
            panelX + 180,
            panelY + 75,
            darkPanel,
            TRUE
        );

        SetDrawBlendMode(
            DX_BLENDMODE_NOBLEND,
            0
        );

        // 枠
        DrawBox(
            panelX,
            panelY,
            panelX + 180,
            panelY + 75,
            gold,
            FALSE
        );

        // 敵名
        DrawFormatString(
            panelX + 20,
            panelY + 10,
            white,
            "%s",
            enemies[i].getName().c_str()
        );

        // HP
        DrawFormatString(
            panelX + 20,
            panelY + 40,
            white,
            "HP : %d",
            enemies[i].getHp()
        );
    }


    //--------------------------------------------------
// ④ 下部UIの背景
//--------------------------------------------------

    SetDrawBlendMode(
        DX_BLENDMODE_ALPHA,
        220
    );

    //--------------------------------
    // COMMAND
    //--------------------------------
    DrawBox(
        15, 390,
        420, 700,
        darkPanel,
        TRUE
    );

    //--------------------------------
    // PLAYER
    //--------------------------------
    DrawBox(
        420, 390,
        900, 700,
        darkPanel,
        TRUE
    );

    //--------------------------------
    // Battle Log
    //--------------------------------
    DrawBox(
        900, 390,
        1265, 700,
        darkPanel,
        TRUE
    );

    SetDrawBlendMode(
        DX_BLENDMODE_NOBLEND,
        0
    );


    //--------------------------------------------------
    // ⑤ パネル枠
    //--------------------------------------------------

    // COMMAND
    DrawBox(
        15, 390,
        420, 700,
        gold,
        FALSE
    );

    // PLAYER
    DrawBox(
        420, 390,
        900, 700,
        gold,
        FALSE
    );

    // Battle Log
    DrawBox(
        900, 390,
        1265, 700,
        gold,
        FALSE
    );


    //--------------------------------------------------
    // ⑥ COMMAND
    //--------------------------------------------------

    DrawFormatString(
        45, 410,
        yellow,
        "==== COMMAND ===="
    );


    // 1 たたかう
    DrawFormatString(
        55, 460,
        white,
        "1  たたかう"
    );

    // 2 スキル
    DrawFormatString(
        55, 515,
        white,
        "2  スキル"
    );

    // 3 防御
    DrawFormatString(
        55, 570,
        white,
        "3  ぼうぎょ"
    );

    // 4 復活
    DrawFormatString(
        55, 625,
        white,
        "4  ふっかつのじゅもん"
    );


    //--------------------------------------------------
    // ⑦ PLAYER
    //--------------------------------------------------

    DrawFormatString(
        465, 410,
        yellow,
        "==== PLAYER ===="
    );


    //--------------------------------------------------
    // HP
    //--------------------------------------------------

    DrawFormatString(
        465, 455,
        white,
        "HP"
    );

    DrawFormatString(
        750, 455,
        white,
        "%d / %d",
        player.getHp(),
        player.getMaxHp()
    );


    //--------------------------------------------------
    // HPゲージ
    //--------------------------------------------------

    int hpGaugeX = 500;
    int hpGaugeY = 480;
    int hpGaugeWidth = 240;
    int hpGaugeHeight = 18;

    // 背景
    DrawBox(
        hpGaugeX,
        hpGaugeY,
        hpGaugeX + hpGaugeWidth,
        hpGaugeY + hpGaugeHeight,
        GetColor(60, 60, 60),
        TRUE
    );

    // HP
    if (player.getMaxHp() > 0)
    {
        int hpWidth =
            hpGaugeWidth *
            player.getHp() /
            player.getMaxHp();

        DrawBox(
            hpGaugeX,
            hpGaugeY,
            hpGaugeX + hpWidth,
            hpGaugeY + hpGaugeHeight,
            GetColor(220, 60, 60),
            TRUE
        );
    }


    //--------------------------------------------------
    // MP
    //--------------------------------------------------

    DrawFormatString(
        465, 520,
        white,
        "MP"
    );

    DrawFormatString(
        750, 520,
        white,
        "%d / %d",
        player.getMp(),
        player.getMaxMp()
    );


    //--------------------------------------------------
    // MPゲージ
    //--------------------------------------------------

    int mpGaugeX = 500;
    int mpGaugeY = 545;
    int mpGaugeWidth = 240;
    int mpGaugeHeight = 18;

    // 背景
    DrawBox(
        mpGaugeX,
        mpGaugeY,
        mpGaugeX + mpGaugeWidth,
        mpGaugeY + mpGaugeHeight,
        GetColor(60, 60, 60),
        TRUE
    );

    // MP
    if (player.getMaxMp() > 0)
    {
        int mpWidth =
            mpGaugeWidth *
            player.getMp() /
            player.getMaxMp();

        DrawBox(
            mpGaugeX,
            mpGaugeY,
            mpGaugeX + mpWidth,
            mpGaugeY + mpGaugeHeight,
            GetColor(60, 120, 220),
            TRUE
        );
    }


    //--------------------------------------------------
    // 区切り線
    //--------------------------------------------------

    DrawLine(
        450, 580,
        870, 580,
        gold
    );


    //--------------------------------------------------
    // ATK
    //--------------------------------------------------

    DrawFormatString(
        465, 600,
        white,
        "ATK"
    );

    DrawFormatString(
        800, 600,
        white,
        "%d",
        player.getAttack()
    );


    //--------------------------------------------------
    // SKILL
    //--------------------------------------------------

    DrawFormatString(
        465, 640,
        white,
        "SKILL"
    );

    DrawFormatString(
        800, 640,
        white,
        "%d",
        player.getSkillPower()
    );


    //--------------------------------------------------
    // ⑧ Battle Log
    //--------------------------------------------------

    DrawFormatString(
        930, 410,
        yellow,
        "==== Battle Log ===="
    );

    // ログ
    for (int i = 0; i < battleLog.size(); i++)
    {
        DrawFormatString(
            930,
            450 + i * 32,
            white,
            "%s",
            battleLog[i].c_str()
        );
    }


    //--------------------------------------------------
    // ⑨ 一番下の操作説明
    //--------------------------------------------------

    SetDrawBlendMode(
        DX_BLENDMODE_ALPHA,
        220
    );

    DrawBox(
        15, 700,
        1265, 715,
        darkPanel,
        TRUE
    );

    SetDrawBlendMode(
        DX_BLENDMODE_NOBLEND,
        0
    );

    DrawBox(
        15, 700,
        1265, 715,
        gold,
        FALSE
    );

    DrawFormatString(
        35, 700,
        white,
        "1～4キーでコマンドを選択してください"
    );
    // GAME OVER
    if (isGameOver)
    {
        // GAME OVER画像を上部中央に表示
        DrawExtendGraph(
            140, 50,
            1140, 331,
            gameOverImage,
            TRUE
        );
    }

    // GAME CLEAR
    if (isGameClear)
    {
        DrawExtendGraph(
            140, 50,
            1140, 331,
            gameClearImage,
            TRUE
        );
    }

}
void PlayScene::AddLog(const std::string& text)
{
    battleLog.push_back(text);

    if (battleLog.size() > 6)
    {
        battleLog.erase(battleLog.begin());
    }
}

//------------------------
// 報酬適用
//------------------------
void PlayScene::ApplyReward(int choice)
{
    switch (choice)
    {
        //------------------------
        // ① 基礎ステータスアップ
        //------------------------
    case 1:
    {
        player.AddMaxHp(10);
        player.AddMp(2);

        AddLog("最大HPが 10 上がった！");
        AddLog("MPが 2 上がった！");

        break;
    }

    //------------------------
    // ② スキル威力アップ
    //------------------------
    case 2:
    {
        player.AddAttack(2);
        player.LearnNewSkill();

        AddLog("攻撃力が 2 上がった！");
        AddLog("スキルの威力が上がった！");

        break;
    }

    //------------------------
    // ③ HP・MP回復
    //------------------------
    case 3:
    {
        player.Heal(10);
        player.RecoverMp(7);

        AddLog("HPが 10 回復した！");
        AddLog("MPが 7 回復した！");

        break;
    }
    }

    //------------------------
    // 次のステージへ
    //------------------------
    currentStage++;

    if (currentStage < stages.size())
    {
        // 階層更新（敵撃破後に次階層へ）
        floorNumber = currentStage + 1;

        LoadStage(currentStage);

        AddLog(std::to_string(floorNumber) + "階に到達した！");
        AddLog("新しい敵が現れた！");

        // 11階、21階、31階、41階...で,ふっかつのじゅもんを再使用可能にする
        if (floorNumber >= 11 && floorNumber % 10 == 1)
        {
            player.ResetResurrection();

            AddLog("ふっかつのじゅもんが使用可能になった！");
        }

        gameState = GameState::Battle;
        isPlayerTurn = true;
    }
    else
    {
        AddLog("ゲームクリア！");

        isGameClear = true;
        gameClearStartTime = GetNowCount();
    }
}