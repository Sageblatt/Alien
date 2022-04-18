#include "Bullet.h"

Bullet::Bullet(int dir, float x_, float y_, double dmg): damage(dmg) {
    x = 0;
    y = 0;
    direction = dir;
    clock = std::make_unique<Clock>();
    clock->restart();

    texture.loadFromFile("../images/m_bullet.png");
    sprite.setTexture(texture);

    if (dir > 0)
        sprite.setPosition(x_ + 60,y_ + 30);
    else
        sprite.setPosition(x_ + 20, y_ + 50);
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
    x = sprite.getPosition().x;
    return x;
}

float Bullet::getPositionY() {
    y = sprite.getPosition().y;
    return y;
}

FloatRect Bullet::getRect() {
    return {sprite.getPosition().x, sprite.getPosition().y, 20, 20};
}

void Bullet::draw(RenderWindow &window) {
    window.draw(sprite);
}
void Bullet::setLife(bool life_) {
    life = life_;
}
bool Bullet::isLife() const {
    return life;
}

double Bullet::getDamage() const {
    return damage;
}
