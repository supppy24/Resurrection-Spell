#include "Gargoyle.h"
#include "DxLib.h"
#include <cstdlib>

Gargoyle::Gargoyle()
{
    HP = 180;
    Attack = 12;
    Skill = 15;

    gaimage = LoadGraph("image/GARGOYLE.png");

    lastActionName = "";
}

Gargoyle::~Gargoyle()
{
}

//void Gargoyle::Update()
//{
//
//}

void Gargoyle::Draw(int x, int y)
{
    DrawExtendGraph(x, y, x + 256, y + 256, gaimage, true);
}

// s“®
int Gargoyle::Act()
{
    // 0‚È‚ç’ÊíUŒ‚A1‚È‚çƒXƒLƒ‹
    int action = rand() % 2;

    if (action == 0)
    {
        // ’ÊíUŒ‚–¼‚ğ•Û‘¶
        lastActionName = "Î’Ü";

        return Attack;
    }
    else
    {
        // ƒXƒLƒ‹–¼‚ğ•Û‘¶
        lastActionName = "‹}~‰º“ËŒ‚";

        return Skill;
    }
}

// ÅŒã‚Ég‚Á‚½‹Z–¼
std::string Gargoyle::GetLastActionName() const
{
    return lastActionName;
}

int Gargoyle::GetHP() const
{
    return HP;
}

void Gargoyle::TakeDamage(int damage)
{
    HP -= damage;

    if (HP < 0)
    {
        HP = 0;
    }
}

bool Gargoyle::IsDead() const
{
    return HP <= 0;
}