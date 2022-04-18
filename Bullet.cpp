#include "Bullet.h"

Bullet::Bullet(int dir, float x, float y) {
    direction = dir;
    bullet_x = 0;
    file = file;
    x_player = x;
    y_player = y;

    clock = std::make_unique<Clock>();
    clock->restart();

    image.loadFromFile("../images/m_bullet.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    if (dir > 0)
        sprite.setPosition(x + 60,y + 30);
    else
        sprite.setPosition(x + 20, y + 50);
}

void Bullet::getBulletCoord() {
   if (direction >= 0) {
        sprite.move(4, 0);
   } else {
       sprite.setRotation(180);
       sprite.move(-4, 0);
   }

   auto actual_x = sprite.getPosition().x;

   if (actual_x > 1700 or actual_x < 0)
       life = false;
}

float Bullet::getPositionX() {
    X = sprite.getPosition().x;
    return X;
}

float Bullet::getPositionY() {
    Y = sprite.getPosition().y;
    return Y;
}

FloatRect Bullet::getRect() {
    return {sprite.getPosition().x, sprite.getPosition().y, 20, 20};
}

void Bullet::move(){}

void Bullet::incrementTime() {}
