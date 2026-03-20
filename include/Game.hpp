#ifndef GAME_HPP
#define GAME_HPP

#include "Player.hpp"
#include "Map.hpp"

class Game {
public:
    void Update(char lastKey, Player& player, Map& gameMap);
    bool TryPushBox(size_t x, size_t y, int dx, int dy, Map& game_map);
};

#endif