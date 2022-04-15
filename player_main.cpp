﻿#include "Player.h"
#include <SFML/Graphics.hpp>
#include "Monster.h"
using namespace sf;

int main()
{   //Задали размер окна
    
    Player hero("../images/astronaut.png", 0.2f, 5, 1376, 768);
    Monster alien("../images/ALIEN.png", 2.5, 1376, 768);
    
    Clock clock; //создаем переменную для привязки персонажа ко времени.
    float time;

    RenderWindow window(sf::VideoMode(1376, 768), "SFML works!");

    while (window.isOpen())
    {
        Event event;
        time = (float)clock.getElapsedTime().asMicroseconds(); 
        
        time /= 800;
        hero.SetTime(time);
        alien.SetTime(time);
        clock.restart();
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        hero.Keyboard();
        hero.Move();
        alien.Move();
        alien.Attack();
        window.clear();

        hero.Draw(window);
        alien.Draw(window);
        window.display();
    }
}