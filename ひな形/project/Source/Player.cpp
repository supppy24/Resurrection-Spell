#include "Player.h"

Player::Player()
// 初期値設定
    : hp(50),
    maxHp(50),
    mp(30),
    attackPower(5),
    skillPower(15),
    usedResurrection(false),
    isDefending(false)
{
}

// 現在HP取得
int Player::getHp() const
{
    return hp;
}

// 最大HP取得
int Player::getMaxHp() const
{
    return maxHp;
}

// 現在MP取得
int Player::getMp() const
{
    return mp;
}

// 死亡判定
bool Player::isDead() const
{
    return hp <= 0;
}

// ふっかつのじゅもん使用済み判定
bool Player::hasUsedResurrection() const
{
    return usedResurrection;
}

// 通常攻撃
void Player::attack(Enemy& enemy)
{
    enemy.takeDamage(attackPower);
}

// スキル攻撃
bool Player::skill(Enemy& enemy)
{
    // MP不足
    if (mp < 7)
    {
        return false;
    }

    // ダメージ
    enemy.takeDamage(skillPower);

    // MP消費
    mp -= 7;

    return true;
}

// 防御
void Player::defend()
{
    // 防御状態にする
    isDefending = true;
}

// ふっかつのじゅもん
bool Player::resurrect()
{
    // 既に使っているなら失敗
    if (usedResurrection)
    {
        return false;
    }

    // HP全回復
    hp = maxHp;

    // 使用済みにする
    usedResurrection = true;

    return true;
}

// ダメージを受ける
void Player::takeDamage(int damage)
{
    // 防御中ならダメージ半減
    if (isDefending)
    {
        damage /= 2;

        // 一度攻撃を受けたら防御解除
        isDefending = false;
    }

    hp -= damage;

    // HPが0未満にならないようにする
    if (hp < 0)
    {
        hp = 0;
    }
}