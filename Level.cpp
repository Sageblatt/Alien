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

    hero = std::make_unique<Player>("../images/astronaut.png", 0.2f, 5, window->getSize().x, window->getSize().y);

    for (auto i = 0; i < 5; i++) {
        monsters.emplace_back(
                std::make_unique<Monster>("../images/ALIEN.png",
                                          2.5,
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
        time = (float)clock.getElapsedTime().asMicroseconds();

        time /= 800;
      hero->setTime(time);
        for(auto & it : monsters) {
          it->setTime(time);
        }

        clock.restart();
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window->close();
            else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
                return 1;
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Space)
                {

                    bullets.emplace_back(std::make_unique<Bullet>(hero->direction_move,
                                                                  hero->getPositionX(), hero->getPositionY()));
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
                    it->sprite.setColor(Color::Red);
                    it->hp = it->hp - 50;
                    it1->life = false;

                }
            }
        }
         
        for (auto it = bullets.begin(); it != bullets.end();)
        {

            (*it)->getBulletCoord();

            if (!(*it)->life) {
                auto tmpit = it;
                ++it;
                bullets.erase(tmpit);
            }
            else it++;
        }
         for (auto it = monsters.begin(); it != monsters.end();)
        {

            if ((*it)->hp <= 0) {
                auto tmpit = it;
                ++it;
                monsters.erase(tmpit);
            }
            else it++;
        }


        window->clear();

        window->draw(*sprites[0]);
      hero->draw(*window);
        for(auto & it : monsters) {
          it->draw(*window);
        }
        for (auto & bullet : bullets){
            //bullet->draw(*window);
           window->draw(bullet->sprite);
//            std::cout << "!!!!!!";
        }
        
        window->display();
    }
    return 0;
}
