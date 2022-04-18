#include "Player.h"

Player::Player(const String& fname, float sp_x, float sp_y, int wind_w, int wind_h) {
    file = fname;
    direction_move = 0;

    window_width = wind_w;
    window_height = wind_h;

    width = 100;
    height = 100;

    speed_x = sp_x;
    speed_y = sp_y;

    onGround = true;

    image.loadFromFile(fname);
    texture.loadFromImage(image);   
    sprite.setTexture(texture);             
    sprite.setPosition((float)(window_width / 2.0), (float)(window_height - height));

    current_frame = 0;
    current_frame_2 = 0;

    boost = 22;
    time_boost = 0;
    key = false;
}

void Player::incrementTime() {
    time_boost += time / 3000;
}

void boostTimeToZero(bool& key, float& timeBoost) {
    if (!key) {
        timeBoost = 0;
        key = !key;
    }
}


void Player::move() {
    current_frame += 0.01f * time;
    if (current_frame > 10)
        current_frame = 0;

    switch (direction_move)
    {
        case 0: // Stop, 0; +++
            sprite.setTextureRect(IntRect(width * 4, height, width, height));
            sprite.move(0, 0);
            current_frame_2 = 0;
            return;

        case 1: // Right, 1;
            sprite.setTextureRect(IntRect(width * int(current_frame), 0, width, height));
            if(sprite.getPosition().x <= (float)(window_width - width))
                sprite.move(speed_x * time, 0);

            else sprite.move(0 * time, 0);
                current_frame_2 = 0;
            return;

        case 2: // No move to Right, 2;
            if (current_frame_2 <= 4)
              current_frame_2 += (float)(0.015 * time);

            sprite.setTextureRect(IntRect(width * int(current_frame_2), height, width, height));
            sprite.move(0, 0);
            return;

        case 3: // Up, to See to Right, 3;
            if (-speed_y + boost * time_boost < 0 && !key) {
                incrementTime();
                sprite.setTextureRect(IntRect(900, 0, width, height));
                sprite.move(0, -speed_y * time_boost + boost * time_boost * time_boost / 2);
                current_frame_2 = 0;
                return;
            }

            boostTimeToZero(key, time_boost);

            if (key && sprite.getPosition().y < window_height - height) {
                incrementTime();
                sprite.setTextureRect(IntRect(0, 0, width, height));
                sprite.move(0, boost * time_boost * time_boost / 2);
                current_frame_2 = 0;
                return;
            }

            time_boost = 0;
            key = false;
            direction_move = 2;
            return;

        case 4: // Up to Right, 4;
            if (-speed_y + boost * time_boost < 0 && !key) {
                incrementTime();
                sprite.setTextureRect(IntRect(900, 0, width, height));

                if (sprite.getPosition().x <= (float)(window_width - width))
                    sprite.move(speed_x * time, -speed_y * time_boost + boost * time_boost * time_boost / 2);

                else
                    sprite.move(0 * time, -speed_y * time_boost + boost * time_boost * time_boost / 2);

                current_frame_2 = 0;
                return;
            }

            boostTimeToZero(key, time_boost);

            if (key && sprite.getPosition().y < window_height - height) {
                incrementTime();

                sprite.setTextureRect(IntRect(0, 0, width, height));
                if (sprite.getPosition().x <= (float)(window_width - width))
                    sprite.move(speed_x * time, boost * time_boost * time_boost / 2);
                else
                    sprite.move(0 * time, boost * time_boost * time_boost / 2);
                current_frame_2 = 0;
                return;
            }
            time_boost = 0;
            key = false;
            direction_move = 2;
            return;

        case 5: // Shout to Right, 5;
            sprite.setTextureRect(IntRect(width * (int)(current_frame), height * 2, width, height));

            if (Keyboard::isKeyPressed(Keyboard::Right) && onGround) {
                if (sprite.getPosition().x <= window_width - width)
                    sprite.move(speed_x * time, 0);
                else
                    sprite.move(0 * time, 0);
            } else if (Keyboard::isKeyPressed(Keyboard::Up) || !onGround) {
                if (-speed_y + boost * time_boost < 0 && key == false) {
                    onGround = false;
                    incrementTime();
                    sprite.move(0, -speed_y * time_boost + boost * time_boost * time_boost / 2);
                    current_frame_2 = 0;
                    return;
                }

                boostTimeToZero(key, time_boost);

                if (key && sprite.getPosition().y < window_height - height) {
                    incrementTime();
                    sprite.move(0, boost * time_boost * time_boost / 2);
                    current_frame_2 = 0;
                    return;
                }
                onGround = true;
                time_boost = 0;
                key = false;
            } else
                sprite.move(0, 0);
            time_boost = 0;
            current_frame_2 = 0;
            return;


        case -1: // Left, -1;
            sprite.setTextureRect(IntRect(900 - width * int(current_frame), height * 3, width, height));

            if(sprite.getPosition().x >= 0)
                sprite.move(-speed_x * time, 0);

            else
                sprite.move(0 * time, 0);
            current_frame_2 = 0;
            return;

        case -2: // No move to Left, -2;
            if (current_frame_2 <= 4)
              current_frame_2 += (float)(0.015 * time);

            sprite.setTextureRect(IntRect(900 - width * int(current_frame_2), height, width, height));
            sprite.move(0, 0);
            return;

        case -3: // Up, to See to Left, -3;
            if (-speed_y + boost * time_boost < 0 && !key) {
                incrementTime();
                sprite.setTextureRect(IntRect(0, height * 3, width, height));
                sprite.move(0 * time, -speed_y * time_boost + boost * time_boost * time_boost / 2);
                current_frame_2 = 0;
                return;
            }

            boostTimeToZero(key, time_boost);

            if (key && sprite.getPosition().y < window_height - height) {
                incrementTime();
                sprite.setTextureRect(IntRect(900, height * 3, width, height));
                sprite.move(0 * time, boost * time_boost * time_boost / 2);
                 current_frame_2 = 0;
                return;
            }
            time_boost = 0;
            key = false;
            direction_move = -2;
            return;

        case -4: // Up to Left, -4;
            if (-speed_y + boost * time_boost < 0 && !key) {
                incrementTime();
                sprite.setTextureRect(IntRect(0, height * 3, width, height));

                if (sprite.getPosition().x >= 0)
                    sprite.move(-speed_x * time, -speed_y * time_boost + boost * time_boost * time_boost / 2);
                else
                    sprite.move(0 * time, -speed_y * time_boost + boost * time_boost * time_boost / 2);
                current_frame_2 = 0;
                return;
            }
            boostTimeToZero(key, time_boost);

            if (key && sprite.getPosition().y < window_height - height) {
                incrementTime();
                sprite.setTextureRect(IntRect(900, height * 3, width, height));
                if (sprite.getPosition().x >= 0)
                    sprite.move(-speed_x * time, boost * time_boost * time_boost / 2);
                else
                    sprite.move(0 * time, boost * time_boost * time_boost / 2);
                current_frame_2 = 0;
                return;
            }
            time_boost = 0;
            key = false;
            direction_move = -2;
            return;

        case -5: // Shout to Left, -5;
            sprite.setTextureRect(IntRect(900 - width * (int)(current_frame), height * 4, width, height));
            if (Keyboard::isKeyPressed(Keyboard::Left) && onGround) {
                if (sprite.getPosition().x >= 0)
                    sprite.move(-speed_x * time, 0);
                else
                    sprite.move(-0 * time, 0);
            } else if (Keyboard::isKeyPressed(Keyboard::Up) || !onGround) {
                if (-speed_y + boost * time_boost < 0 && key == false) {
                    onGround = false;
                    incrementTime();
                    sprite.move(0, -speed_y * time_boost + boost * time_boost * time_boost / 2);
                    current_frame_2 = 0;
                    return;
                }

                boostTimeToZero(key, time_boost);

                if (key && sprite.getPosition().y < window_height - height) {
                    incrementTime();
                    sprite.move(0, boost * time_boost * time_boost / 2);
                    current_frame_2 = 0;
                    return;
                }
                onGround = true;
                time_boost = 0;
                key = false;
            } else {
                sprite.move(0, 0);
                time_boost = 0;
                current_frame_2 = 0;
                return;
            }
    }
}

