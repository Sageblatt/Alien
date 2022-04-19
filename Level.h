//
// Created by sageblatt on 15.04.2022.
//

#ifndef ALIEN_LEVEL_H
#define ALIEN_LEVEL_H

#include "Menu.h"
#include "Player.h"
#include "Monster.h"
#include "Bullet.h"
#include "Health.h"
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
    std::unique_ptr<Font> font;
    std::unique_ptr<Text> wave_text;
    std::unique_ptr<Clock> wave_timer;

    std::unique_ptr<Table> tablice;
    vector<std::unique_ptr<Health>> hearts;

    std::vector<double> waves;
    double last_wave = 40;

    bool is_win;
    bool is_lose;
    std::unique_ptr<Text> win_text;
    std::unique_ptr<Text> lose_text;

    std::unique_ptr<Player> hero;
    std::list<std::unique_ptr<Monster>> monsters;
    std::list<std::unique_ptr<Bullet>> bullets;

    const double BULLET_SPEED = 500;

public:
    Level(std::shared_ptr<RenderWindow> wind, Planets num);

    int run() override;
    void spawnMonsters(unsigned wave);
};


#endif //ALIEN_LEVEL_H
