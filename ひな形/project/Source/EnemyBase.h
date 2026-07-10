#pragma once

#include <string>

class EnemyBase
{
public:

    virtual ~EnemyBase() {}

    virtual void Update() = 0;
    virtual void Draw() = 0;

    // 敵の行動
    virtual int Act() = 0;

    // ダメージ
    virtual void TakeDamage(int damage) = 0;

    // HP取得
    virtual int GetHP() const = 0;

    // 名前
    virtual std::string GetName() const = 0;

    // 死亡判定
    virtual bool IsDead() const = 0;
};