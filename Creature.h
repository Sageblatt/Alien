#ifndef ALIEN_CREATURE_H
#define ALIEN_CREATURE_H

#include <SFML/Graphics.hpp>
using namespace sf;


class Creature {
protected:
    std::unique_ptr<Clock> timer;

    int width;
    int height;  // ширина, высота
    float speed_x;
    float speed_y; //скорости по x, y

    double time;
    float dt;

    float x;
    float y;
    double hp;

    int window_width;
    int window_height;

    float current_frame; //хранит текущий кадр
    float current_frame_2;

    Texture texture; //sfml текстура
    Sprite  sprite;

public:
    virtual void move() = 0;

    void savePosition();
    void setTime(float t);
    void setSpriteColor(Color c);
    void receiveDamage(double damage);

    float getTime() const;
    virtual FloatRect getRect();
    float getPositionX() const;
    float getPositionY() const;
    double getHp() const;

    void draw(RenderWindow& window) const;
};

#endif //ALIEN_CREATURE_H
