//
// Created by sageblatt on 01.04.2022.
//

#ifndef ALIEN_STARTINGMENU_H
#define ALIEN_STARTINGMENU_H

#include "MainMenu.h"
#include "Menu.h"

using namespace sf;
using std::make_unique;

class StartingMenu: public Menu {
protected:
    std::shared_ptr<RenderWindow> window;

    void nextWindow() override;

public:
    explicit StartingMenu(std::shared_ptr<RenderWindow> wind);

    void lor();
    void lo1();
    void run() override;
};


#endif //ALIEN_STARTINGMENU_H
