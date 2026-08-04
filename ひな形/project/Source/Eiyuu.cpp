#include "Eiyuu.h"
#include "DxLib.h"
#include <cstdlib>

Eiyuu::Eiyuu()
{
    HP = 250;
    Attack = 5;
    Skill = 10;

    eiimage = LoadGraph("image/EIYUU.png");

    lastActionName = "";
}

Eiyuu::~Eiyuu()
{
}

//void Eiyuu::Update()
//{
//
//}

void Eiyuu::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, eiimage, true);
}

// s“®
int Eiyuu::Act()
{
    // 0‚È‚ç’ÊíUŒ‚A1‚È‚çƒXƒLƒ‹
    int action = rand() % 2;

    if (action == 0)
    {
        // ’ÊíUŒ‚–¼‚ğ•Û‘¶
        lastActionName = "‰p—Y‚ÌŒ•";

        return Attack;
    }
    else
    {
        // ƒXƒLƒ‹–¼‚ğ•Û‘¶
        lastActionName = "‹U‚è‚ÌŒ•‹Z";

        return Skill;
    }
}

// ÅŒã‚Ég‚Á‚½‹Z–¼
std::string Eiyuu::GetLastActionName() const
{
    return lastActionName;
}

int Eiyuu::GetHP() const
{
    return HP;
}

void Eiyuu::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Eiyuu::IsDead() const
{
    return HP <= 0;
}