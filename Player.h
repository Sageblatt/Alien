#ifndef ALIEN_PLAYER_H
#define ALIEN_PLAYER_H

#include "Creature.h"

class Player : public Creature {
protected:

	Clock clock; //создаем переменную для привязки персонажа ко времени.
	float CurrentFrame;//хранит текущий кадр
	float CurrentFrame2;

	float time;

	int WindowWidth;
	int WindowHeight;

	bool key;

	float boost;
	float timeBoost;
	float boostHeight;

	bool onGround;
	void Move() override;

	void Keyboard();
public:

	Player(String file,float speedX, float speedY, int windowWidth, int windowHeight);
	~Player();


	void Run();
};

#endif // ALIEN_PLAYER_H
