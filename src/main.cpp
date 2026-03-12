#include "Map.hpp"
#include "Input.hpp"
#include "Game.hpp"
#include "Player.hpp"

int main() {
    Map gameMap;
    Input userInput;
    Game gameUpdate;
    Player player;

    bool running = true;
    while (running) {
        // 1. 描画
        gameMap.draw();

        // 2. 入力待機
        userInput.read(); 

        // 3. 計算（今は中身が空ですが、ここで入力を元に処理します）
        gameUpdate.update(userInput.lastKey);
        
        // 特定の入力で running = false にすれば終了できる
    }

    return 0;
}