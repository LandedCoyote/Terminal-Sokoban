#ifndef PLAYER_HPP
#define PLAYER_HPP

class Player {
private:
    int x, y;
public:
    Player() { x = 1; y = 1; }
    void move(int dx, int dy);
    int getX();
    int getY();
};

#endif