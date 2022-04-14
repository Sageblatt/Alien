#include "StartingMenu.h"
#include "Game.h"
#include "AudioEngine.h"

StartingMenu::StartingMenu(std::shared_ptr<RenderWindow> wind) {
    window = wind;

    font = make_unique<Font>();
    font->loadFromFile("../fonts/tab.ttf");

    tab_text = std::make_unique<Text>("Press Tab to continue", *font);
    tab_text->setString("Press Tab to continue");
    tab_text->setCharacterSize(20);
    tab_text->setPosition(100, 700);

    //текстуры
    for (auto i = 0; i < 3; i++)
        textures.emplace_back(make_unique<Texture>());

    for (auto i = 0; i < 6; i++)
        lor_textures[i] = make_unique<Texture>();

    textures[0]->loadFromFile("../images/PLAY.png");
    textures[1]->loadFromFile("../images/alien_wave_2.png");
    textures[2]->loadFromFile("../images/first_screen.png");

    lor_textures[0]->loadFromFile("../images/lor_1.png");
    lor_textures[1]->loadFromFile("../images/The_Earth.png");
    lor_textures[2]->loadFromFile("../images/lor_2.png");
    lor_textures[3]->loadFromFile("../images/gym.png");
    lor_textures[4]->loadFromFile("../images/lor_3.png");
    lor_textures[5]->loadFromFile("../images/monsters.png");

    //спрайты
    for (auto i = 0; i < 3; i++)
        sprites.emplace_back(make_unique<Sprite>(*textures[i]));

    for (auto i = 0; i < 6; i++)
        lor_sprites[i] = make_unique<Sprite>(*lor_textures[i]);
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
                if (isMenu) {
                    Game::getInstance()->getAEng()->setFadeFlag(LOR);
                    lor();
                    break;
//                    nextWindow();//прожали play перешли на другую страницу меню
                }
                 // вызов первого лора
//                break;
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
    lor_sprites[1]->setPosition(0, 0);
    lor_sprites[0]->setPosition(-700, 300);

    Clock clock;

    float x = -300;
    float y = 700;

    while (window->isOpen()) {
        if(y >= 0) {
            clock.restart();
            auto t = clock.getElapsedTime().asSeconds();
            y = y - 1000000*t;
            lor_sprites[0]->setPosition(x, y);
            clock.restart();
        }

        window->draw(*lor_sprites[1]);
        window->draw(*lor_sprites[0]);

        if (y <= 0)
            window->draw(*tab_text);

        window->display();
        window->clear();

        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
                lor1();
            else if (event.type == Event::Closed)
                window->close();
        }
    }
}

void StartingMenu::lor1() {
    lor_sprites[3]->setPosition(0, 0);
    lor_sprites[2]->setPosition(300, 300);

    Clock clock;

    float x = -100;
    float y = 500;

    while (window->isOpen()) {

        if (y >= 0) {
            clock.restart();
            auto t = clock.getElapsedTime().asSeconds();
            y = y - 1000000* t;
            lor_sprites[2]->setPosition(x, y);
            clock.restart();
        }

        window->draw(*lor_sprites[3]);
        window->draw(*lor_sprites[2]);

        if (y <= 0)
            window->draw(*tab_text);


        window->display();

        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
                lor3();
            else if (event.type == Event::Closed)
                window->close();
        }
    }
}

void StartingMenu::lor3() {
    lor_sprites[5]->setPosition(0, 0);
    lor_sprites[4]->setPosition(300, 300);

    Clock clock;

    float x = 400;
    float y = 300;


    while (window->isOpen()) {

        if (y >= 0) {
            clock.restart();
            auto t = clock.getElapsedTime().asSeconds();
            y = y - 1000000*t;
            lor_sprites[4]->setPosition(x, y);
            clock.restart();
        }

        window->draw(*lor_sprites[5]);
        window->draw(*lor_sprites[4]);

        if (y <= 0)
            window->draw(*tab_text);


        window->display();
        window->clear();

        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab) {
                Game::getInstance()->getAEng()->setFadeFlag(MAINMENU);
                nextWindow();
            }
            else if (event.type == Event::Closed)
                window->close();
        }
    }
}
