
#ifndef ALIEN_MENU_H
#define ALIEN_MENU_H
#pragma once
#include <SFML/Graphics.hpp>
#include <vector>



class MainMenu {
protected:
    std::vector <sf::Sprite> textures;
    unsigned long score;

    //virtual void nextWindow() = 0;

public:
    MainMenu();
    static void run(sf::RenderWindow& window) ;

};


#endif //ALIEN_MENU_H