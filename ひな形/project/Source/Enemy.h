#pragma once
#include <string>
#include "EnemyBase.h"

class Enemy
{
public:

    Enemy(int type);

    ~Enemy();

    void Update();

    void Draw();

    int Act();

    void TakeDamage(int damage);

    int GetHP() const;

    std::string GetName() const;

    bool IsDead() const;

private:

    EnemyBase* enemy;
};