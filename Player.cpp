#include "Player.h"

Player::Player(float sp_x, float sp_y, int wind_w, int wind_h, double health): JUMP_SPEED(sp_y) {
    timer = std::make_unique<Clock>();
    timer->restart();
    dt = 0;

    hp = health;

    direction_move = STOP;

    window_width = wind_w;
    window_height = wind_h;

    width = 100;
    height = 100;

    speed_x = sp_x;
    speed_y = 0;

    onGround = true;

    texture.loadFromFile("../images/astronaut.png");
    sprite.setTexture(texture);             
    sprite.setPosition((float)(window_width / 2.0), (float)(window_height - height));

    current_frame = 0;
    current_frame_2 = 0;
}

void Player::move() {
    dt = timer->getElapsedTime().asSeconds();
    timer->restart();

    current_frame += FRAME_RATIO * dt;
    if (current_frame > 10)
        current_frame = 0;

    switch (direction_move)
    {
        case STOP: // Stop, 0; +
            sprite.setTextureRect(IntRect(width * 4,
                                          height,
                                          width,
                                          height));
            current_frame_2 = 0;
            return;

        case GO_RIGHT: // Right, 1; +
            sprite.setTextureRect(IntRect(width * int(current_frame),
                                          0,
                                          width,
                                          height));

            if (sprite.getPosition().x <= (float)(window_width - width))
                sprite.move(speed_x * dt, 0);

            current_frame_2 = 0;
            return;

        case SEE_RIGHT: // No move to Right, 2; +
            if (current_frame_2 <= 4)
              current_frame_2 += FRAME_RATIO * dt;

            sprite.setTextureRect(IntRect(width * int(current_frame_2),
                                          height,
                                          width,
                                          height));
            return;

        case JUMP_SEE_RIGHT: // Up, to See to Right, 3; +
            if (-speed_y + g_accel * dt < 0) {
                sprite.setTextureRect(IntRect(900,
                                              0,
                                              width,
                                              height));
                sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);
                current_frame_2 = 0;
                speed_y = speed_y - g_accel * dt;
                return;
            }
            else if (sprite.getPosition().y < (float)(window_height - height) and -speed_y + g_accel * dt > 0) {
                sprite.setTextureRect(IntRect(0, 0, width, height));
                sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);
                current_frame_2 = 0;
                speed_y = speed_y - g_accel * dt;
                return;
            }
            direction_move = SEE_RIGHT;
            speed_y = 0;
            return;

        case JUMP_RIGHT: // Up to Right, 4; +
            if (-speed_y + g_accel * dt < 0) {
                sprite.setTextureRect(IntRect(900,
                                              0,
                                              width,
                                              height));

                if (sprite.getPosition().x <= (float) (window_width - width))
                    sprite.move(speed_x * dt, -speed_y * dt + g_accel * dt * dt / 2);
                else
                    sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);

                current_frame_2 = 0;
                speed_y = speed_y - g_accel * dt;
                return;
            } else if (sprite.getPosition().y < (float)(window_height - height)
                    and -speed_y + g_accel * dt > 0) {
                sprite.setTextureRect(IntRect(0,
                                              0,
                                              width,
                                              height));

                if (sprite.getPosition().x <= (float)(window_width - width))
                    sprite.move(speed_x * dt, -speed_y * dt + g_accel * dt * dt / 2);
                else
                    sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);

                current_frame_2 = 0;
                speed_y = speed_y - g_accel * dt;
                return;
            }
            direction_move = SEE_RIGHT;
            speed_y = 0;
            return;

        case FIRE_RIGHT: // Shout to Right, 5; +
            sprite.setTextureRect(IntRect(width * (int)(current_frame),
                                          height * 2,
                                          width,
                                          height));

            if (Keyboard::isKeyPressed(Keyboard::Right) && onGround) {
                if (sprite.getPosition().x <= (float)(window_width - width))
                    sprite.move(speed_x * dt, 0);
            } else if (Keyboard::isKeyPressed(Keyboard::Up) || !onGround) {
                if (-speed_y + g_accel * dt < 0) {
                    onGround = false;
                    sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);
                    current_frame_2 = 0;
                    return;
                }

                if (sprite.getPosition().y < (float)(window_height - height)) {
                    sprite.move(0, g_accel * dt * dt / 2);
                    current_frame_2 = 0;
                    return;
                }
                onGround = true;
            }
            current_frame_2 = 0;
            return;

        case GO_LEFT: // Left, -1; +
            sprite.setTextureRect(IntRect(900 - width * int(current_frame),
                                          height * 3,
                                          width,
                                          height));

            if (sprite.getPosition().x >= 0)
                sprite.move(-speed_x * dt, 0);

            current_frame_2 = 0;
            return;

        case SEE_LEFT: // No move to Left, -2; +
            if (current_frame_2 <= 4)
                current_frame_2 += FRAME_RATIO * dt;

            sprite.setTextureRect(IntRect(900 - width * int(current_frame_2),
                                          height,
                                          width,
                                          height));
            return;

        case JUMP_SEE_LEFT: // Up, to See to Left, -3; +
            if (-speed_y + g_accel * dt < 0) {
                sprite.setTextureRect(IntRect(0,
                                              height * 3,
                                              width,
                                              height));
                sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);
                current_frame_2 = 0;
                speed_y = speed_y - g_accel * dt;
                return;
            } else if (sprite.getPosition().y < (float)(window_height - height)
                    and -speed_y + g_accel * dt > 0) {
                sprite.setTextureRect(IntRect(900,
                                              height * 3,
                                              width,
                                              height));
                sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);
                current_frame_2 = 0;
                speed_y = speed_y - g_accel * dt;
                return;
            }
            direction_move = SEE_LEFT;
            speed_y = 0;
            return;

        case JUMP_LEFT: // Up to Left, -4; +
            if (-speed_y + g_accel * dt < 0) {
                sprite.setTextureRect(IntRect(0,
                                              height * 3,
                                              width,
                                              height));

                if (sprite.getPosition().x >= 0)
                    sprite.move(-speed_x * dt, -speed_y * dt + g_accel * dt * dt / 2);
                else
                    sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);

                current_frame_2 = 0;
                speed_y = speed_y - g_accel * dt;
                return;
            } else if (sprite.getPosition().y < (float)(window_height - height)
                    and -speed_y + g_accel * dt > 0) {
                sprite.setTextureRect(IntRect(900,
                                              height * 3,
                                              width,
                                              height));

                if (sprite.getPosition().x >= 0)
                    sprite.move(-speed_x * dt, -speed_y * dt + g_accel * dt * dt / 2);
                else
                    sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);

                current_frame_2 = 0;
                speed_y = speed_y - g_accel * dt;
                return;
            }
            direction_move = SEE_LEFT;
            speed_y = 0;
            return;

        case FIRE_LEFT: // Shout to Left, -5; +
            sprite.setTextureRect(IntRect(900 - width * (int)(current_frame),
                                          height * 4,
                                          width,
                                          height));
            if (Keyboard::isKeyPressed(Keyboard::Left) && onGround) {
                if (sprite.getPosition().x >= 0)
                    sprite.move(-speed_x * dt, 0);

            } else if (Keyboard::isKeyPressed(Keyboard::Up) || !onGround) {
                if (-speed_y + g_accel * dt < 0) {
                    onGround = false;
                    sprite.move(0, -speed_y * dt + g_accel * dt * dt / 2);
                    current_frame_2 = 0;
                    return;
                }

                if (sprite.getPosition().y < (float)(window_height - height)) {
                    sprite.move(0, g_accel * dt * dt / 2);
                    current_frame_2 = 0;
                    return;
                }
                onGround = true;
            } else {
                current_frame_2 = 0;
                return;
            }
    }
}

