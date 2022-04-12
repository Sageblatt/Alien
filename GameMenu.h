#ifndef ALIEN_GAMEMENU_H
#define ALIEN_GAMEMENU_H

#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace  sf;
using std::make_unique;


class GameMenu: public Menu {
protected:
    void nextWindow() override;

public:
    explicit GameMenu(std::shared_ptr<RenderWindow> wind);
    void run() override;
};

#endif //ALIEN_GAMEMENU_H