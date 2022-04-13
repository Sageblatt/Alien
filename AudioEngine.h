//
// Created by sageblatt on 13.04.2022.
//

#ifndef ALIEN_AUDIOENGINE_H
#define ALIEN_AUDIOENGINE_H

#include <SFML/Audio.hpp>
#include <array>
#include "Game.h"

enum Songs {
    STARTINGMENU,
    MAINMENU,
    LOR
};

class AudioEngine {
private:
    std::array<std::unique_ptr<sf::SoundBuffer>, 3> sound_bufs;
    static const unsigned short TRACKS_AMOUNT = 3;
    std::array<std::unique_ptr<sf::Music>, TRACKS_AMOUNT> tracks;

    Songs current_track;

    std::pair<bool, Songs> fade_flag;
    const float FADE_LEN = 1;
    std::unique_ptr<sf::Clock> timer;

    void fade(Songs next_song);

public:
    AudioEngine();

    void run();

    void setFadeFlag(Songs number_of_track);
};


#endif //ALIEN_AUDIOENGINE_H
