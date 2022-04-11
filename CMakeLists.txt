cmake_minimum_required(VERSION 3.21)
project(Alien)

set(CMAKE_CXX_STANDARD 17)

add_executable(Alien
        Menu.cpp
        StartingMenu.cpp
        GameMenu.cpp
        Planet.cpp
        Creature.cpp
        Player.cpp
        Monster.cpp
        Newmenu.cpp
        MainManu.cpp
        main.cpp)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

target_link_libraries(Alien sfml-graphics sfml-window sfml-system sfml-audio)