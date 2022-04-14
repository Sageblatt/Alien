#ifndef ALIEN_MAINMENU_H
#define ALIEN_MAINMENU_H

#include "Menu.h"
#include "GameMenu.h"

using namespace sf;
using std::make_unique;

class MainMenu: public Menu {
public:
    explicit MainMenu(std::shared_ptr<RenderWindow> wind);
    int run() override;
};


#endif //ALIEN_MAINMENU_H