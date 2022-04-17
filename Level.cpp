//
// Created by sageblatt on 15.04.2022.
//

#include "Level.h"
#include "Game.h"
#include "RandomNumberGenerator.h"

Level::Level(std::shared_ptr<RenderWindow> wind, Planets num) {
    window = wind;

    textures.emplace_back(std::make_unique<Texture>());

    std::string fname;

    switch (num) {
        case PURPLE:
            fname = "../images/pink_planet.png";
            break;
        case FIRE:
            fname = "../images/fire_planet.png";
            break;
        case ELECTRIC:
            fname = "../images/pink_planet.png";
            break;
    }

    textures[0]->loadFromFile(fname);
    sprites.emplace_back(std::make_unique<Sprite>(*textures[0]));

    hero = std::make_unique<Player>("../images/astronaut.png", 0.2f, 5, window->getSize().x, window->getSize().y);

    for (auto i = 0; i < 5; i++) {
        monsters.emplace_back(
                std::make_unique<Monster>("../images/ALIEN_big.png",
                                          2.5,
                                          Game::getInstance()->getRng()->
                                          getRandomInt(0,static_cast<int>(window->getSize().x)),
                                          window->getSize().x, window->getSize().y,2));
    }
}

int Level::run() {
    Clock clock; //создаем переменную для привязки персонажа ко времени.
    float time;

    while (window->isOpen())
    {
        Event event;
        time = (float)clock.getElapsedTime().asMicroseconds();

        time /= 800;
        hero->SetTime(time);
        for(auto & it : monsters) {
            it->SetTime(time);
        }

        clock.restart();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
                return 1;
        }
        hero->SavePosition();
        hero->Keyboard();
        hero->Move();

        for(auto & it : monsters) {
            it->SavePosition();
            it->DistanceToHero(hero->GetPositionX());
            it->Move();
            it->Attack();
        }

        window->clear();

        window->draw(*sprites[0]);
        hero->Draw(*window);
        for(auto & it : monsters) {
            it->Draw(*window);
        }
        window->display();
    }
    return 0;
}
