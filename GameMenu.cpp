
#include "GameMenu.h"
#include <SFML/Graphics.hpp>

using namespace sf;

GameMenu::GameMenu(){
    int score;
}
void GameMenu::RunPlanets(RenderWindow& window) {
    //текстуры
    Texture menuTexture1, menuTexture2, menuTexture3, menuTexture4, menuBackground;
    menuTexture1.loadFromFile("C:/Users/79096/CLionProjects/game3/planet_2.png");
    menuTexture2.loadFromFile("C:/Users/79096/CLionProjects/game3/planet_1.png");
    menuTexture3.loadFromFile("C:/Users/79096/CLionProjects/game3/planet_3.png");
    menuTexture4.loadFromFile("C:/Users/79096/CLionProjects/game3/CHOOSE_A_PLANET.png");
    menuBackground.loadFromFile("C:/Users/79096/CLionProjects/game3/background_4.png");

    //спрайты
    Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3), menu4(menuTexture4), menuBg(menuBackground);
    menu1.setPosition(950, 300); // PURPLE 200X200
    menu2.setPosition(500, 500); // FIRE
    menu3.setPosition(200, 250); // ELECTRIC
    menu4.setPosition(300, 60); // CHOOSE_A_PLANET
    menuBg.setPosition(0, 0);

    //номер меню и открыто окно или нет
    bool isMenu = 1;
    int menuNum = 0;

    //вызов окна меню
    while (isMenu) {
        menu1.setColor(Color::White);
        menu2.setColor(Color::White);
        menu3.setColor(Color::White);
        menuNum = 0;
        window.clear(Color(129, 181, 221));

        if (IntRect(950, 300, 200, 200).contains(Mouse::getPosition(window))) {
            menu1.setColor(Color::Blue);
            menuNum = 1;
        } else if (IntRect(500, 500, 200, 200).contains(Mouse::getPosition(window))) {
            menu2.setColor(Color::Blue);
            menuNum = 2;
        } else if (IntRect(200, 250, 200, 200).contains(Mouse::getPosition(window))) {
            menu3.setColor(Color::Blue);
            menuNum = 3;
        }


        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1 or menuNum == 2 or menuNum == 3) {
                isMenu = false;

            }
        }
        window.draw(menuBg);
        window.draw(menu1);
        window.draw(menu2);
        window.draw(menu3);
        window.draw(menu4);
        window.display();


            Event event{};
            while (window.pollEvent(event)) {
                if (event.type == Event::Closed ||
                    (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
                    window.close();
                }

            }
        }
    }






