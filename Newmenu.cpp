#include <SFML/Graphics.hpp>
#include "Newmenu.h"


using namespace sf;
using namespace std;

StartingMenu::StartingMenu(){
    int score;
}
void StartingMenu::run(RenderWindow& window) {
    //текстуры
    Texture menuTexture1, menuTexture2, menuTexture3, aboutTexture, menuBackground;
    menuTexture1.loadFromFile("../images/PLAY.png");
    menuTexture2.loadFromFile("../images/alien_wave_2.png");
    menuBackground.loadFromFile("../images/background3.png");

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
                play(window, isMenu); //прожали play перешли на другую страницу меню
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
        MainMenu m;
        m.run(window);
    }
};
void StartingMenu::lor(RenderWindow& window) {

    Texture lor, planet;
    planet.loadFromFile("C:/Users/79096/CLionProjects/game3/PLAY.png");
    lor.loadFromFile("C:/Users/79096/CLionProjects/game3/blackbg.jpg");
    Sprite getLor(lor), planet1(planet);
    getLor.setPosition(0, 0);
    planet1.setPosition(300, 300);

    Font font;
    font.loadFromFile("C:\\Users\\79096\\CLionProjects\\game3\\Art_Gothic_ExtraBold.ttf");
    Text lor1("Once upon a time", font), lor2("Once upon a time", font),
    lor3("Once upon a time", font), lor4("Once upon a time", font);

    lor1.setString("In the year 2150, the Earth is destroyed. ");
    lor2.setString("Huge monsters from other planets filled the whole space,");
    lor3.setString(" so people had to go underground, ");
    lor4.setString("where they can get at least one chance...");
    lor1.setPosition(200, 100);
    lor1.setCharacterSize(30);
    lor2.setPosition(100, 200);
    lor2.setCharacterSize(30);
    lor3.setPosition(300, 300);
    lor3.setCharacterSize(50);
    lor4.setPosition(200, 400);
    lor4.setCharacterSize(50);


    Clock clock;
    clock.restart();
    int y = 500;
    int delta;

    while (window.isOpen()) {
        window.clear();
            if(y > 0) {

                auto t = clock.getElapsedTime().asSeconds();
                y = y - 0.000001*t;
                planet1.setPosition(300, y);
               //lor1.setPosition(400, y);
//                lor2.setPosition(380, y - 100);
        }

        clock.restart();
        window.draw(getLor);

//        window.draw(lor2);
        window.draw(planet1);
//        window.draw(lor1);
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
void StartingMenu::lo1(RenderWindow& window){
    Texture lor, planet;
    planet.loadFromFile("C:/Users/79096/CLionProjects/game3/PLAY.png");
    lor.loadFromFile("C:/Users/79096/CLionProjects/game3/blackbg.jpg");
    Sprite getLor(lor), planet1(planet);
    getLor.setPosition(0, 0);
    planet1.setPosition(300, 300);

    Font font;
    font.loadFromFile("C:\\Users\\79096\\CLionProjects\\game3\\Art_Gothic_ExtraBold.ttf");
    Text lor1("Once upon a time", font), lor2("Once upon a time", font),
            lor3("Once upon a time", font), lor4("Once upon a time", font);

    lor1.setString("In the year 2150, the Earth is destroyed. ");
    lor2.setString("Huge monsters from other planets filled the whole space,");
    lor3.setString(" so people had to go underground, ");
    lor4.setString("where they can get at least one chance...");
    lor1.setPosition(200, 100);
    lor1.setCharacterSize(30);
    lor2.setPosition(100, 200);
    lor2.setCharacterSize(30);
    lor3.setPosition(300, 300);
    lor3.setCharacterSize(50);
    lor4.setPosition(200, 400);
    lor4.setCharacterSize(50);


    Clock clock;
    clock.restart();
    int y = 500;
    int delta;

    while (window.isOpen()) {
    window.clear();
    if(y > 0) {

    auto t = clock.getElapsedTime().asSeconds();
    y = y - 0.000001*t;
    planet1.setPosition(300, y);
    //lor1.setPosition(400, y);
    //                lor2.setPosition(380, y - 100);
    }

    clock.restart();
    window.draw(getLor);

    //        window.draw(lor2);
    window.draw(planet1);
    //        window.draw(lor1);
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
