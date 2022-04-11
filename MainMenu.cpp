#include "MainMenu.h"

MainMenu::MainMenu(std::shared_ptr<RenderWindow> wind) {
    window = wind;

    //текстуры
    for (auto i = 0; i < 4; i++)
        textures.emplace_back(make_unique<Texture>());

    textures[0]->loadFromFile("../images/CONTINUE.png");
    textures[1]->loadFromFile("../images/EXIT.png");
    textures[2]->loadFromFile("../images/NEW_GAME.png");
    textures[3]->loadFromFile("../images/background_2.png");

    //спрайты
    for (auto i = 0; i < 4; i++)
        sprites.emplace_back(make_unique<Sprite>(*textures[i]));

}

void MainMenu::run() {
    sprites[0]->setPosition(400, 400);
    sprites[1]->setPosition(400, 300);
    sprites[2]->setPosition(400, 500);
    sprites[3]->setPosition(0, 0);

    //номер меню и открыто окно или нет
    bool isMenu = 1;
    int menuNum = 0;

    //вызов окна меню
    while (isMenu and window->isOpen()) {
        sprites[0]->setColor(Color::White);
        menuNum = 0;
        window->clear(Color(129, 181, 221));

        if (IntRect(400, 600, 300, 600).contains(Mouse::getPosition(*window))) {
            sprites[0]->setColor(Color::Red);
            menuNum = 1;
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (menuNum == 1)
                isMenu = false; //если нажали первую кнопку, то выходим из меню
        }


        window->draw(*sprites[3]);
        for (auto i = 0; i < 3; i++)
            window->draw(*sprites[i]);
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

void MainMenu::nextWindow() {}

