#include <SFML/Graphics.hpp>
#include "menu.h"
#include "MainManu.h"
#include <string>

using namespace sf;
using namespace std;
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
    Sprite menu1(menuTexture1), menu2(menuTexture2), menuBg(menuBackground);
    menu1.setPosition(300, 600);
    menu2.setPosition(-400, -500);
    menuBg.setPosition(0, 0);

    //номер меню и открыто окно или нет
    bool isMenu = 1;
    int menuNum = 0;

    //вызов окна меню
    while (isMenu) {
        window.clear(Color(129, 181, 221));

        if (IntRect(400, 600, 400, 100).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color::Red);
            menuNum = 1;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                window.clear(Color(129, 181, 221));
                lor(window); //прожали play, пошёл лор
                break;
            }

        }

        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        //window.draw(menu3);
        window.display();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed ||
                (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
                window.close();
            }

        }

    }
}
void StartingMenu::play (RenderWindow& window, bool NextMenu) {
    if (NextMenu == 1){
        Menu m;
        m.run(window);
    }
};
void StartingMenu::lor(RenderWindow& window) {

    Texture lor;
    lor.loadFromFile("C:/Users/79096/CLionProjects/game3/blackbg.jpg");
    Sprite getLor(lor);
    getLor.setPosition(0, 0);

    Font font;
    font.loadFromFile("C:\\Users\\79096\\CLionProjects\\game3\\Art_Gothic_ExtraBold.ttf");
    Text lor1("Once upon a time", font);
    lor1.setString("Once upon a time");
    lor1.setPosition(360, 100);
    lor1.setCharacterSize(50);

    Clock clock;
    clock.restart();
    int x = 500;
    float y = 500;

    while (window.isOpen()) {
        window.clear();
            if(y > 0) {

                auto t = clock.getElapsedTime().asSeconds();
                y = y - 30*t;
                lor1.setPosition(x, y);
        }
        clock.restart();

        window.draw(getLor);
        window.draw(lor1);
        window.display();
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed ||
                (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
                window.close();
            }

        }
    }
}
