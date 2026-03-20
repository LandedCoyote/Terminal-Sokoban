#include "Map.hpp"
#include "Player.hpp"
#include <iostream>
#include <fstream>

Map::Map() : width_(0), height_(0), start_x_(0), start_y_(0) {}

bool Map::LoadLevel(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    // 1. サイズ読み込み
    file >> width_ >> height_;
    
    // 2. 初期座標読み込み
    file >> start_x_ >> start_y_;
    file.ignore(); 

    grid_.assign(height_, std::vector<char>(width_));

    for (size_t y = 0; y < height_; ++y) {
        std::string line;
        std::getline(file, line);
        for (size_t x = 0; x < width_; ++x) {
            if (x < line.length()) {
                // マップ上のPは描画時にPlayerクラスから出すので、データ上は床にする
                if (line[x] == 'P') grid_[y][x] = ' ';
                else grid_[y][x] = line[x];
            } else {
                grid_[y][x] = ' ';
            }
        }
    }
    return true;
}

char Map::GetObject(size_t x, size_t y) const {
    if (y >= height_ || x >= width_) return '#'; // 範囲外は壁扱い
    return grid_[y][x];
}

void Map::SetObject(size_t x, size_t y, char obj) {
    if (y < height_ && x < width_) {
        grid_[y][x] = obj;
    }
}

void Map::Draw(const Player& player) const {
    // 画面クリア
    std::cout << "\033[2J\033[1;1H";
    for (size_t y = 0; y < height_; ++y) {
        for (size_t x = 0; x < width_; ++x) {
            if (x == player.x() && y == player.y()) std::cout << 'P';
            else std::cout << grid_[y][x];
        }
        std::cout << std::endl;
    }
}