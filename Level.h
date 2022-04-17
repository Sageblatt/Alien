//
// Created by sageblatt on 15.04.2022.
//

#ifndef ALIEN_LEVEL_H
#define ALIEN_LEVEL_H

#include "Menu.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"
#include <memory>
#include <list>

using namespace sf;

enum Planets {
    PURPLE,
    FIRE,
    ELECTRIC
};

class Level: public Menu {
protected:
    std::unique_ptr<Player> hero;
    std::list<std::unique_ptr<Monster>> monsters;
    std::list<std::unique_ptr<Bullet>> bullets;

public:
    Level(std::shared_ptr<RenderWindow> wind, Planets num);

    int run() override;
};


#endif //ALIEN_LEVEL_H
