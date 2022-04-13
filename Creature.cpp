#include "Creature.h"
//Creature::Creature(){}
#include <iostream>
using std::cout;
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



