#ifndef ALIEN_PLAYER_H
#define ALIEN_PLAYER_H

#include "Creature.h"

class Player : public Creature {
protected:

	Clock clock; //������� ���������� ��� �������� ��������� �� �������.
	float CurrentFrame;//������ ������� ����
	float CurrentFrame2;
	float CurrentAttack;
	float CurrentAttack2;
	float time;
	int WindowWidth;
	int WindowHeight;
	bool key;
	float boost;
	float timeBoost;
	float boostHeight;

	void Move() override;
	void Attack() override;

	void KeyboardAttack();
	void Keyboard();
public:

	Player(String file,float speedX, float speedY, int windowWidth, int windowHeight);
	~Player();


	void Run();
};

#endif // ALIEN_PLAYER_H
