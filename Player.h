#ifndef ALIEN_PLAYER_H
#define ALIEN_PLAYER_H

#include "Creature.h"

class Player : public Creature {
protected:
	
	bool key;

	float boost;
	float boostHeight;

	bool onGround;
	
public:

	void Keyboard();
	void Move() override;
	void IncrementTime();
	Player(String file,float speedX, float speedY, int windowWidth, int windowHeight);
	~Player();


	//void Run(Monster& alien);
};

#endif // ALIEN_PLAYER_H
