#include "Creature.h"

void Creature::setTime(float t) {
    time = t;
}

float Creature::getTime() const {
    return time;
}

void Creature::draw(RenderWindow& window) const {
    window.draw(sprite);
}

void Creature::savePosition() {
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
}

float Creature::getPositionX() const {
    return x;
}

float Creature::getPositionY() const {
    return y;
}

FloatRect Creature::getRect() {
    x = sprite.getPosition().x;
    y = sprite.getPosition().y;
    return {x, y, 100, 100};
}
