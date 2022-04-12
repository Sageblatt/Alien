#include "StartingMenu.h"

StartingMenu::StartingMenu(std::shared_ptr<RenderWindow> wind) {
    window = wind;

    //текстуры
    for (auto i = 0; i < 3; i++)
        textures.emplace_back(make_unique<Texture>());

    textures[0]->loadFromFile("../images/PLAY.png");
    textures[1]->loadFromFile("../images/alien_wave_2.png");
    textures[2]->loadFromFile("../images/background3.png");

    //спрайты
    for (auto i = 0; i < 3; i++)
        sprites.emplace_back(make_unique<Sprite>(*textures[i]));
}

void StartingMenu::run() {
    sprites[0]->setPosition(300, 600);
    sprites[1]->setPosition(-400, -500);
    sprites[2]->setPosition(0, 0);

    //номер меню и открыто окно или нет
    bool isMenu = 1;
    int menuNum = 0;

    //вызов окна меню
    while (isMenu and window->isOpen()) {
        window->clear(Color(129, 181, 221));

        if (IntRect(400, 600, 400, 100).contains(Mouse::getPosition(*window))) {
            sprites[0]->setColor(Color::Red);
            menuNum = 1;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1) {
                window->clear(Color(129, 181, 221));
                if (isMenu)
                    nextWindow(); //прожали play перешли на другую страницу меню
                //lor(window) вызов первого лора
                break;
            }

        }

        window->draw(*sprites[2]);
        window->draw(*sprites[0]);
        window->draw(*sprites[1]);
        window->display();

        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed ||
                (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
                window->close();
            }
        }

    }
}

void StartingMenu::nextWindow() {
    MainMenu m(window);
    m.run();
}

void StartingMenu::lor() {

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
    double y = 500;

    while (window->isOpen()) {
        window->clear();
            if(y > 0) {

                auto t = clock.getElapsedTime().asSeconds();
                y = y - 0.000001*t;
                planet1.setPosition(300, y);
               //lor1.setPosition(400, y);
//                lor2.setPosition(380, y - 100);
        }

        clock.restart();
        window->draw(getLor);

//        window.draw(lor2);
        window->draw(planet1);
//        window.draw(lor1);
        window->display();
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed ||
                (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
                window->close();
            }
        }
    }
}

void StartingMenu::lo1(){
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
    double y = 500;

    while (window->isOpen()) {
        window->clear();
        if(y > 0) {
            auto t = clock.getElapsedTime().asSeconds();
            y = y - 0.000001*t;
            planet1.setPosition(300, y);
            //lor1.setPosition(400, y);
            //lor2.setPosition(380, y - 100);
        }

        clock.restart();
        window->draw(getLor);

        //        window.draw(lor2);
        window->draw(planet1);
        //        window.draw(lor1);
        window->display();

        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::Closed ||
                (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)) {
                window->close();
            }
        }
    }
}
// void StartingMenu::lor(RenderWindow& window) {

//     Texture lor, text;
//     text.loadFromFile("C:/Users/79096/CLionProjects/game3/lor_1.png");
//     lor.loadFromFile("C:/Users/79096/CLionProjects/game3/The_Earth.png");

//     Sprite getLor(lor), planet1(text);
//     getLor.setPosition(0, 0);
//     planet1.setPosition(-700, 300);
//     Font font;
//     font.loadFromFile("C:/Users/79096/CLionProjects/game3/tab.ttf");
//     Text tab("Press Tab to continue", font);
//     tab.setString("Press Tab to continue");
//     tab.setCharacterSize(20);
//     Clock clock;
//     tab.setPosition(100, 700);
//     long long y = 700;
//     int x = -300;

//     while (window.isOpen()) {

//             if(y >= 0) {
//                 clock.restart();
//                 auto t = clock.getElapsedTime().asSeconds();
//                 y = y - 100000*t;
//                planet1.setPosition(x, y );
//                 clock.restart();
//         }


//         window.draw(getLor);
//         window.draw(planet1);
//         if (y<=0){
//             window.draw(tab);
//         }
//         window.display();
//         window.clear();

//         Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == Event::Closed ||
//                 (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)) {
//                 lor1(window);
//             }

//         }
//     }
// }
// void StartingMenu::lor1(RenderWindow& window) {
//     Texture lor, planet;
//     planet.loadFromFile("C:/Users/79096/CLionProjects/game3/lor_2.png");
//     lor.loadFromFile("C:/Users/79096/CLionProjects/game3/sportzal.png");
//     Sprite getLor(lor), planet1(planet);
//     getLor.setPosition(0, 0);
//     planet1.setPosition(300, 300);
//     Font font;
//     font.loadFromFile("C:/Users/79096/CLionProjects/game3/tab.ttf");
//     Text tab("Press Tab to continue", font);
//     tab.setString("Press Tab to continue");
//     tab.setCharacterSize(20);
//     tab.setPosition(100, 700);
//     Clock clock;
//     int y = 500;
//     int x = -100;
//     int delta;

//     while (window.isOpen()) {

//         if (y >= 0) {
//             clock.restart();
//             auto t = clock.getElapsedTime().asSeconds();
//             y = y - 100000* t;
//             planet1.setPosition(x, y);
//             clock.restart();
//         }

//         window.draw(getLor);
//         window.draw(planet1);
//         if (y<=0){
//             window.draw(tab);
//         }
//         window.display();
//         Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == Event::Closed ||
//                 (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)) {
//                 lor3(window);
//             }

//         }
//     }
// }
// void StartingMenu::lor3(RenderWindow& window) {

//     Texture lor, text;
//     text.loadFromFile("C:/Users/79096/CLionProjects/game3/lor_3.png");
//     lor.loadFromFile("C:/Users/79096/CLionProjects/game3/monsters.png");

//     Sprite getLor(lor), planet1(text);
//     getLor.setPosition(0, 0);
//     planet1.setPosition(300, 300);
//     Font font;
//     font.loadFromFile("C:/Users/79096/CLionProjects/game3/tab.ttf");
//     Text tab("Press Tab to continue", font);
//     tab.setString("Press Tab to continue");
//     tab.setCharacterSize(20);
//     tab.setPosition(100, 700);
//     Clock clock;

//     long long y = 300;
//     int x = 400;

//     while (window.isOpen()) {

//         if(y >= 0) {
//             clock.restart();
//             auto t = clock.getElapsedTime().asSeconds();
//             y = y - 1000*t;
//             planet1.setPosition(x, y );
//             clock.restart();
//         }

//         window.draw(getLor);
//         window.draw(planet1);
//         if (y<=0){
//             window.draw(tab);
//         }
//         window.display();
//         window.clear();

//         Event event;
//         while (window.pollEvent(event)) {
//             if (event.type == Event::Closed ||
//                 (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)) {
//                 play(window,1);
//                 window.close();


//             }

//         }
//     }
// }



