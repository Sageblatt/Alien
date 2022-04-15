cmake_minimum_required(VERSION 3.21)
project(Alien)

set(CMAKE_CXX_STANDARD 17)

add_executable(Alien
        Creature.cpp
        Player.cpp
        main.cpp
        Monster.cpp)

include_directories(./images)

find_package(SFML 2.5 COMPONENTS graphics audio window system REQUIRED)

target_link_libraries(Alien sfml-graphics sfml-window sfml-system sfml-audio)