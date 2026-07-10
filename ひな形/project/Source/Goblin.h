#pragma once

class Goblin
{
public:
	Goblin();
	~Goblin();
	void Update();
	void Draw();

private:
	int HP;
	int Attack;
	int Skill;

	int slimage;
};