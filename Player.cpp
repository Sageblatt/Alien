#include "Player.h"
#include <iostream>


Player::Player(String file, float speedX, float speedY, int windowWidth, int windowHeight)
{
    this->file = file;
    //Конструктор с параметрами для класса Player. 
    //При создании объекта класса мы будем задавать имя файла, координату Х и У, ширину и высоту, и скорости по X и Y
    directionMove = 0;
    directionAttack = 0;


    this->WindowWidth = windowWidth;
    this->WindowHeight = windowHeight;

    this->Width = 100;
    this->Height = 100;

    this->SpeedX = speedX;
    this->SpeedY = speedY;
    
    image.loadFromFile(file);          // cоздаём image объекта: ("images/actronaut.png")
    texture.loadFromImage(image);                        //закидываем наше изображение в текстуру
    sprite.setTexture(texture);                          //заливаем спрайт текстурой
  //  sprite.setTextureRect(IntRect(WindowWidth / 2, Y, Width, Height)); //Задаем состояние спрайта
    sprite.setPosition((float)(WindowWidth/2), (float)(WindowHeight - Height));

    this->CurrentFrame = 0;
    this->CurrentFrame2 = 0;
    this->CurrentAttack = 0;
    this->CurrentAttack2 = 0;
    this->boost = 10;
    this->timeBoost = 0;
    this->boostHeight = 0;
    this->key = false;
}

void Player::Run() 
{
    RenderWindow window(sf::VideoMode(WindowWidth, WindowHeight), "SFML works!"); //размер изображения 1200x630

    while (window.isOpen())
    {
        Event event;
        time = (float)clock.getElapsedTime().asMicroseconds(); //дать прошедшее время в микросекундах      
        clock.restart(); //перезагружает время
        time /= 800;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        Keyboard();
        Move();
        KeyboardAttack();
        Attack();


        window.clear();
        window.draw(sprite);//рисуем спрайт объекта p класса player
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
        {
    case 0: // Stop;

        sprite.setTextureRect(IntRect(Width * 4, Height, Width, Height));
        sprite.move(0, 0);
        CurrentFrame2 = 0;

        return;
        }
        {
    case 1: // Left;
        sprite.setTextureRect(IntRect(900 - Width * int(CurrentFrame), Height * 3, Width, Height));
        sprite.move(-SpeedX * time, 0);
        CurrentFrame2 = 0;
        return;
        }
        {
    case 2: // Right;

        sprite.setTextureRect(IntRect(Width * (int)(CurrentFrame), Height * 0, Width, Height));
        sprite.move(SpeedX * time, 0);
        CurrentFrame2 = 0;
        return;
        }
        {
    case 3: // Up, to See to Right;

        if (-SpeedY + boost * timeBoost < 0 && key == false) {
            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(900, 0, Width, Height));
            sprite.move(0 * time, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }
        boostTimeToZero(key, timeBoost);
        if (key == true && sprite.getPosition().y < WindowHeight - Height) {

            incrementTime(timeBoost, time);
            sprite.setTextureRect(IntRect(0, 0, Width, Height));
            sprite.move(0 * time, boost * timeBoost * timeBoost / 2);
            CurrentFrame2 = 0;
            return;
        }

        timeBoost = 0;
        key = false;
        directionMove = 5;
        return;
        }
        {
    case 4: // No move to Left;
        if (CurrentFrame2 <= 4)
        {
            CurrentFrame2 += (float)(0.015 * time);
        }
        sprite.setTextureRect(IntRect(900 - Width * int(CurrentFrame2), Height, Width, Height));
        sprite.move(0, 0);
        return;
        }
        {
    case 5: // No move to Right;
        if (CurrentFrame2 <= 4)
        {
            CurrentFrame2 += (float)(0.015 * time);
        }
        //std::cout << 5;
        sprite.setTextureRect(IntRect(Width * int(CurrentFrame2), Height, Width, Height));
        sprite.move(0, 0);
        return;
        }
        {
    case 6: // Up, to See to Left;

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
        directionMove = 4;
        return;
        }
        {
    case 7: // Up to Left;

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
        directionMove = 4;
        return;
        }
       {
    case 8: // Up to Right;

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
        directionMove = 5;
        return;
        }
    }
    
}