bool Player::keyboard() {
    cooldown_left -= dt;
//  FOR TO LEFT
    if (Keyboard::isKeyPressed(Keyboard::Left) && (direction_move == STOP || direction_move == GO_LEFT
            || direction_move == SEE_LEFT || direction_move == SEE_RIGHT)) {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            direction_move = JUMP_LEFT;
            speed_y = JUMP_SPEED;
            return false;
        } else {
            direction_move = GO_LEFT;
            return false;
        }
    } else if (direction_move == GO_LEFT) {
        direction_move = SEE_LEFT;
        return false;
    }

    //  FOR TO RIGHT
    else if (Keyboard::isKeyPressed(Keyboard::Right) && (direction_move == STOP || direction_move == GO_RIGHT
            || direction_move == SEE_RIGHT || direction_move == SEE_LEFT)) {
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            direction_move = JUMP_RIGHT;
            speed_y = JUMP_SPEED;
            return false;
        }
        else {
            direction_move = GO_RIGHT;
            return false;
        }
    } else if (direction_move == GO_RIGHT) {
        direction_move = SEE_RIGHT;
        return false;
    }

    else if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (direction_move == GO_LEFT || direction_move == SEE_LEFT) {
            direction_move = JUMP_SEE_LEFT;
            speed_y = JUMP_SPEED;
            return false;
        }

        if (direction_move == STOP || direction_move == GO_RIGHT || direction_move == SEE_RIGHT) {
            direction_move = JUMP_SEE_RIGHT;
            speed_y = JUMP_SPEED;
            return false;
        }
    }

    //                     ATTACK !!!
    else if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (direction_move == STOP || direction_move == SEE_RIGHT) {
            direction_move = FIRE_RIGHT; // Shout to Right;
        } else if (direction_move == SEE_LEFT) {
            direction_move = FIRE_LEFT; // Shout to Left;
        }
        if (cooldown_left <= 0) {
            cooldown_left = COOLDOWN;
            return true;
        }
        return false;
    } else if (direction_move == FIRE_RIGHT && onGround) {
        direction_move = SEE_RIGHT;
        return false;
    } else if (direction_move == FIRE_LEFT && onGround) {
        direction_move = SEE_LEFT;
        return false;
    }
    return false;
}

Direction Player::getDirectionMove() const {
    return direction_move;
}

float Player::getPositionX() {
    return sprite.getPosition().x;
}

float Player::getPositionY() {
    return sprite.getPosition().y;
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