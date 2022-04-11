#include "MainManu.h"
using namespace sf;

MainMenu::MainMenu(){
    int k;
}
void MainMenu::run(RenderWindow& window) {
    //текстуры
    Texture menuTexture1, menuTexture2, menuTexture3, menuBackground;
    menuTexture1.loadFromFile("C:/Users/79096/CLionProjects/game3/CONTINUE.png");
    menuTexture2.loadFromFile("C:/Users/79096/CLionProjects/game3/EXIT.png");
    menuTexture3.loadFromFile("C:/Users/79096/CLionProjects/game3/NEW_GAME.png");
    menuBackground.loadFromFile("C:/Users/79096/CLionProjects/game3/background_2.png");

    //спрайты
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menuBg(menuBackground);
    menu1.setPosition(400, 400);
    menu2.setPosition(400, 300);
    menu3.setPosition(400, 500);
    menuBg.setPosition(0, 0);

    //номер меню и открыто окно или нет
    bool isMenu = 1;
    int menuNum = 0;

    //вызов окна меню
    while (isMenu) {
        menu1.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(400, 600, 300, 600).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color::Red);
            menuNum = 1;
        }
//
//        if (Mouse::isButtonPressed(Mouse::Left)) {
//            if (menuNum == 1)
//                //isMenu = false; //если нажали первую кнопку, то выходим из меню
//        }


        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.display();


    }
}