void Player::Keyboard()
{
    if (!Keyboard::isKeyPressed(Keyboard::Space))
    {

        if (Keyboard::isKeyPressed(Keyboard::Left) && (directionMove == 0 || directionMove == 1 || directionMove == 4 || directionMove == 5))
        {
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                directionMove = 7;
                return;
            }
            directionMove = 1;
            return;
        }

        else if (directionMove == 1)
        {
            directionMove = 4;
            return;
        }


        else if (Keyboard::isKeyPressed(Keyboard::Right) && (directionMove == 0 || directionMove == 2 || directionMove == 5 || directionMove == 4))
        {
            if (Keyboard::isKeyPressed(Keyboard::Up)) {
                directionMove = 8;
                return;
            }
            directionMove = 2;
            return;
        }
        else if (directionMove == 2)
        {
            directionMove = 5;
            return;
        }

        else if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            if (directionMove == 1 || directionMove == 4)
            {
                directionMove = 6;
                return;
            }
            if (directionMove == 0 || directionMove == 2 || directionMove == 5)
            {
                directionMove = 3;
                return;
            }
        }
    }
}

void Player::KeyboardAttack() {

    if (Keyboard::isKeyPressed(Keyboard::Space)) {

        if (Keyboard::isKeyPressed(Keyboard::Left) && (directionAttack == 0 || directionAttack == 1 || directionAttack == 4 || directionAttack == 5))
        {
            //if (Keyboard::isKeyPressed(Keyboard::Up)) {
            //    directionAttack = 7;
            //    return;
            //}
            directionAttack = 1;
            return;
        }

        else if (directionAttack == 1)
        {
            directionAttack = 4;
            return;
        }


        else if (Keyboard::isKeyPressed(Keyboard::Right) && (directionAttack == 0 || directionAttack == 2 || directionAttack == 5 || directionAttack == 4))
        {
            //if (Keyboard::isKeyPressed(Keyboard::Up)) {
            //    directionAttack = 8;
            //    return;
            //}
            directionAttack = 2;
            return;
        }
        else if (directionAttack == 2)
        {
            directionAttack = 5;
            return;
        }

        //else if (Keyboard::isKeyPressed(Keyboard::Up))
        //{
        //    if (directionAttack == 1 || directionAttack == 4)
        //    {
        //        directionAttack = 6;
        //        return;
        //    }
        //    if (directionAttack == 0 || directionAttack == 2 || directionAttack == 5)
        //    {
        //        directionAttack = 3;
        //        return;
        //    }
        //}
    }
}



