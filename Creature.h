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

    int   directionMove{}; //направление движения спрайта

    float time{};
    float timeBoost{};
    int X{};
    int Y{};

    int WindowWidth{};
    int WindowHeight{};

    float CurrentFrame{};//хранит текущий кадр
    float CurrentFrame2{};

    String  file{};         //файл с расширением
    Image   image{};        //sfml изображение
    Texture texture{};      //sfml текстура
    Sprite  sprite{};       //sfml спрайт

    //unsigned strength;

    //std::vector <sf::Sprite> sprites;

public:
    int   hp;
    virtual void Move() = 0;
    virtual void Attack() = 0;
    void SavePosition();
    void SetTime(float time);
    float GetTime();

    int GetPositionX();
    int GetPositionY();

    void Draw(RenderWindow& window);
    virtual void IncrementTime() = 0;

    //Creature();
    //virtual ~Creature()  = 0;

};

#endif //ALIEN_CREATURE_H