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
    std::unique_ptr<Font> font;
    std::array<std::unique_ptr<Texture>, 6> lor_textures;
    std::array<std::unique_ptr<Sprite>, 6> lor_sprites;
    std::unique_ptr<Text> tab_text;
    std::unique_ptr<Clock> timer;
    std::array<float, 3> lor_x;
    std::array<float, 3> lor_y;

    const float LOR_SPEED = 50;

    void nextWindow() override;

public:
    explicit StartingMenu(std::shared_ptr<RenderWindow> wind);

    void lor();
    void lor1();
    void lor3();
    void lorn(unsigned n);
    void run() override;
};


#endif //ALIEN_STARTINGMENU_H
