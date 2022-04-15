#include "Creature.h"

void Creature::SetTime(float t) {
	this->time = t;
}

float Creature::GetTime() {
    return this->time;
}

void Creature::Draw(RenderWindow& window) {
	window.draw(sprite);
}



