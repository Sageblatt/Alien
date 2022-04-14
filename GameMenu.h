#ifndef ALIEN_GAMEMENU_H
#define ALIEN_GAMEMENU_H

#include <SFML/Graphics.hpp>
#include "Menu.h"

using namespace  sf;
using std::make_unique;


class GameMenu: public Menu {
public:
    explicit GameMenu(std::shared_ptr<RenderWindow> wind);
    int run() override;
};

#endif //ALIEN_GAMEMENU_H