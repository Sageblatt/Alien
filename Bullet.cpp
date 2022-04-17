
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(int direction, float bullet_x, float bullet_y) {
    this->direction = direction;
    this->bullet_x = 0;
    this->file = file;
    this->x_player = bullet_x;
    this->y_player = bullet_y;
   

    clock = std::make_unique<Clock>();
    clock->restart();

    image.loadFromFile("../images/m_bullet.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    if(direction > 0)
        sprite.setPosition((float) (bullet_x + 60 ), (float) (bullet_y + 30  ));
    else sprite.setPosition((float) (bullet_x + 20), (float) (bullet_y + 50 ));
}

void Bullet::getBulletcoord() {

   if(direction >= 0) {
        sprite.move(4, 0);
    }
    else {
        sprite.setRotation(180);
        sprite.move(-4, 0);
    }

    if(sprite.getPosition().x > 1700){

        life = false;
    }
    if(sprite.getPosition().x < 0){
        life = false;
    }
    std::cout << sprite.getPosition().y << " ";
    std::cout << y_player <<'\n';

}

float Bullet::GetPositionX() {
    this->X = (float)sprite.getPosition().x;
    return this->X;
}

float Bullet::GetPositionY() {
    this->Y = (float)sprite.getPosition().y;
    return this->Y;
}

FloatRect Bullet::getRect(){
    return FloatRect (sprite.getPosition().x, sprite.getPosition().y, 20, 20);
}


void Bullet::Move(){}
void Bullet::Attack() {}
void Bullet::IncrementTime() {}


Bullet::~Bullet(){}



