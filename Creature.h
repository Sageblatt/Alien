#ifndef ALIEN_CREATURE_H
#define ALIEN_CREATURE_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Creature {
protected:
    int Width;
    int Height;  // ширина, высота
    float SpeedX;
    float SpeedY; //скорости по x, y

    int directionMove; //направление движения спрайта

    float time;
    float timeBoost;

    int WindowWidth;
    int WindowHeight;

    float CurrentFrame;//хранит текущий кадр
    float CurrentFrame2;

    String  file;         //файл с расширением
    Image   image;        //sfml изображение
    Texture texture;      //sfml текстура
    Sprite  sprite;       //sfml спрайт

public:
    virtual void Move() = 0;
    virtual void Attack() = 0;

    void SetTime(float t);
    float GetTime();

    void Draw(RenderWindow& window);
    virtual void IncrementTime() = 0;
};

#endif //ALIEN_CREATURE_H