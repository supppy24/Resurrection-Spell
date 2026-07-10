#pragma once

class Doragon
{
public:
	Doragon();
	~Doragon();
	void Update();
	void Draw();

private:
	int HP;
	int Attack;
	int Skill;

	int slimage;
};