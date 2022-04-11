#ifndef ALIEN_MAINMENU_H
#define ALIEN_MAINMENU_H

#include <SFML/Graphics.hpp>
#include <vector>

using namespace sf;

class MainMenu {
protected:
    std::vector <sf::Sprite> textures;
    unsigned long score;

    //virtual void nextWindow() = 0;

public:
    MainMenu();
    static void run(sf::RenderWindow& window) ;

};


#endif //ALIEN_MAINMENU_H