// What is direction_move?

// direction_move = ...
// 0 - Stop (to Right)  
//              
// 1 - Go to Right
// 2 - Stay and see to Right
// 3 - Jump and see to right 
// 4 - Jump to Right 
// 
// 5 - Shout to Right
// 6 - Up and Shout to Right
// 7 - Go to back and Shout to Right
// 
// -1 - Go to Left
// -2 - Stay and see to Left
// -3 - Jump and see to left 
// -4 - Jump to Left
// 
// -5 - Shout to Left
// -6 - Go to Back and Shout to Left
//  - Up and Shout to Left


void Player::keyboard() {
//  FOR TO LEFT
    if (Keyboard::isKeyPressed(Keyboard::Left) && (direction_move == 0 || direction_move == -1 || direction_move == -2 || direction_move == 2)) {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            direction_move = -4;
            return;
        } else {
            direction_move = -1;
            return;
        }
    } else if (direction_move == -1) {
        direction_move = -2;
        return;
    }

    //  FOR TO RIGHT

    else if (Keyboard::isKeyPressed(Keyboard::Right) && (direction_move == 0 || direction_move == 1 || direction_move == 2 || direction_move == -2))
    {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            direction_move = 4;
            return;
        }
        else {
            direction_move = 1;
            return;
        }
    } else if (direction_move == 1) {
        direction_move = 2;
        return;
    }

    else if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (direction_move == -1 || direction_move == -2) {
            direction_move = -3;
            return;
        }

        if (direction_move == 0 || direction_move == 1 || direction_move == 2) {
            direction_move = 3;
            return;
        }
    }
    //                     ATTACK !!!

    else if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (direction_move == 0 || direction_move == 2 ) {
            direction_move = 5; // Shout to Right;
            return; 
        } else if (direction_move == -2 ) {
            direction_move = -5; // Shout to Left;
            return;
        }
    } else if (direction_move == 5 && onGround) {
        direction_move = 2;
        return;
    } else if (direction_move == -5 && onGround) {
        direction_move = -2;
        return;
    }
}

int Player::getDirectionMove() {
    return direction_move;
}

float Player::getPositionX() {
    return sprite.getPosition().x;
}

float Player::getPositionY() {
    return sprite.getPosition().y;
}
