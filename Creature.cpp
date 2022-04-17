#include "Creature.h"
//Creature::Creature(){}
//#include <iostream>
//using std::cout;



void Creature::SetTime(float time)
{
    this->time = time;
}
float Creature::GetTime() {
    return this->time;
}

void Creature::Draw(RenderWindow& window)
{
    window.draw(sprite);
}

void Creature::Move()
{
}

void Creature::SavePosition()
{
    this->X = (int)sprite.getPosition().x;
    this->Y = (int)sprite.getPosition().y;
}

int Creature::GetPositionX()
{
    return this->X;
}
int Creature::GetPositionY()
{
    return this->Y;
}
FloatRect Creature::getRect(){
    this->X = (float)sprite.getPosition().x;
    this->Y = (float)sprite.getPosition().y;
    return FloatRect (X, Y, 100, 100);
}



