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
    const float COOLDOWN;

    // NEW
    // begin...
    const float SCALE_X = 1.6;
    const float SCALE_Y = 1.6;
    // ...end;


    bool is_firing;

    int direction;

    float distance_to_hero;
    bool on_ground;

public:
    Monster(float sp_x, float x0, int wind_w, int wind_h, double health, float cooldown);
    void move() override;
    bool attack();

    void setDistanceToHero(float hero_pos);

    float getPositionX();
    float getPositionY();
    int getDirection() const;
};



#endif //ALIEN_MONSTER_H