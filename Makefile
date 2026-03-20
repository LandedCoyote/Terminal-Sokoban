# --- 設定 ---
CXX      = g++
CXXFLAGS = -g -Wall -Iinclude
TARGET   = bin/sokoban
SRCDIR   = src
OBJDIR   = build

# src フォルダ内のすべての .cpp ファイルを取得
SOURCES  = $(wildcard $(SRCDIR)/*.cpp)
# オブジェクトファイルのパスを build/xxxx.o に変換
OBJECTS  = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# --- ビルド命令 ---

all: $(TARGET)

# 実行ファイルの生成
$(TARGET): $(OBJECTS)
	@mkdir -p bin
	$(CXX) $(OBJECTS) -o $(TARGET)

# 各 .cpp から .o を生成
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 掃除用
clean:
	rm -rf $(OBJDIR) bin

# 再ビルド
re: clean all

.PHONY: all clean re