void Player::Attack()
{
    CurrentAttack += (float)(0.01 * time);
    if (CurrentAttack > 10) CurrentAttack = 0;
    
    if (!Keyboard::isKeyPressed(Keyboard::Space)) return;
    switch (directionAttack) {
        
    case 0: // Stop;
        if (Keyboard::isKeyPressed(Keyboard::Space) )
        {
            sprite.setTextureRect(IntRect(Width * (int)(CurrentAttack), Height * 2, Width, Height));
                sprite.move(0, 0);
                CurrentAttack2 = 0;

                return;
        }
        
        
    //case 1: // Left;
    //    sprite.setTextureRect(IntRect(900 - Width * int(CurrentAttack), Height * 4, Width, Height));
    //    sprite.move(-SpeedX * time, 0);
    //    CurrentAttack2 = 0;
    //    return;
 
    //case 2: // Right;

    //    sprite.setTextureRect(IntRect(Width * (int)(CurrentAttack), Height * 2, Width, Height));
    //    sprite.move(SpeedX * time, 0);
    //    CurrentAttack2 = 0;
    //    return;

    //case 3: // Up, to See to Right;

    //    if (-SpeedY + boost * timeBoost < 0 && key == false) {
    //        incrementTime(timeBoost, time);
    //        sprite.setTextureRect(IntRect( Width * (int)(CurrentAttack), Height * 2, Width, Height));
    //        sprite.move(0 * time, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
    //        CurrentAttack2 = 0;
    //        return;
    //    }
    //    boostTimeToZero(key, timeBoost);
    //    if (key == true && sprite.getPosition().y < WindowHeight - Height) {

    //        incrementTime(timeBoost, time);
    //        sprite.setTextureRect(IntRect(900 - Width * (int)(CurrentAttack), Height * 2, Width, Height));
    //        sprite.move(0 * time, boost * timeBoost * timeBoost / 2);
    //        CurrentAttack2 = 0;
    //        return;
    //    }

    //    timeBoost = 0;
    //    key = false;
    //    directionAttack = 5;
    //    return;

    case 4: // No move to Left;
        if (CurrentAttack2 <= 4)
        {
            CurrentAttack2 += (float)(0.015 * time);
        }
        sprite.setTextureRect(IntRect(900 - Width * int(CurrentAttack), Height * 4, Width, Height));
        sprite.move(0, 0);
        return;

    case 5: // No move to Right;
        if (CurrentAttack2 <= 4)
        {
            CurrentAttack2 += (float)(0.015 * time);
        }
        //std::cout << 5;
        sprite.setTextureRect(IntRect(Width * (int)(CurrentAttack), Height * 2, Width, Height));
        sprite.move(0, 0);
        return;

    //case 6: // Up, to See to Left;

    //    if (-SpeedY + boost * timeBoost < 0 && key == false) {

    //        incrementTime(timeBoost, time);
    //        sprite.setTextureRect(IntRect(900 - Width * int(CurrentAttack), Height * 4, Width, Height));
    //        sprite.move(0 * time, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
    //        CurrentAttack2 = 0;
    //        return;
    //    }
    //    boostTimeToZero(key, timeBoost);
    //    if (key == true && sprite.getPosition().y < WindowHeight - Height) {

    //        incrementTime(timeBoost, time);
    //        sprite.setTextureRect(IntRect(900 - Width * int(CurrentAttack), Height * 4, Width, Height));
    //        sprite.move(0 * time, boost * timeBoost * timeBoost / 2);
    //        CurrentAttack2 = 0;
    //        return;
    //    }
    //    timeBoost = 0;
    //    key = false;
    //    directionAttack = 4;
    //    return;

    //case 7: // Up to Left;

    //    if (-SpeedY + boost * timeBoost < 0 && key == false) {

    //        incrementTime(timeBoost, time);
    //        sprite.setTextureRect(IntRect(900 - Width * int(CurrentAttack), Height * 4, Width, Height));
    //        sprite.move(-SpeedX * time, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
    //        CurrentAttack2 = 0;
    //        return;
    //    }
    //    boostTimeToZero(key, timeBoost);
    //    if (key == true && sprite.getPosition().y < WindowHeight - Height) {

    //        incrementTime(timeBoost, time);
    //        sprite.setTextureRect(IntRect(900 - Width * int(CurrentAttack), Height * 4, Width, Height));
    //        sprite.move(-SpeedX * time, boost * timeBoost * timeBoost / 2);
    //        CurrentAttack2 = 0;
    //        return;
    //    }
    //    timeBoost = 0;
    //    key = false;
    //    directionAttack = 4;
    //    return;

    //case 8: // Up to Right;

    //    if (-SpeedY + boost * timeBoost < 0 && key == false) {
    //        incrementTime(timeBoost, time);
    //        sprite.setTextureRect(IntRect(Width * (int)(CurrentAttack), Height * 2, Width, Height));
    //        sprite.move(SpeedX * time, -SpeedY * timeBoost + boost * timeBoost * timeBoost / 2);
    //        CurrentAttack2 = 0;
    //        return;
    //    }
    //    boostTimeToZero(key, timeBoost);
    //    if (key == true && sprite.getPosition().y < WindowHeight - Height) {

    //        incrementTime(timeBoost, time);
    //        sprite.setTextureRect(IntRect(Width * (int)(CurrentAttack), Height * 2, Width, Height));
    //        sprite.move(SpeedX * time, boost * timeBoost * timeBoost / 2);
    //        CurrentAttack2 = 0;
    //        return;
    //    }
    //    timeBoost = 0;
    //    key = false;
    //    directionAttack = 5;
        return;
    }
    
}