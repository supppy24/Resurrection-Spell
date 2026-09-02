#ifndef PLAYER_H
#define PLAYER_H

#include "Enemy.h"

class Player
{
private:
    // 現在HP
    int hp;

    // 最大HP
    int maxHp;

    // 現在MP
    int mp;

    // 最大MP
    int maxMp;

    // 通常攻撃力
    int attackPower;

    // スキル攻撃力
    int skillPower;

    // ふっかつのじゅもん使用済みフラグ
    bool usedResurrection;

    // 防御中かどうか
    bool isDefending;

public:
    Player();

    // 各種ゲッター
    int getHp() const;
    int getMaxHp() const;
    int getMp() const;

    // 戦闘状態確認
    bool isDead() const;
    bool hasUsedResurrection() const;

    // 通常攻撃
    void attack(Enemy& enemy);

    // スキル攻撃
    bool skill(Enemy& enemy);

    // 防御
    void defend();

    // ふっかつのじゅもん
    bool resurrect();

    // 攻撃力アップ
    void AddAttack(int value);

    // 最大HPアップ
    void AddMaxHp(int value);

    // HP全回復
    void FullHeal();

    // HPを指定量回復
    void Heal(int value);

    // 最大MPアップ
    void AddMp(int value);

    // 最大MP取得
    int getMaxMp() const;

    // MP回復
    void RecoverMp(int value);

    // 新しいスキルを覚える
    void LearnNewSkill();

    // ダメージを受ける
    void takeDamage(int damage);

    // 攻撃力取得
    int getAttack() const;

    // スキル威力取得
    int getSkillPower() const;

    // ふっかつのじゅもんを再使用可能にする
    void ResetResurrection();
};

#endif