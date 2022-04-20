#ifndef ALIEN_MONSTER_H
#define ALIEN_MONSTER_H

#include "Creature.h"
using std::vector;

struct Tiles {
    int x;
    int y;
    int width;
    int height;
};

class Monster : public Creature {
protected:
    vector<Tiles> move_vec;
    vector<Tiles> attack_vec;
    vector<Tiles> fall_vec;

    const float g_accel = 1000;
    const float FRAME_RATIO_1 = 9;
    const float COOLDOWN = 2;
    bool is_firing;
    float red_cooldown = 0;
    int direction;

    float distance_to_hero;
    bool on_ground;

public:
     bool is_red;
    Monster(float sp_x, float x0, int wind_w, int wind_h, double health, float cd);

    void move() override;
    bool attack();

    void setDistanceToHero(float hero_pos);

    float getPositionX();
    float getPositionY();
    int getDirection() const;
};



#endif //ALIEN_MONSTER_H