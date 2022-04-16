#include "Monster.h"

Monster::Monster(String file, float speedX, int x0, int windowWidth, int windowHeight)
{
    this->file = file;
    this->directionMove = 0;

     
    this->moveVec.push_back({ 0, 524, 65, 60 });
    this->moveVec.push_back({ 78, 528, 65, 60 });

    this->attackVec.push_back({ 0, 0, 65, 59 });
    this->attackVec.push_back({ 0, 315, 62, 60 });
    this->attackVec.push_back({ 0, 455, 69, 60 });
    this->attackVec.push_back({ 82, 455, 90, 60 });
    this->attackVec.push_back({ 0, 455, 69, 60 });
    this->attackVec.push_back({ 0, 315, 62, 60 });
    this->attackVec.push_back({ 0, 0, 65, 59 });

    this->fallVec.push_back({ 0, 139, 65, 65 });
    
   
    this->WindowWidth = windowWidth;
    this->WindowHeight = windowHeight;

//    this->X0 = rand() % (1000 - fallVec[0].Width);
    this->X0 = x0;
    this->Y0 = 0;

    this->SpeedX = speedX;

    this->onGround = false;

    image.loadFromFile(file);         
    texture.loadFromImage(image);                     
    sprite.setTexture(texture);

    sprite.setPosition((float)X0, (float)Y0);

    this->CurrentFrame = 0;
    this->CurrentFrame2 = 0;

    this->boost = 10;
    this->timeBoost1 = 0;
    this->boostHeight = 0;
    this->key = false;
}

void Monster::IncrementTime() {
    this->timeBoost1 += this->time / 1000;
}

void Monster::Move()
{
   // std::cout << sprite.getPosition().y << '\n';
    CurrentFrame += (float)(0.01 * time);
    if (CurrentFrame > 10) CurrentFrame = 0;
    
    if (onGround == false) {
        onGround = false;
        IncrementTime();
       // std::cout << boost * timeBoost * timeBoost / 2 << '\n';
        sprite.setTextureRect(IntRect(fallVec[0].X, fallVec[0].Y, fallVec[0].Width, fallVec[0].Height));
        sprite.move(0, boost * timeBoost1 * timeBoost1 / 2);
    }
    if (sprite.getPosition().y >= (WindowHeight - fallVec[0].Height))
    {
        
        onGround = true;
        sprite.setTextureRect(IntRect(fallVec[0].X, fallVec[0].Y, fallVec[0].Width, fallVec[0].Height));
        sprite.move(0, 0);
    }
    if (onGround == true) return;
}

void Monster::Attack() 
{
    CurrentFrame += (float)(0.0000001 * time);
    if (CurrentFrame > 6) CurrentFrame = 0;
    if (onGround == true)
    {
        int  i = (int)CurrentFrame;
        sprite.setTextureRect(IntRect(attackVec[i].X, attackVec[i].Y, attackVec[i].Width, attackVec[i].Height));
        sprite.move(0, 0);
    }
}
