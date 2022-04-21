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
using std::unique_ptr;

enum Planets {
    PURPLE,
    FIRE,
    ELECTRIC
};

struct MonsterParameters{
    float speed;
    double hp;
    double cooldown;
    double damage;
};

class Level: public Menu {
protected:
    unique_ptr<Font> font;
    unique_ptr<Text> wave_text;
    unique_ptr<Clock> wave_timer;

    unique_ptr<Table> tablice;
    std::vector<unique_ptr<Health>> hearts;

    std::vector<double> waves;
    double last_wave = 40;

    bool is_win;
    bool is_lose;
    unique_ptr<Text> win_text;
    unique_ptr<Text> lose_text;

    unique_ptr<Player> hero;
    std::list<unique_ptr<Monster>> monsters;
    std::list<unique_ptr<Bullet>> bullets;

    MonsterParameters monster_parameters;

    const double BULLET_SPEED = 500;

public:
    Level(std::shared_ptr<RenderWindow> wind, Planets num);

    int run() override;
    void spawnMonsters(unsigned wave);
};


#endif //ALIEN_LEVEL_H