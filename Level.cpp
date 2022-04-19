//
// Created by sageblatt on 15.04.2022.
//

#include "Level.h"
#include "Game.h"
#include "RandomNumberGenerator.h"
#include <iostream>

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

    hero = std::make_unique<Player>(400.f,
                                    500,
                                    window->getSize().x,
                                    window->getSize().y,
                                    200);

    for (auto i = 0; i < 1; i++) {
        monsters.emplace_back(
                std::make_unique<Monster>(200,
                                          Game::getInstance()->getRng()->
                                          getRandomInt(0,static_cast<int>(window->getSize().x)),
                                          window->getSize().x, window->getSize().y, 100));
    }
}

int Level::run() {
    hero->resetTimer();
    for (auto & it : monsters)
        it->resetTimer();

    bool hero_shoots;

    while (window->isOpen())
    {
        Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
                return 1;
        }

        hero_shoots = hero->keyboard();

        if (hero_shoots) {
            bullets.emplace_back(std::make_unique<Bullet>(hero->getDirectionMove(),
                                                          hero->getPositionX(),
                                                          hero->getPositionY(),
                                                          50.0, 100, false));
        }
        hero->move();

        for(auto & it : monsters) {
            it->setDistanceToHero(hero->getPositionX());
            it->move();
            auto fire = it->attack();
            if (fire) {
                bullets.emplace_back(std::make_unique<Bullet>(it->getDirection(),
                                                              it->getPositionX(),
                                                              it->getPositionY(),
                                                              50.0, 100, true));
            }
        }

        for (auto & it : monsters) {
            for (auto &it1: bullets) {
                if (it->getRect().intersects(it1->getRect()) and !it1->isForHero()) {
                    //it->setSpriteColor(Color::Red);
                    it->receiveDamage(it1->getDamage());
                    it1->setLife(false);
                }
            }
        }

        for (auto &it1: bullets) {
            if (hero->getRect().intersects(it1->getRect()) and it1->isForHero()) {
                hero->receiveDamage(it1->getDamage());
                it1->setLife(false);
            }
        }
        std::cout << hero->getHp() << std::endl;

        if (hero->getHp() <= 0)
            return 1;
         
        for (auto it = bullets.begin(); it != bullets.end();) {
            (*it)->move();

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
