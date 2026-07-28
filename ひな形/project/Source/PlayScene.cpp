#include <ctime>
#include <vector>
#include <string>

#include "DxLib.h"

#include "../Library/SceneManager.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
    kImage = LoadGraph("image/Komando.jpg");
    rewardImage = LoadGraph("image/Reward.png");

    srand((unsigned int)time(nullptr));

    isGameOver = false;
    isPlayerTurn = true;

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
        {1},
        {2},
        {3},
        {1,2},
        {4},
        {5,6},
        {7},
        {8},
        {9,10}
    };

    LoadStage(currentStage);

    battleLog.clear();
    AddLog("敵が現れた！");
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
        }

        if (player.isDead())
        {
            AddLog("プレイヤーは倒れた...");
            isGameOver = true;
        }

        isPlayerTurn = true;
    }

    //------------------------
    // 全滅したら報酬画面へ
    //------------------------
    if (enemies.empty())
    {
        gameState = GameState::Reward;
        isPlayerTurn = false;

        // キーを離すまで待つ
        rewardWaitRelease = true;

        AddLog("報酬を選択してください");

        return;
    }
}

void PlayScene::Draw()
{
    //------------------------
    // 報酬画面
    //------------------------
    if (gameState == GameState::Reward)
    {
        // Reward.png を全画面表示
        DrawExtendGraph(0, 0, 1280, 720, rewardImage, TRUE);

        return;
    }

    int color = GetColor(255, 255, 255);

    DrawFormatString(1000, 600, color,
        "Player HP : %d / %d",
        player.getHp(),
        player.getMaxHp());

    DrawFormatString(1000, 630, color,
        "Player MP : %d / %d",
        player.getMp(),
        player.getMaxMp());

    DrawFormatString(1000, 660, color,
        "ATK : %d",
        player.getAttack());

    DrawFormatString(1000, 690, color,
        "SKILL : %d",
        player.getSkillPower());

    DrawGraph(0, 350, kImage, true);

    // 敵描画
    for (int i = 0; i < enemies.size(); i++)
    {
        enemies[i].Draw(300 + i * 300, 50);

        DrawFormatString(390 + i * 300, 288, color,
            "%s",
            enemies[i].getName().c_str());

        DrawFormatString(390 + i * 300, 308, color,
            "HP : %d",
            enemies[i].getHp());
    }

    // ログ
    DrawString(1000, 350,
        "==== Battle Log ====",
        GetColor(255, 255, 0));

    for (int i = 0; i < battleLog.size(); i++)
    {
        DrawString(1000,
            380 + i * 25,
            battleLog[i].c_str(),
            GetColor(255, 255, 255));
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
        player.AddAttack(2);
        player.AddMaxHp(10);
        player.AddMp(2);

        AddLog("攻撃力が 2 上がった！");
        AddLog("最大HPが 10 上がった！");
        AddLog("MPが 2 上がった！");

        break;
    }

    //------------------------
    // ② スキル威力アップ
    //------------------------
    case 2:
    {
        player.LearnNewSkill();

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
        LoadStage(currentStage);

        AddLog("新しい敵が現れた！");

        gameState = GameState::Battle;
        isPlayerTurn = true;
    }
    else
    {
        AddLog("ゲームクリア！");
        isGameOver = true;
    }
}