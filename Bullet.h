#ifndef ALIEN_BULLET_H
#define ALIEN_BULLET_H

#include "Creature.h"
#include "Player.h"

class Bullet: public Creature{
protected:
    std::unique_ptr<Clock> clock;
    int direction;
    float bullet_x;
    float bullet_y;
    float x_player;
    float y_player;
    float x_monster;
    float y_monster;
    float X;
    float Y;
    float dx = 0;

public:
    bool life = true;
    Sprite  sprite{};
    Bullet(int direction, float bullet_x, float bullet_y);
    void getBulletcoord();
    FloatRect getRect();
    float GetPositionX();
    float GetPositionY();
    void Move() override;
    void Attack();
    void IncrementTime();
    ~Bullet();
};

#endif //ALIEN_BULLET_H



