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
            fname = "../images/electric_planet.png";
            break;
    }

    textures[0]->loadFromFile(fname);
    sprites.emplace_back(std::make_unique<Sprite>(*textures[0]));

    hero = std::make_unique<Player>(200.f, 300, window->getSize().x, window->getSize().y);

    for (auto i = 0; i < 5; i++) {
        monsters.emplace_back(
                std::make_unique<Monster>(2.5,
                                          Game::getInstance()->getRng()->
                                          getRandomInt(0,static_cast<int>(window->getSize().x)),
                                          window->getSize().x, window->getSize().y, 100));
    }
}

int Level::run() {
    Clock clock; //создаем переменную для привязки персонажа ко времени.
    float time;

    while (window->isOpen())
    {
        Event event;
        time = (float)clock.getElapsedTime().asSeconds();

        hero->setTime(time);

        for(auto & it : monsters)
            it->setTime(time);

        clock.restart();

        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
                return 1;
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space) {
                    bullets.emplace_back(std::make_unique<Bullet>(hero->getDirectionMove(),
                                                                  hero->getPositionX(), hero->getPositionY(), 50.0));
                }
            }
        }

        hero->keyboard();
        hero->move();

        for(auto & it : monsters) {
            it->move();
            it->attack();
        }

        for (auto & it : monsters) {
            for (auto &it1: bullets) {
                if (it->getRect().intersects(it1->getRect())) {
                    it->setSpriteColor(Color::Red);
                    it->receiveDamage(it1->getDamage());
                    it1->setLife(false);
                }
            }
        }
         
        for (auto it = bullets.begin(); it != bullets.end();) {
            (*it)->getBulletCoord();

            if (!(*it)->isLife()) {
                auto tmpit = it;
                ++it;
                bullets.erase(tmpit);
            } else {
                it++;
            }
        }

        for (auto it = monsters.begin(); it != monsters.end();) {
            if ((*it)->getHp() <= 0) {
                auto tmpit = it;
                ++it;
                monsters.erase(tmpit);
            } else {it++;
            }
        }

        window->clear();
        window->draw(*sprites[0]);

        hero->draw(*window);
        for(auto & it : monsters)
            it->draw(*window);

        for (auto & bullet : bullets)
            bullet->draw(*window);

        window->display();
    }
    return 0;
}
