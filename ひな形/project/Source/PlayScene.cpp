#include <ctime>

#include "DxLib.h"

#include "../Library/SceneManager.h"

#include "PlayScene.h"

PlayScene::PlayScene()
{
    srand(static_cast<unsigned int>(time(nullptr)));

    isGameOver = false;
    isPlayerTurn = true;

    oldKey1 = false;
    oldKey2 = false;
    oldKey3 = false;
    oldKey4 = false;
}

PlayScene::~PlayScene()
{
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

    if (isPlayerTurn)
    {
        bool key1 = CheckHitKey(KEY_INPUT_1);

        if (key1 && !oldKey1)
        {
            player.attack(enemy);

            isPlayerTurn = false;
        }

        oldKey1 = key1;

        bool key2 = CheckHitKey(KEY_INPUT_2);

        if (key2 && !oldKey2)
        {
            player.skill(enemy);

            isPlayerTurn = false;
        }

        oldKey2 = key2;

        bool key3 = CheckHitKey(KEY_INPUT_3);

        if (key3 && !oldKey3)
        {
            player.heal();

            isPlayerTurn = false;
        }

        oldKey3 = key3;

        bool key4 = CheckHitKey(KEY_INPUT_4);

        if (key4 && !oldKey4)
        {
            player.resurrect();

            isPlayerTurn = false;
        }

        oldKey4 = key4;

        if (enemy.isDead())
        {
            isGameOver = true;
        }
    }
    else
    {
        int damage = enemy.act();

        player.takeDamage(damage);

        if (player.isDead())
        {
            isGameOver = true;
        }

        isPlayerTurn = true;
    }
}

void PlayScene::Draw()
{
    int color = GetColor(255, 255, 255);

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
        "Enemy  HP : %d",
        enemy.getHp());

    DrawString(
        0,
        120,
        "======================",
        color);

    DrawString(
        0,
        160,
        "コマンドをえらべ！！",
        color);

    DrawString(
        0,
        200,
        "1:こうげき",
        color);

    DrawString(
        0,
        230,
        "2:スキル",
        color);

    DrawString(
        0,
        260,
        "3:かいふく",
        color);

    DrawString(
        0,
        290,
        "4:ふっかつのじゅもん",
        color);

    DrawString(
        0,
        360,
        "[T]キーでタイトルへ",
        color);

    if (enemy.isDead())
    {
        DrawString(
            0,
            420,
            "敵を倒した！ 勝利！！",
            GetColor(255, 255, 0));
    }

    if (player.isDead())
    {
        DrawString(
            0,
            420,
            "プレイヤーは倒れた...",
            GetColor(255, 0, 0));
    }
}