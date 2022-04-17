cmake_minimum_required(VERSION 3.20)
project(Alien)

set(CMAKE_CXX_STANDARD 17)

add_executable(Alien
        Menu.cpp
        GameMenu.cpp
        Creature.cpp
        Player.cpp
        Monster.cpp
        RandomNumberGenerator.cpp
        StartingMenu.cpp
        MainMenu.cpp
        Game.cpp
        Level.cpp
        Bullet.cpp
        main.cpp)


include_directories(./images)
include_directories(./audio)
include_directories(./fonts)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

target_link_libraries(Alien sfml-graphics sfml-window sfml-system)