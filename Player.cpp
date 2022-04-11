#include "Player.h"
#include <iostream>

Player::Player(String file, float speedX, float speedY, int windowWidth, int windowHeight)
{
    this->file = file;
    //Êîíñòðóêòîð ñ ïàðàìåòðàìè äëÿ êëàññà Player. 
    //Ïðè ñîçäàíèè îáúåêòà êëàññà ìû áóäåì çàäàâàòü èìÿ ôàéëà, êîîðäèíàòó Õ è Ó, øèðèíó è âûñîòó, è ñêîðîñòè ïî X è Y
    directionMove = 0;



    this->WindowWidth = windowWidth;
    this->WindowHeight = windowHeight;

    this->Width = 100;
    this->Height = 100;

    this->SpeedX = speedX;
    this->SpeedY = speedY;

    this->onGround = true;

    image.loadFromFile(file);          // cîçäà¸ì image îáúåêòà: ("images/actronaut.png")
    texture.loadFromImage(image);                        //çàêèäûâàåì íàøå èçîáðàæåíèå â òåêñòóðó
    sprite.setTexture(texture);                          //çàëèâàåì ñïðàéò òåêñòóðîé
  //  sprite.setTextureRect(IntRect(WindowWidth / 2, Y, Width, Height)); //Çàäàåì ñîñòîÿíèå ñïðàéòà
    sprite.setPosition((float)(WindowWidth / 2), (float)(WindowHeight - Height));

    this->CurrentFrame = 0;
    this->CurrentFrame2 = 0;

    this->boost = 10;
    this->timeBoost = 0;
    this->boostHeight = 0;
    this->key = false;
}

void Player::Run()
{
    RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "SFML works!"); //ðàçìåð èçîáðàæåíèÿ 1200x630

    while (window.isOpen())
    {
        Event event;
        time = (float)clock.getElapsedTime().asMicroseconds(); //äàòü ïðîøåäøåå âðåìÿ â ìèêðîñåêóíäàõ      
        clock.restart(); //ïåðåçàãðóæàåò âðåìÿ
        time /= 800;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Keyboard();
        Move();


        window.clear();
        window.draw(sprite);//ðèñóåì ñïðàéò îáúåêòà p êëàññà player
        window.display();
    }

}


Player::~Player() {}


void boostTimeToZero(bool& key, float& timeBoost)
{
    if (!key)
    {
        timeBoost = 0;
        key = !key;
    }
}
void incrementTime(float& timeBoost, float& time)
{
    timeBoost += time / 2000;
}

