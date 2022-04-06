#include <SFML/Graphics.hpp>
#include "menu.h"
#include "MainManu.h"
#include <string>
using namespace sf;

StartingMenu::StartingMenu(){
    int score;
}
void StartingMenu::run(RenderWindow& window) {
    //текстуры
    Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
    menuTexture1.loadFromFile("C:/Users/79096/CLionProjects/game3/PLAY.png");
    menuTexture2.loadFromFile("C:/Users/79096/CLionProjects/game3/alien_wave_2.png");
    menuBackground.loadFromFile("C:/Users/79096/CLionProjects/game3/5698aad283f6267.png");

    //спрайты
    Sprite menu1(menuTexture1), menu2(menuTexture2),  menuBg(menuBackground);
    menu1.setPosition(300, 600);
    menu2.setPosition(-400, -500);
    menuBg.setPosition(0, 0);

    //номер меню и открыто окно или нет
    bool isMenu = 1;
    int menuNum = 0;

    //вызов окна меню
    while (isMenu)
    {
        menu1.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(400, 600, 300, 600).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color::Red);
            menuNum = 1;
        }

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                nextWindow(window, menuNum);
                break;
            }
            //если нажали первую кнопку, то выходим из меню
        }


        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        //window.draw(menu3);
        window.display();

    }

}
void StartingMenu::nextWindow(RenderWindow& window, bool NextMenu) {
    if (NextMenu == 1){
        Menu m;
        m.run(window);
    }
}

