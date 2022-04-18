#ifndef ALIEN_BULLET_H
#define ALIEN_BULLET_H

#include "Creature.h"
#include "Player.h"

class Bullet{
protected:
    Sprite sprite;
    Texture texture;

    std::unique_ptr<Clock> clock;

    int direction;
    bool life = true;
    float x;
    float y;

    const double damage;

public:
    Bullet(int dir, float x, float y, double dmg);

    void draw(RenderWindow& window);
    void setLife(bool life);

    void getBulletCoord();
    FloatRect getRect();
    bool isLife() const;
    const double getDamage() const;
    float getPositionX();
    float getPositionY();
};

#endif //ALIEN_BULLET_H



