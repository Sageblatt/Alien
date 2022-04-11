#ifndef ALIEN_CREATURE_H
#define ALIEN_CREATURE_H

#include <SFML/Graphics.hpp>
using namespace sf;


class Creature
{
protected:

    int Width{};
    int Height{};  // ������, ������
    float SpeedX{};
    float SpeedY{}; //�������� �� x, y
    int   directionMove{};//����������� �������� ������


    String  file;         //���� � �����������
    Image   image;        //sfml �����������
    Texture texture;      //sfml ��������
    Sprite  sprite;       //sfml ������

    //double   hp;
    //unsigned strength;

    //std::vector <sf::Sprite> sprites;
    virtual void Move() = 0;


public:
    
    Creature();
	//virtual ~Creature()  = 0;

};

#endif //ALIEN_CREATURE_H