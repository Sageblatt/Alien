//
// Created by sageblatt on 12.04.2022.
//
#include "Game.h"
#include "StartingMenu.h"
#include "MainMenu.h"
#include "RandomNumberGenerator.h"
#include "Level.h"

Game* Game::instance = nullptr;

Game* Game::getInstance() {
    if (instance)
        return instance;
    instance = new Game();
    return instance;
}

Game::Game() {
    starting_menu = nullptr;
    main_menu = nullptr;
    game_menu = nullptr;
    rng = nullptr;
}

void Game::init() {
    window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1376, 768), "Alien");
    load_texture = std::make_unique<Texture>();
    load_texture->loadFromFile("../images/loading_screen.png");
    load_sprite = make_unique<Sprite>(*load_texture);

    window->clear();
    window->draw(*load_sprite);
    window->display();

    starting_menu = new StartingMenu(window);
    main_menu = new MainMenu(window);
    game_menu = new GameMenu(window);
    rng = new RandomNumberGenerator();

    planets[PURPLE] = new Level(window, PURPLE);
    planets[FIRE] = new Level(window, FIRE);
    planets[ELECTRIC] = new Level(window, ELECTRIC);
}

void Game::runGame() {
//    starting_menu->run();
//
//    for (auto i = 1; i < 4; i++)
//        starting_menu->lor(i);
//
//    main_menu->run();

    int planet_num;
    planet_num = game_menu->run() - 1;

    while (window->isOpen()) {
        planets[planet_num]->run();
        planet_num = game_menu->run() - 1;
    }


    window->close();
}

MainMenu* Game::getMainMenu() const {
    return main_menu;
}

StartingMenu* Game::getStartingMenu() const {
    return starting_menu;
}

GameMenu *Game::getGameMenu() const {
    return game_menu;
}

RandomNumberGenerator *Game::getRng() const {
    return rng;
}

const std::shared_ptr<sf::RenderWindow> &Game::getWindow() const {
    return window;
}

void Game::deleteGame() {
    delete instance;
    instance = nullptr;
}

Game::~Game() {
    delete starting_menu;
    delete main_menu;
    delete game_menu;
    delete rng;
}




