#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <cstddef>

class Player {
private:
    size_t x_;
    size_t y_;

public:
    Player();
    void SetPosition(size_t x, size_t y);
    void Move(int dx, int dy);

    size_t x() const { return x_; }
    size_t y() const { return y_; }
};

#endif