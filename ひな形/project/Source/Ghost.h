#pragma once

class Ghost
{
public:
	Ghost();
	~Ghost();
	void Update();
	void Draw();

private:
	int HP;
	int Attack;
	int Skill;

	int slimage;
};
