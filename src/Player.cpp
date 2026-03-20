#include "Player.hpp"

#include <vector>

Player::Player() : x_(0), y_(0) {}

void Player::SetPosition(size_t x, size_t y) {
    // 引数の x と メンバ変数の x_ が明確に分かれるのでミスが減る
    x_ = x;
    y_ = y;
}

void Player::Move(int dx, int dy) {
    // 横移動で座標が負になるのを防止
    if (dx < 0 && static_cast<size_t>(-dx) > x_) {
        x_=0;
    } else {
        x_ += dx;
    }
    // 縦移動で座標が負になるのを防止
    if (dy < 0 && static_cast<size_t>(-dy) > y_) {
        y_=0;
    } else {
        y_ += dy;
    }
}