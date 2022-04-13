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

    int   directionMove{}; //����������� �������� �������

    float time{};
    float timeBoost{};
    

    int WindowWidth{};
    int WindowHeight{};

    float CurrentFrame{};//������ ������� ����
    float CurrentFrame2{};

    String  file{};         //���� � �����������
    Image   image{};        //sfml �����������
    Texture texture{};      //sfml ��������
    Sprite  sprite{};       //sfml ������

    //double   hp;
    //unsigned strength;

    //std::vector <sf::Sprite> sprites;

public:

    virtual void Move() = 0;

    void SetTime(float time);
    float GetTime();

    void Draw(RenderWindow& window);
    virtual void IncrementTime() = 0;

    //Creature();
	//virtual ~Creature()  = 0;

};

#endif //ALIEN_CREATURE_H