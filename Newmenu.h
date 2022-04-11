//
// Created by sageblatt on 01.04.2022.
//

#ifndef ALIEN_STARTINGMENU_H
#define ALIEN_STARTINGMENU_H
#pragma once
#include <SFML/Graphics.hpp>
#include "MainManu.h"
using namespace  sf;

class StartingMenu {
protected:
    void play(RenderWindow& window, bool NextMenu);

public:
     void lor(sf::RenderWindow& window);
     StartingMenu();
     void lo1(sf::RenderWindow& window);
     void run(sf::RenderWindow& window);
//    ~StartingMenu() = default;
};


#endif //ALIEN_STARTINGMENU_H
