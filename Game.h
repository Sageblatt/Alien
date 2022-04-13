//
// Created by sageblatt on 12.04.2022.
//

#ifndef ALIEN_GAME_H
#define ALIEN_GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include <thread>

class StartingMenu;
class MainMenu;
class GameMenu;
class RandomNumberGenerator;
class AudioEngine;

class Game {
private:
    StartingMenu* starting_menu;
    MainMenu* main_menu;
    GameMenu* game_menu;
    RandomNumberGenerator* rng;
    AudioEngine* a_eng;

    std::shared_ptr<sf::RenderWindow> window;
    std::unique_ptr<sf::Texture> load_texture;
    std::unique_ptr<sf::Sprite> load_sprite;

    Game();
    static Game* instance;
public:
    static Game* getInstance();

    MainMenu* getMainMenu() const;
    StartingMenu* getStartingMenu() const;
    GameMenu* getGameMenu() const;
    RandomNumberGenerator* getRng() const;
    AudioEngine* getAEng() const;

    const std::shared_ptr<sf::RenderWindow>& getWindow() const;

    void init();
    void runGame();

    static void deleteGame();

    ~Game();
};


#endif //ALIEN_GAME_H
