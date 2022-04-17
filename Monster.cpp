//#include "windows.h"
#include "Monster.h"
//#include <iostream>
//using std::cout;

//Monster::Monster() {}

Monster::Monster(String file, float speedX, int x0, int windowWidth, int windowHeight, double hp)
{
    this->file = file;
    this->directionMove = 0;
    this->attackTact = 0;
    //this->attackTact2 = 0;

    this->hp = hp;

    this->moveVec.push_back({ 0, 524, 65, 60 });
    this->moveVec.push_back({ 78, 528, 65, 60 });

    this->attackVec.push_back({ 0, 0, 83, 59 });
    this->attackVec.push_back({ 0, 315, 83, 60 });
    this->attackVec.push_back({ 0, 455, 83, 60 });
    this->attackVec.push_back({ 82, 455, 83, 60 });
    this->attackVec.push_back({ 0, 455, 83, 60 });
    this->attackVec.push_back({ 0, 315, 83, 60 });
    this->attackVec.push_back({ 0, 0, 83, 59 });

    this->fallVec.push_back({ 0, 139, 65, 65 });


    this->WindowWidth = windowWidth;
    this->WindowHeight = windowHeight;

    this->X = x0;

    this->Y = 0;

    this->SpeedX = speedX;

    this->onGround = false;

    image.loadFromFile(file);
    texture.loadFromImage(image);
    sprite.setTexture(texture);

    sprite.setPosition((float)X,(float)Y);

    //std::cout << sprite.getPosition().y << '\n';
    this->CurrentFrame = 0;
    this->CurrentFrame2 = 0;

    this->boost = 10;
    this->timeBoost1 = 0;
    this->boostHeight = 0;
    this->key = false;
}
void Monster::IncrementTime()
{
    // std::cout << "TIME: " << time << '\n';
    this->timeBoost1 += this->time / 1000;
    // std::cout << "TIMEBOOST1: " << timeBoost1 << '\n';
}

void Monster::Move()
{

    // std::cout << sprite.getPosition().y << '\n';


    if (onGround == false) {
        //std::cout << "BOOST!!! " << boost * timeBoost1 * timeBoost1 / 2 << '\n';
        CurrentFrame += (float)(0.01 * time);
        if (CurrentFrame > 10) CurrentFrame = 0;
        onGround = false;
        IncrementTime();
        // std::cout << boost * timeBoost * timeBoost / 2 << '\n';
        sprite.setTextureRect(IntRect(fallVec[0].x, fallVec[0].y, fallVec[0].Width, fallVec[0].Height));
        sprite.move(0, boost * timeBoost1 * timeBoost1 / 2);
    }
    //std::cout << sprite.getPosition().y << "---" << WindowHeight - fallVec[0].Height << '\n';
    if (sprite.getPosition().y >= (WindowHeight - fallVec[0].Height))
    {

        onGround = true;

    }
    if (onGround == true) return;
}

void Monster::Attack()
{
    if ((int)CurrentFrame >= 5)
    {
        //std::cout << "Tact: " << attackTact << '\n';
        CurrentFrame = 0;
        attackTact = 0;
    }

    if (onGround == true && abs(distanceToHero) <= 300)
    {
        //std::cout << "not OK    " << distanceToHero << '\n';

        if (distanceToHero >= 0)
        {
            while (attackTact < 250)
            {
                sprite.setTextureRect(IntRect(attackVec[0].x, attackVec[0].y, attackVec[0].Width, attackVec[0].Height));
                attackTact++;
                sprite.move(0, 0);
                return;
            }

            sprite.setTextureRect(IntRect(attackVec[(int)CurrentFrame].x, attackVec[(int)CurrentFrame].y, attackVec[(int)CurrentFrame].Width, attackVec[(int)CurrentFrame].Height));
            sprite.move(0, 0);
            CurrentFrame += (float)(time) / 100;
        }

        else
        {
            while (attackTact < 250)
            {
                sprite.setTextureRect(IntRect(478 - attackVec[0].x - attackVec[0].Width, attackVec[0].y, attackVec[0].Width, attackVec[0].Height));                attackTact++;
                sprite.move(0, 0);
                return;
            }

            sprite.setTextureRect(IntRect(478 - attackVec[(int)CurrentFrame].x - attackVec[(int)CurrentFrame].Width, attackVec[(int)CurrentFrame].y, attackVec[(int)CurrentFrame].Width, attackVec[(int)CurrentFrame].Height));
            sprite.move(0, 0);
            CurrentFrame += (float)(time) / 100;
        }
    }
    if (onGround == true && distanceToHero > 300)
    {
        CurrentFrame += (float)(time) / 110;
        //std::cout << "OK    " << distanceToHero << '\n';
        int j = (int)(CurrentFrame / 3);
        //std::cout << "j   " << j << '\n';
        sprite.setTextureRect(IntRect(moveVec[j].x, moveVec[j].y, moveVec[j].Width, moveVec[j].Height));
        sprite.move(SpeedX/50 * time, 0);
    }

    if (onGround == true && distanceToHero < -300)
    {
        CurrentFrame += (float)(time) / 110;
        //std::cout << "OK    " << distanceToHero << '\n';
        int j = (int)(CurrentFrame / 3);
        //std::cout << "j   " << j << '\n';
        sprite.setTextureRect(IntRect(478 - moveVec[j].x - moveVec[j].Width, moveVec[j].y, moveVec[j].Width, moveVec[j].Height));
        sprite.move(-SpeedX/50 * time, 0);
    }

}

void Monster::DistanceToHero(int X)
{
    this->distanceToHero = X - this->X;
}

Monster::~Monster() { };


