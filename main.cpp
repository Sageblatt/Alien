#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Newmenu.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1376, 768), "alien");
    StartingMenu m;
    m.run(window);
//  while (window.isOpen()) {
//
//        sf::Event event;
//       while (window.pollEvent(event)) {
//           if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        //window.draw(shape);
//      window.display();
//     return 0;
//    }

}
