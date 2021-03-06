//
// Created by sageblatt on 19.04.2022.
//
#ifndef ALIEN__HEALTH_H_
#define ALIEN__HEALTH_H_

#include <SFML/Graphics.hpp>
#include <memory>

using namespace sf;
using std::unique_ptr;

class Table {
protected:
    unique_ptr<Texture> texture_tab;
    unique_ptr<Sprite>  sprite_tab;

public:
    Table();
    void draw(RenderWindow& window);
};

struct TilesHeart {
    int x0;
    int lenX;
    int y0;
    int lenY;
};

class Health {
protected:
    unique_ptr<Texture> texture_heart;
    unique_ptr<Sprite>  sprite_heart;

    std::vector<TilesHeart> heart_vec;

    int count;

public:
    explicit Health(int i);

    void hurt(double hp, double maxHp);

    void draw(RenderWindow& window);
};

#endif //ALIEN__HEALTH_H_
