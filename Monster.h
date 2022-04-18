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

    int attack_tact;

    const float g_accel = 1000;
    const float FRAME_RATIO_1 = 9;

    float distance_to_hero;
    bool on_ground;

public:
    Monster(float sp_x, float x0, int wind_w, int wind_h, double health);

    void move() override;
    void attack();

    void setDistanceToHero(float hero_pos);
};



#endif //ALIEN_MONSTER_H