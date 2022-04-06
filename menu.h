//
// Created by sageblatt on 01.04.2022.
//

#ifndef ALIEN_STARTINGMENU_H
#define ALIEN_STARTINGMENU_H
#pragma once
#include <SFML/Graphics.hpp>
#include "MainManu.h"
using namespace  sf;

class StartingMenu: public Menu {
protected:
    static void nextWindow(RenderWindow& window, bool NextMenu);

public:
     StartingMenu();
     static void run(sf::RenderWindow& window) ;
    ~StartingMenu() = default;
};


#endif //ALIEN_STARTINGMENU_H
