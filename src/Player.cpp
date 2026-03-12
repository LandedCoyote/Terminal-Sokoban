#include "Player.hpp"

void Player::move(int dx, int dy) {
    x += dx;
    y += dy;
}

int Player::getX() { return x; }
int Player::getY() { return y; }