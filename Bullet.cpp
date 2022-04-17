
#include <iostream>
#include "Bullet.h"

Bullet::Bullet(int direction, float bullet_x, float bullet_y) {
    this->direction = direction;
    this->bullet_x = 0;
    this->file = file;
    this->x_player = bullet_x;
    this->y_player = bullet_y;
    this->x_player = bullet_x;
    this->y_player = bullet_y;

    image.loadFromFile("../images/m_bullet.png");
    texture.loadFromImage(image);
    sprite.setTexture(texture);
    if(direction > 0)
        sprite.setPosition((float) (bullet_x + 60 ), (float) (bullet_y + 31  ));
    else sprite.setPosition((float) (bullet_x + 15), (float) (bullet_y + 55 ));
}
void Bullet::getBulletcoord() {

    float time = clock.getElapsedTime().asMicroseconds() ;
    time = time / 800;


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
    std::cout << sprite.getPosition().x << " ";
    std::cout << x_player;
   // std::cout << time << " ";

    clock.restart();
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
    return FloatRect (this->X, this->Y, 20, 20);
}
void Bullet::Move(){}
void Bullet::Attack() {}
void Bullet::IncrementTime() {}


Bullet::~Bullet(){}



