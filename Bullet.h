#ifndef ALIEN_BULLET_H
#define ALIEN_BULLET_H

#include "Creature.h"
#include "Player.h"

class Bullet{
protected:
    Sprite sprite;
    Texture texture;

    std::unique_ptr<Clock> timer;
    float dt;

    int direction;

    bool life = true;

    float x;
    float y;

    float speed;

    const double damage;

public:
    Bullet(int dir, float x, float y, double dmg, float spd);

    void draw(RenderWindow& window);
    void setLife(bool life);

    void move();
    FloatRect getRect();
    bool isLife() const;
    double getDamage() const;

};

#endif //ALIEN_BULLET_H



