#ifndef ALIEN_MAINMENU_H
#define ALIEN_MAINMENU_H

#include "Menu.h"
#include "GameMenu.h"

using namespace sf;
using std::make_unique;

class MainMenu: public Menu {
protected:
    void nextWindow() override;

public:
    explicit MainMenu(std::shared_ptr<RenderWindow> wind);
    void run() override;
};


#endif //ALIEN_MAINMENU_H