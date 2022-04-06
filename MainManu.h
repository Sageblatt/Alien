
#ifndef ALIEN_MENU_H
#define ALIEN_MENU_H
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>



class Menu {
protected:
    std::vector <sf::Sprite> textures;
    unsigned long score;

    //virtual void nextWindow() = 0;

public:
    Menu();
    static void run(sf::RenderWindow& window) ;
    ~Menu() = default;
};


#endif //ALIEN_MENU_H