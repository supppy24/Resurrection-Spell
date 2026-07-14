#include <ctime>
#include <string>

#include "DxLib.h"

#include "../Library/SceneManager.h"

#include "PlayScene.h"

PlayScene::PlayScene()
{
    // コマンド画像を読み込む
    kImage = LoadGraph("image/Komando.jpg");

    srand(static_cast<unsigned int>(time(nullptr)));

    isGameOver = false;
    isPlayerTurn = true;

    oldKey1 = false;
    oldKey2 = false;
    oldKey3 = false;
    oldKey4 = false;

    // 最初の敵を生成
    enemyType = 1;
    enemy = Enemy(enemyType);

    newEnemyMessage = false;
    messageTimer = 0;

    // ログ初期化
    battleLog.clear();
    AddLog("スライムが あらわれた！");
}

PlayScene::~PlayScene()
{
}

void PlayScene::Update()
{
    //--------------------------------------------------
    // 新しい敵が出現するメッセージ表示中
    //--------------------------------------------------
    if (newEnemyMessage)
    {
        messageTimer--;

        if (messageTimer <= 0)
        {
            enemy = Enemy(enemyType);
            newEnemyMessage = false;
        }

        return;
    }

    //--------------------------------------------------
    // タイトルへ戻る
    //--------------------------------------------------
    if (CheckHitKey(KEY_INPUT_T))
    {
        SceneManager::ChangeScene("TITLE");
    }

    //--------------------------------------------------
    // ゲーム終了なら終了
    //--------------------------------------------------
    if (isGameOver)
    {
        return;
    }

    //--------------------------------------------------
    // プレイヤーターン
    //--------------------------------------------------
    if (isPlayerTurn)
    {
        //--------------------------
        // 1 攻撃
        //--------------------------
        bool key1 = CheckHitKey(KEY_INPUT_1);

        if (key1 && !oldKey1)
        {
            player.attack(enemy);

            AddLog("プレイヤーのこうげき！");

            if (enemy.isDead())
            {
                AddLog("敵をたおした！");
            }

            isPlayerTurn = false;
        }

        oldKey1 = key1;

        //--------------------------
        // 2 スキル
        //--------------------------
        bool key2 = CheckHitKey(KEY_INPUT_2);

        if (key2 && !oldKey2)
        {
            player.skill(enemy);

            AddLog("スキルをつかった！");

            if (enemy.isDead())
            {
                AddLog("敵をたおした！");
            }

            isPlayerTurn = false;
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

    //--------------------------------------------------
    // 敵ターン
    //--------------------------------------------------
    else
    {
        int damage = enemy.act();

        player.takeDamage(damage);

        AddLog("敵のこうげき！");

        if (player.isDead())
        {
            AddLog("プレイヤーは たおれた...");
            isGameOver = true;
        }

        isPlayerTurn = true;
    }

    //--------------------------------------------------
    // 敵を倒したら次の敵へ
    //--------------------------------------------------
    if (enemy.isDead())
    {
        enemyType++;

        if (enemyType <= 3)
        {
            newEnemyMessage = true;
            messageTimer = 120;

            AddLog("新しい敵が あらわれた！");
        }
        else
        {
            AddLog("すべての敵をたおした！");
            isGameOver = true;
        }
    }
}

void PlayScene::Draw()
{
    int color = GetColor(255, 255, 255);

    //--------------------------------------------------
    // ステータス表示
    //--------------------------------------------------
    DrawString(
        0,
        0,
        "======================",
        color);

    DrawFormatString(
        0,
        30,
        color,
        "Player HP : %d",
        player.getHp());

    DrawFormatString(
        0,
        60,
        color,
        "Player MP : %d",
        player.getMp());

    DrawFormatString(
        0,
        90,
        color,
        "Enemy HP : %d",
        enemy.getHp());

    DrawString(
        0,
        120,
        "======================",
        color);

    //--------------------------------------------------
    // タイトルへ戻る
    //--------------------------------------------------
    DrawString(
        0,
        200,
        "[T]キーでタイトルへ",
        color);

    //--------------------------------------------------
    // コマンド画像
    //--------------------------------------------------
    DrawGraph(
        0,
        350,
        kImage,
        true);

    //--------------------------------------------------
    // メッセージ
    //--------------------------------------------------
    if (newEnemyMessage)
    {
        DrawString(
            0,
            160,
            "新しい敵が現れた！",
            GetColor(255, 255, 0));
    }

    if (player.isDead())
    {
        DrawString(
            0,
            160,
            "プレイヤーは倒れた...",
            GetColor(255, 0, 0));
    }

    if (enemy.isDead() && enemyType > 3)
    {
        DrawString(
            0,
            160,
            "ゲームクリア！",
            GetColor(0, 255, 0));
    }

    // バトルログ
    DrawString(
        1000,
        480,
        "====== バトルログ ======",
        GetColor(255, 255, 0));

    for (int i = 0; i < battleLog.size(); i++)
    {
        DrawString(
            1000,
            500 + i * 25,
            battleLog[i].c_str(),
            GetColor(255, 255, 255));
    }
}

// ログ追加
void PlayScene::AddLog(const std::string& text)
{
    battleLog.push_back(text);

    // 最新6件だけ残す
    if (battleLog.size() > 6)
    {
        battleLog.erase(battleLog.begin());
    }
}