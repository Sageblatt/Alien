#ifndef ALIEN_PLAYER_H
#define ALIEN_PLAYER_H

#include "Creature.h"
using std::vector;
class Player : public Creature {
protected:
	bool key;

	float boost;
	float boostHeight;

	bool onGround;
	
public:
	void Keyboard();
	void Move() override;
	void Attack() override;
	void IncrementTime() override;
    int GetDirectionMove();
	Player(String file, float speedX, float speedY, int windowWidth, int windowHeight);
};


class Table
{
protected:
    String  fileTab;
    Image   imageTab;
    Texture textureTab;

public:
    void Draw(RenderWindow& window);
    Sprite  spriteTab;
    Table(String fileTab);
};


struct TilesHeart
{
    int x0;
    int lenX;
    int y0;
    int lenY;
};

class Health
{
protected:

    String  fileHeart;
    Image   imageHeart;
    Texture textureHeart;
    Sprite  spriteHeart;

    vector<TilesHeart> heartVec;

    int count;
public:

    Health(std::string fileHeart, int count);

    void Hurt(int hp, int maxHp);

    void Draw(RenderWindow& window);
};

#endif // ALIEN_PLAYER_H
