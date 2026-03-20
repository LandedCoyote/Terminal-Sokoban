#include "Map.hpp"
#include "Input.hpp"
#include "Game.hpp"
#include "Player.hpp"

int main() {
    Map game_map;
    Input user_input;
    Game game_logic;
    Player player;

    if (!game_map.LoadLevel("data/level1.txt")) return 1;

    // Mapが読み込んだ初期位置をPlayerに反映
    player.SetPosition(game_map.start_x(), game_map.start_y());

    while (true) {
        game_map.Draw(player);
        user_input.Read();
        game_logic.Update(user_input.lastKey, player, game_map);
    }

    return 0;
}