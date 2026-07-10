#include "Enemy.h"

#include "Slime.h"
#include "Goblin.h"
#include "Doragon.h"
#include "Mimick.h"
#include "Ghost.h"
#include "Gorem.h"
#include "Majyo.h"
#include "Maou.h"
#include "Medusa.h"
#include "Skall.h"

Enemy::Enemy(int type)
{
    switch (type)
    {
    case 1:

        enemy = new Slime();

        break;

    case 2:

        enemy = new Goblin();

        break;

    case 3:

        enemy = new Doragon();

        break;

    case 4:

        enemy = new Mimick();

        break;

    case 5:

        enemy = new Ghost();

        break;

    case 6:

        enemy = new Gorem();

        break;

    case 7:

        enemy = new Majyo();

        break;

    case 8:

        enemy = new Maou();

        break;

    case 9:

        enemy = new Medusa();

        break;

    case 10:

        enemy = new Skall();

        break;

    default:

        enemy = new Slime();

        break;
    }
}

Enemy::~Enemy()
{
    delete enemy;
}

void Enemy::Update()
{
    enemy->Update();
}

void Enemy::Draw()
{
    enemy->Draw();
}

int Enemy::Act()
{
    return enemy->Act();
}

void Enemy::TakeDamage(int damage)
{
    enemy->TakeDamage(damage);
}

int Enemy::GetHP() const
{
    return enemy->GetHP();
}

std::string Enemy::GetName() const
{
    return enemy->GetName();
}

bool Enemy::IsDead() const
{
    return enemy->IsDead();
}