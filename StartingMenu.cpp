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

    timer = make_unique<Clock>();
    timer->restart();

    lor_x[0] = -300;
    lor_y[0] = 700;
    lor_x[1] = -100;
    lor_y[1] = 500;
    lor_x[2] = 400;
    lor_y[2] = 300;

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
                    lorn(1);
                    lorn(2);
                    lorn(3);
                    Game::getInstance()->getAEng()->setFadeFlag(MAINMENU);
                    nextWindow();
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

void StartingMenu::lorn(unsigned n) {
    timer->restart();
    auto i1 = 2 * n - 2; //0
    auto i2 = 2 * n - 1; //1
    lor_sprites[i2]->setPosition(0, 0);
    lor_sprites[i1]->setPosition(-700, 300);

    float x = lor_x[n-1];
    float y = lor_y[n-1];

    while (window->isOpen()) {
        if (y >= 0) {
            auto t = timer->getElapsedTime().asSeconds();
            y = y - LOR_SPEED * t;
            lor_sprites[i1]->setPosition(x, y);
            timer->restart();
        }

        window->draw(*lor_sprites[i2]);
        window->draw(*lor_sprites[i1]);

        if (y <= 0)
            window->draw(*tab_text);

        window->display();
        window->clear();

        Event event;
        while (window->pollEvent(event)) {
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
                return;
            else if (event.type == Event::Closed)
                window->close();
        }
    }
}
