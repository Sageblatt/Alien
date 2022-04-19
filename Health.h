//
// Created by sageblatt on 19.04.2022.
//
#ifndef ALIEN__HEALTH_H_
#define ALIEN__HEALTH_H_

#include <SFML/Graphics.hpp>
#include <memory>

using std::vector;
using namespace sf;

class Table {
protected:
    std::unique_ptr<Texture> texture_tab;
    std::unique_ptr<Sprite>  sprite_tab;

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
    std::unique_ptr<Texture> texture_heart;
    std::unique_ptr<Sprite>  sprite_heart;

    vector<TilesHeart> heart_vec;

    int count;

public:
    explicit Health(int i);

    void hurt(double hp, double maxHp);

    void draw(RenderWindow& window);
};

#endif //ALIEN__HEALTH_H_
