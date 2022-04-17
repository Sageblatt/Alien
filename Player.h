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
    float GetPositionX();
    float GetPositionY();
	void Keyboard();
	void Move() override;
	void Attack() override;
	void IncrementTime() override;
	Player(String file, float speedX, float speedY, int windowWidth, int windowHeight);
};

#endif // ALIEN_PLAYER_H
