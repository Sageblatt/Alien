#ifndef ALIEN_PLAYER_H
#define ALIEN_PLAYER_H

#include "Creature.h"

// What is direction_move?
// direction_move = ...
// 0 - Stop (to Right)
//
// 1 - Go to Right
// 2 - Stay and see to Right
// 3 - Jump and see to right
// 4 - Jump to Right
//
// 5 - Shout to Right
// 6 - Up and Shout to Right
// 7 - Go to back and Shout to Right
//
// -1 - Go to Left
// -2 - Stay and see to Left
// -3 - Jump and see to left
// -4 - Jump to Left
//
// -5 - Shout to Left
// -6 - Go to Back and Shout to Left
//  - Up and Shout to Left

enum Direction {
    STOP = 0,
    GO_RIGHT = 1,
    SEE_RIGHT = 2,
    JUMP_SEE_RIGHT = 3,
    JUMP_RIGHT = 4,
    FIRE_RIGHT = 5,
    JUMP_FIRE_RIGHT [[maybe_unused]] = 6,
    GO_LEFT_FIRE_RIGHT [[maybe_unused]] = 7,
    GO_LEFT = -1,
    SEE_LEFT = -2,
    JUMP_SEE_LEFT = -3,
    JUMP_LEFT = -4,
    FIRE_LEFT = -5,
    GO_RIGHT_FIRE_LEFT [[maybe_unused]] = -6,
    JUMP_FIRE_LEFT [[maybe_unused]] = -7
};

class Player : public Creature {
protected:
    const float JUMP_SPEED = 200;
	const float g_accel = 500;
    const float COOLDOWN = 1;

	bool onGround;
    Direction direction_move;
	
public:
    Player(float sp_x, float sp_y, int wind_w, int wind_h);

    bool keyboard();
    void move() override;

    float getPositionX();
    float getPositionY();
    Direction getDirectionMove() const;
};

#endif // ALIEN_PLAYER_H