void Player::Move()
{
    CurrentFrame += (float)(0.01 * time);
    if (CurrentFrame > 10) CurrentFrame = 0;

    switch (directionMove) {
        // Stop, 0;
        {
    case 0:

        sprite.setTextureRect(IntRect(Width * 4, Height, Width, Height));
        sprite.move(0, 0);
        CurrentFrame2 = 0;

        return;
        }

        // Right, 1;
        {
    case 1:

        sprite.setTextureRect(IntRect(Width * (int)(CurrentFrame), Height * 0, Width, Height));
        sprite.move(SpeedX * time, 0);
        CurrentFrame2 = 0;
        return;
        }
        // No move to Right, 2;
        {
    case 2:
        if (CurrentFrame2 <= 4)
            CurrentFrame2 += (float)(0.015 * time);

        sprite.setTextureRect(IntRect(Width * int(CurrentFrame2), Height, Width, Height));
        sprite.move(0, 0);
        return;
        }
        // Up, to See to Right, 3;
        {
    case 3:

        if (-SpeedY + boost * timeBoost < 0 && key == false) {
            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(900, 0, Width, Height));
            sprite.move(0, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }
        boostTimeToZero(key, timeBoost);
        if (key == true && sprite.getPosition().y < WindowHeight - Height) {

            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(0, 0, Width, Height));
            sprite.move(0, boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }

        timeBoost = 0;
        key = false;
        directionMove = 2;
        return;
        }
        // Up to Right, 4;
        {
    case 4:

        if (-SpeedY + boost * timeBoost < 0 && key == false) {
            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(900, 0, Width, Height));
            sprite.move(SpeedX * time, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }
        boostTimeToZero(key, timeBoost);
        if (key == true && sprite.getPosition().y < WindowHeight - Height) {

            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(0, 0, Width, Height));
            sprite.move(SpeedX * time, boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }
        timeBoost = 0;
        key = false;
        directionMove = 2;
        return;
        }
        // Shout to Right, 5;
        {
    case 5:
        sprite.setTextureRect(IntRect(Width * (int)(CurrentFrame), Height * 2, Width, Height));

        if (Keyboard::isKeyPressed(Keyboard::Right) && onGround)
            sprite.move(SpeedX * time, 0);

        else if(Keyboard::isKeyPressed(Keyboard::Up) || onGround == false)
        {
            if (-SpeedY + boost * timeBoost < 0 && key == false) {
                onGround = false;
                incrementTime(timeBoost, time);
                sprite.move(0, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
                CurrentFrame2 = 0;
                return;
            }

            
            boostTimeToZero(key, timeBoost);

            if (key == true && sprite.getPosition().y < WindowHeight - Height)
            {
                incrementTime(timeBoost, time);
                sprite.move(0, boost * timeBoost * timeBoost / 2);
                CurrentFrame2 = 0;
                return;
            }
            onGround = true;
            timeBoost = 0;
            key = false;
        }

        else 
            sprite.move(0, 0);

        CurrentFrame2 = 0;
        return;
        }

        // Left, -1;
        {
    case -1:
        sprite.setTextureRect(IntRect(900 - Width * int(CurrentFrame), Height * 3, Width, Height));
        sprite.move(-SpeedX * time, 0);
        CurrentFrame2 = 0;
        return;
        }
        // No move to Left, -2;
        {
    case -2:
        if (CurrentFrame2 <= 4)
        {
            CurrentFrame2 += (float)(0.015 * time);
        }
        sprite.setTextureRect(IntRect(900 - Width * int(CurrentFrame2), Height, Width, Height));
        sprite.move(0, 0);
        return;
        }
        // Up, to See to Left, -3;
        {
    case -3:

        if (-SpeedY + boost * timeBoost < 0 && key == false) {

            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(0, Height * 3, Width, Height));
            sprite.move(0 * time, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }
        boostTimeToZero(key, timeBoost);
        if (key == true && sprite.getPosition().y < WindowHeight - Height) {

            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(900, Height * 3, Width, Height));
            sprite.move(0 * time, boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }
        timeBoost = 0;
        key = false;
        directionMove = -2;
        return;
        }
        // Up to Left, -4;
        {
    case -4:

        if (-SpeedY + boost * timeBoost < 0 && key == false) {

            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(0, Height * 3, Width, Height));
            sprite.move(-SpeedX * time, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }
        boostTimeToZero(key, timeBoost);
        if (key == true && sprite.getPosition().y < WindowHeight - Height) {

            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(900, Height * 3, Width, Height));
            sprite.move(-SpeedX * time, boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }
        timeBoost = 0;
        key = false;
        directionMove = -2;
        return;
        }
        // Shout to Left, -5;
        {
    case -5:
        sprite.setTextureRect(IntRect(900 - Width * (int)(CurrentFrame), Height * 4, Width, Height));
        if (Keyboard::isKeyPressed(Keyboard::Left))
            sprite.move(-SpeedX * time, 0);
        else if (Keyboard::isKeyPressed(Keyboard::Up) || onGround == false)
        {
            if (-SpeedY + boost * timeBoost < 0 && key == false) {
                onGround = false;
                incrementTime(timeBoost, time);
                sprite.move(0, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
                CurrentFrame2 = 0;
                return;
            }


            boostTimeToZero(key, timeBoost);

            if (key == true && sprite.getPosition().y < WindowHeight - Height)
            {
                incrementTime(timeBoost, time);
                sprite.move(0, boost * timeBoost * timeBoost / 2);
                CurrentFrame2 = 0;
                return;
            }
            onGround = true;
            timeBoost = 0;
            key = false;
        }
        else sprite.move(0, 0);
        CurrentFrame2 = 0;
        return;
        }
    }
}

// What is directionMove?



// directionMove = ...
// 0 - Stop (to Right)  
//              
// 1 - Go to Right
// 2 - Stay and see to Right
// 3 - Jump and see to right 
// 4 - Jump to Right 
// 
// 5 - Shout to Right
// 6 - Up and Shout to Right
// 7 - Go to back and Shout to Right
// 
// -1 - Go to Left
// -2 - Stay and see to Left
// -3 - Jump and see to left 
// -4 - Jump to Left
// 
// -5 - Shout to Left
// -6 - Go to Back and Shout to Left
//  - Up and Shout to Left


void Player::Keyboard()
{
//  FOR TO LEFT
    if (Keyboard::isKeyPressed(Keyboard::Left) && (directionMove == 0 || directionMove == -1 || directionMove == -2 || directionMove == 2))
    {
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            directionMove = -4;
            return;
        }
        else
        {
            directionMove = -1;
            return;
        }
    }

    else if (directionMove == -1)
    {
        directionMove = -2;
        return;
    }

    //  FOR TO RIGHT

    else if (Keyboard::isKeyPressed(Keyboard::Right) && (directionMove == 0 || directionMove == 1 || directionMove == 2 || directionMove == -2))
    {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            directionMove = 4;
            return;
        }
        else
        {
            directionMove = 1;
            return;
        }
    }
    else if (directionMove == 1)
    {
        directionMove = 2;
        return;
    }

    else if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        if (directionMove == -1 || directionMove == -2)
        {
            directionMove = -3;
            return;
        }

        if (directionMove == 0 || directionMove == 1 || directionMove == 2)
        {
            directionMove = 3;
            return;
        }
    }
    //                     ATTACK !!!

    else if (Keyboard::isKeyPressed(Keyboard::Space))
    {
        if (directionMove == 0 || directionMove == 2 ) {
            directionMove = 5; // Shout to Right;
            return; 
        }

        else if (directionMove == -2 )
        {
            directionMove = -5; // Shout to Left;
            return;
        }
    }
    else if (directionMove == 5 && onGround)
    {
        directionMove = 2;
        return;
    }
    else if (directionMove == -5 && onGround)
    {
        directionMove = -2;
        return;
    }
}


