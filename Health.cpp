//
// Created by sageblatt on 19.04.2022.
//

#include "Health.h"
#include <iostream>
Table::Table() {
    texture_tab = std::make_unique<Texture>();
    sprite_tab = std::make_unique<Sprite>();

    texture_tab->loadFromFile("../images/tablice.png");
    sprite_tab->setTexture(*texture_tab);
    sprite_tab->setPosition(40, -98);
    sprite_tab->setScale(0.67, 1);
}

void Table::draw(RenderWindow& window) {
    window.draw(*sprite_tab);
}

Health::Health(int i) {
    heart_vec.push_back({0, 232, 1, 215});
    heart_vec.push_back({299, 232, 1, 215});
    heart_vec.push_back({598, 232, 1, 215});
    heart_vec.push_back({897, 232, 1, 215});
    heart_vec.push_back({1196, 232, 1, 215});
    heart_vec.push_back({1494, 232, 1, 215});


    count = i;

    texture_heart = std::make_unique<Texture>();
    sprite_heart = std::make_unique<Sprite>();

    texture_heart->loadFromFile("../images/health.png");
    sprite_heart->setTexture(*texture_heart);

    sprite_heart->setPosition(0.5 * 129 * count + 60, 40);
    sprite_heart->setScale(0.3, 0.3);
}

void Health::draw(RenderWindow& window) {
    window.draw(*sprite_heart);
}

void Health::hurt(double hp_, double maxHp_) {
    auto maxHp = (maxHp_ / 5);
    auto hp = (maxHp_ - hp_);
    while (hp > maxHp){
        hp -= maxHp;
    }
    auto fracHp = maxHp / 5;
    auto i = (int)(hp / fracHp);

    if ((count - 1) * maxHp  > hp_)
        sprite_heart->setTextureRect(IntRect(heart_vec[5].x0,
                                                     heart_vec[5].y0,
                                                     heart_vec[5].lenX,
                                                     heart_vec[5].lenY));
    else if (count * maxHp <= hp_)
        sprite_heart->setTextureRect(IntRect(heart_vec[0].x0,
                                             heart_vec[0].y0,
                                             heart_vec[0].lenX,
                                             heart_vec[0].lenY));
    else if ((count - 1) * maxHp  <= hp_)
        sprite_heart->setTextureRect(IntRect(heart_vec[i].x0,
                                             heart_vec[i].y0,
                                             heart_vec[i].lenX,
                                             heart_vec[i].lenY));
    return;
}