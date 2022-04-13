#ifndef ALIEN_MONSTER_H
#define ALIEN_MONSTER_H

#include "Creature.h"
using std::vector;

struct tiles 
{
	int X;
	int Y;
	int Width;
	int Height;
};

class Monster : public Creature {
protected:

	vector<tiles> moveVec;
	vector<tiles> attackVec;
	vector<tiles> fallVec;



	int X0;
	int Y0;

	bool key;

	float boost;
	float timeBoost1;
	float boostHeight;

	bool onGround;
	



public:
	void Move() override;
	void Attack() override;
	Monster(String file, float speedX, int windowWidth, int windowHeight);
	void IncrementTime();
	~Monster();
};



#endif //ALIEN_MONSTER_H