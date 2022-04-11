#include "StartingMenu.h"



int main()
{
    auto window = std::make_shared<sf::RenderWindow>(sf::VideoMode(1376, 768), "alien");
    StartingMenu m(window);
    m.run();
}
