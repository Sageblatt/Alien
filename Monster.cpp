#include "Monster.h"

Monster::Monster(float sp_x, float x0, int wind_w, int wind_h, double health) {
    attack_tact = 0;
    distance_to_hero = 0;

    hp = health;

    move_vec.push_back({0, 524, 65, 60 });
    move_vec.push_back({78, 528, 65, 60 });

    attack_vec.push_back({0, 0, 83, 59 });
    attack_vec.push_back({0, 315, 83, 60 });
    attack_vec.push_back({0, 455, 83, 60 });
    attack_vec.push_back({82, 455, 83, 60 });
    attack_vec.push_back({0, 455, 83, 60 });
    attack_vec.push_back({0, 315, 83, 60 });
    attack_vec.push_back({0, 0, 83, 59 });

    fall_vec.push_back({0, 139, 65, 65 });

    window_width = wind_w;
    window_height = wind_h;

    x = x0;

    y = 0;

    speed_x = sp_x;

    on_ground = false;

    texture.loadFromFile("../images/ALIEN.png");
    sprite.setTexture(texture);

    sprite.setPosition(x, y);

    current_frame = 0;
    current_frame_2 = 0;

    boost = 10;
    time_boost_1 = 0;
}

void Monster::incrementTime() {
    time_boost_1 += time / 1000;
}

void Monster::move() {
    if (!on_ground) {
        current_frame += 0.01f * time;

        if (current_frame > 10)
            current_frame = 0;

        on_ground = false;
        incrementTime();
        sprite.setTextureRect(IntRect(fall_vec[0].x,
                                      fall_vec[0].y,
                                      fall_vec[0].width,
                                      fall_vec[0].height));
        sprite.move(0, boost * time_boost_1 * time_boost_1 / 2);
    }

    if (sprite.getPosition().y >= (window_height - fall_vec[0].height))
        on_ground = true;

    if (on_ground)
        return;
}

void Monster::attack() {
    if (current_frame >= 5) {
        current_frame = 0;
        attack_tact = 0;
    }

    if (on_ground && std::abs(distance_to_hero) <= 300) {
        if (distance_to_hero >= 0) {
            while (attack_tact < 250) {
                sprite.setTextureRect(IntRect(attack_vec[0].x,
                                              attack_vec[0].y,
                                              attack_vec[0].width,
                                              attack_vec[0].height));
                attack_tact++;
                sprite.move(0, 0);
                return;
            }

            sprite.setTextureRect(IntRect(attack_vec[(int)current_frame].x,
                                          attack_vec[(int)current_frame].y,
                                          attack_vec[(int)current_frame].width,
                                          attack_vec[(int)current_frame].height));
            sprite.move(0, 0);
            current_frame += (float)(time) / 100;
        } else {
            while (attack_tact < 250)
            {
                sprite.setTextureRect(IntRect(478 - attack_vec[0].x - attack_vec[0].width,
                                              attack_vec[0].y,
                                              attack_vec[0].width,
                                              attack_vec[0].height));
                attack_tact++;
                sprite.move(0, 0);
                return;
            }

            sprite.setTextureRect(IntRect(478 - attack_vec[(int)current_frame].x - attack_vec[(int)current_frame].width,
                                          attack_vec[(int)current_frame].y,
                                          attack_vec[(int)current_frame].width,
                                          attack_vec[(int)current_frame].height));
            sprite.move(0, 0);
            current_frame += (float)(time) / 100;
        }
    }

    if (on_ground && distance_to_hero > 300) {
        current_frame += (float)(time) / 110;
        int j = (int)(current_frame / 3);
        sprite.setTextureRect(IntRect(move_vec[j].x, move_vec[j].y, move_vec[j].width, move_vec[j].height));
        sprite.move(speed_x / 50 * time, 0);
    }

    if (on_ground && distance_to_hero < -300) {
        current_frame += (float)(time) / 110;
        int j = (int)(current_frame / 3);
        sprite.setTextureRect(IntRect(478 - move_vec[j].x - move_vec[j].width, move_vec[j].y, move_vec[j].width, move_vec[j].height));
        sprite.move(-speed_x / 50 * time, 0);
    }
}
