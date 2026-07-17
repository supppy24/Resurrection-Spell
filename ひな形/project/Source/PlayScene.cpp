#include <ctime>
#include <vector>
#include <string>

#include "DxLib.h"

#include "../Library/SceneManager.h"
#include "PlayScene.h"

PlayScene::PlayScene()
{
    kImage = LoadGraph("image/Komando.jpg");

    srand((unsigned int)time(nullptr));

    isGameOver = false;
    isPlayerTurn = true;

    oldKey1 = false;
    oldKey2 = false;
    oldKey3 = false;
    oldKey4 = false;

    // ステージ番号
    currentStage = 0;

    // ステージ設定
    stages =
    {
        {1},        // スライム
        {2},        // ゴブリン
        {3},        // ドラゴン
        {1,2},      // スライム＋ゴブリン
        {4},        // ミミック
        {5,6},      // ゴースト＋ゴーレム
        {7},        // 魔女
        {8},        // 魔王
        {9,10}      // メデューサ＋スカル
    };

    // 最初のステージ
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
                player.skill(enemies[0]);

                AddLog("スキルをつかった！");

                if (enemies[0].isDead())
                {
                    AddLog(enemies[0].getName() + "を倒した！");
                    enemies.erase(enemies.begin());
                }

                isPlayerTurn = false;
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
            player.resurrect();

            AddLog("ふっかつのじゅもんを となえた！");

            isPlayerTurn = false;
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

            AddLog(enemy.getName() + "の攻撃！");
        }

        if (player.isDead())
        {
            AddLog("プレイヤーは倒れた...");
            isGameOver = true;
        }

        isPlayerTurn = true;
    }

    //------------------------
    // 全滅したら次のステージ
    //------------------------
    if (enemies.empty())
    {
        currentStage++;

        if (currentStage < stages.size())
        {
            LoadStage(currentStage);

            AddLog("新しい敵が現れた！");
        }
        else
        {
            AddLog("ゲームクリア！");
            isGameOver = true;
        }
    }
}

void PlayScene::Draw()
{
    int color = GetColor(255, 255, 255);

    DrawFormatString(0, 0, color,
        "Player HP : %d",
        player.getHp());

    DrawFormatString(0, 30, color,
        "Player MP : %d",
        player.getMp());


    // コマンド画像
    DrawGraph(
        0,
        350,
        kImage,
        true);


    //--------------------------------------------------
    // 敵表示
    //--------------------------------------------------
    int enemyCount = enemies.size();

    for (int i = 0; i < enemyCount; i++)
    {
        int x = 640;
        int y = 250;

        switch (enemyCount)
        {
        case 1:
            // 1体なら中央
            x = 640;
            break;

        case 2:
            // 左右
            x = (i == 0) ? 450 : 830;
            break;

        case 3:
            // 3体
            if (i == 0) x = 300;
            if (i == 1) x = 640;
            if (i == 2) x = 980;
            break;

        default:
            x = 220 + i * 220;
            break;
        }


        // 敵画像
        enemies[i].Draw(x, y);


        // 名前
        DrawFormatString(
            x - 50,
            y + 120,
            color,
            "%s",
            enemies[i].getName().c_str());


        // HP
        DrawFormatString(
            x - 50,
            y + 145,
            color,
            "HP : %d",
            enemies[i].getHp());
    }


    //--------------------------------------------------
    // バトルログ
    //--------------------------------------------------
    DrawString(
        1000,
        450,
        "==== Battle Log ====",
        GetColor(255, 255, 0));


    for (int i = 0; i < battleLog.size(); i++)
    {
        DrawString(
            1000,
            480 + i * 25,
            battleLog[i].c_str(),
            GetColor(255, 255, 255));
    }
}
// ログ追加
void PlayScene::AddLog(const std::string& text)
{
    battleLog.push_back(text);

    if (battleLog.size() > 6)
    {
        battleLog.erase(battleLog.begin());
    }
}