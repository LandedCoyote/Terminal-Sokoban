#include "Game.hpp"
#include <iostream>

void Game::Update(char lastKey, Player& player, Map& gameMap) {
    int dx = 0;
    int dy = 0;

    // 入力に応じて移動量を決定
    // 一時的にwasdのキーを使って上下左右の移動を表現
    // todo 後で矢印キーに変更を行う
    switch (lastKey) {
        case 'w': dy = -1; break; // 上
        case 's': dy =  1; break; // 下
        case 'a': dx = -1; break; // 左
        case 'd': dx =  1; break; // 右
        default: return;          // 無関係なキーなら何もしない
    }

    // 移動先の座標を計算
    int nextX = player.x() + dx;
    int nextY = player.y() + dy;

    char target_tile = gameMap.GetObject(nextX, nextY);
    // if文を使う場合
    if (target_tile == ' ' || target_tile == '.') {
        player.Move(dx, dy); // 障害物がないので進む
    } else if (target_tile == '$' || target_tile == '*') {
        // 荷物がある場合、押せるか試す
        if (TryPushBox(nextX, nextY, dx, dy, gameMap)) {
            player.Move(dx, dy); // 押せたので自分も進む
        }
    }

    /* // switch文を使う場合
    switch (target_tile) {
        case ' ':
        {
            player.Move(dx, dy); // 障害物がないので進む
            break;
        }
        case '.':
        {
            player.Move(dx, dy); // todo プレイヤーonゴールに表示を変化させる処理を追加する
            break;
        }
        case '$':
        {
            // 荷物がある場合、押せるか試す
            if (TryPushBox(nextX, nextY, dx, dy, gameMap)) {
                player.Move(dx, dy); // 押せたので自分も進む
            }
        }
        case '*':
        {
            // ゴールに箱がある場合、押せるか試す
            if (TryPushBox(nextX, nextY, dx, dy, gameMap)) {
                player.Move(dx, dy); // 押せたので自分も進む
            }
        }
    }
    */
}

// 移動先の座標(x, y)と、その方向(dx, dy)を渡す
bool Game::TryPushBox(size_t x, size_t y, int dx, int dy, Map& game_map) {
    size_t next_x = x + dx;
    size_t next_y = y + dy;
    
    char box_tile = game_map.GetObject(x, y);
    char next_tile = game_map.GetObject(next_x, next_y);
    
    // 箱の移動先が「床」または「ゴール」なら移動可能
    switch (next_tile) {
        case '.':
        {
            game_map.SetObject(next_x, next_y, '*'); // ゴールに箱が置かれた状態を表す（例: '*'）
            game_map.SetObject(x, y, ' ');           // 元の場所を空ける
            return true;
        }
        case ' ':
        {
            game_map.SetObject(next_x, next_y, '$'); // 新しい位置に箱を置く
            if (box_tile == '*') {
                game_map.SetObject(x, y, '.');       // 元の場所がゴールだった場合はゴールに戻す
            } else {
                game_map.SetObject(x, y, ' ');       // 元の場所を空ける
            }
            return true;
        }
        default:
        {
            return false;
        }
    }
}
