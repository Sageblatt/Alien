//
// Created by sageblatt on 13.04.2022.
//

#include "AudioEngine.h"

AudioEngine::AudioEngine() {
//    for (auto i = 0; i < TRACKS_AMOUNT; i++)
//         sound_bufs[i] = std::make_unique<sf::SoundBuffer>();
//
//    sound_bufs[0]->loadFromFile("../audio/menu_01.flac");
//    sound_bufs[1]->loadFromFile("../audio/menu_02.flac");
//    sound_bufs[2]->loadFromFile("../audio/fight.flac");

    timer = std::make_unique<sf::Clock>();

    for (auto i = 0; i < TRACKS_AMOUNT; i++)
        tracks[i] = std::make_unique<sf::Music>();

    tracks[0]->openFromFile("../audio/StartingMenu.ogg");
    tracks[1]->openFromFile("../audio/MainMenu.ogg");
    tracks[2]->openFromFile("../audio/Lor.ogg");

    current_track = STARTINGMENU;

    for (auto i = 0; i < TRACKS_AMOUNT; i++) {
        tracks[i]->setLoop(true);
        tracks[i]->setVolume(0);
    }

}

void AudioEngine::fade(Songs next_song) {
    timer->restart();
    tracks[next_song]->setVolume(0);
    auto t = timer->getElapsedTime().asSeconds();

    while (t < FADE_LEN) {
        tracks[current_track]->setVolume(100.f - 100.f * t / FADE_LEN);
        t = timer->getElapsedTime().asSeconds();
    }

    tracks[current_track]->stop();
    current_track = next_song;
    tracks[current_track]->play();

    timer->restart();
    t = timer->getElapsedTime().asSeconds();

    while (t < FADE_LEN)
    {
        tracks[current_track]->setVolume(100.f * t/FADE_LEN);
        t = timer->getElapsedTime().asSeconds();
    }
}

void AudioEngine::run() {
    tracks[current_track]->setVolume(100);
    tracks[current_track]->play();

    while(Game::getInstance()->getWindow()->isOpen()) {
        if (fade_flag.first) {
            fade_flag.first = false;
            fade(fade_flag.second);
        }
    }

    tracks[current_track]->stop();
}

void AudioEngine::setFadeFlag(Songs number_of_track) {
    fade_flag = std::make_pair(true, number_of_track);
}

