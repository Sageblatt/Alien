//
// Created by sageblatt on 12.04.2022.
//
#ifndef ALIEN_GAME_H
#define ALIEN_GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <thread>

#include "StartingMenu.h"
#include "MainMenu.h"
#include "RandomNumberGenerator.h"
#include "AudioEngine.h"
#include "Level.h"

class Game {
private:
    StartingMenu* starting_menu;
    MainMenu* main_menu;
    GameMenu* game_menu;
    RandomNumberGenerator* rng;
    AudioEngine* a_eng;
    std::array<Level*, 3> planets;

    std::shared_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::Texture> load_texture;
    std::unique_ptr<sf::Sprite> load_sprite;

    Game();
    static Game* instance;
public:
    static Game* getInstance();

    [[maybe_unused]] MainMenu* getMainMenu() const;
    [[maybe_unused]] StartingMenu* getStartingMenu() const;
    [[maybe_unused]] GameMenu* getGameMenu() const;
    RandomNumberGenerator* getRng() const;
    [[maybe_unused]] AudioEngine* getAEng() const;

    [[maybe_unused]] const std::shared_ptr<sf::RenderWindow>& getWindow() const;

    void init();
    void runGame();

    static void deleteGame();

    ~Game();
};


#endif //ALIEN_GAME_H
