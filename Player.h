#ifndef ALIEN_PLAYER_H
#define ALIEN_PLAYER_H

#include "Creature.h"

class Player : public Creature {
protected:
	bool key;
	float boost;
	bool onGround;
	
public:
    Player(const String& fname, float sp_x, float sp_y, int wind_w, int wind_h);

    void keyboard();
    void move() override;
    void incrementTime() override;

    float getPositionX();
    float getPositionY();
    int getDirectionMove();

};

#endif // ALIEN_PLAYER_H
