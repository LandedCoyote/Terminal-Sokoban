#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <string>
#include <cstddef>

class Player; // 前方宣言

class Map {
private:
    size_t width_;
    size_t height_;
    size_t start_x_; // プレイヤーの初期位置を保存するための変数
    size_t start_y_;
    std::vector<std::vector<char>> grid_;

public:
    Map();
    bool LoadLevel(const std::string& filename);
    void Draw(const Player& player) const;

    // ゲッター（中身を返すだけの関数）
    size_t width() const { return width_; }
    size_t height() const { return height_; }
    size_t start_x() const { return start_x_; }
    size_t start_y() const { return start_y_; }
    char GetObject(size_t x, size_t y) const;
    void SetObject(size_t x, size_t y, char obj);
};

#endif