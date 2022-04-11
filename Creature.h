#ifndef ALIEN_CREATURE_H
#define ALIEN_CREATURE_H

#include <SFML/Graphics.hpp>
using namespace sf;


class Creature
{
protected:

    int Width{};
    int Height{};  // ширина, высота
    float SpeedX{};
    float SpeedY{}; //скорости по x, y
    int   directionMove{};//направление движения игрока


    String  file;         //файл с расширением
    Image   image;        //sfml изображение
    Texture texture;      //sfml текстура
    Sprite  sprite;       //sfml спрайт

    //double   hp;
    //unsigned strength;

    //std::vector <sf::Sprite> sprites;
    virtual void Move() = 0;


public:
    
    Creature();
	//virtual ~Creature()  = 0;

};

#endif //ALIEN_CREATURE_H