#pragma once

class Medusa
{
public:
	Medusa();
	~Medusa();
	void Update();
	void Draw();

private:
	int HP;
	int Attack;
	int Skill;

	int slimage;
};