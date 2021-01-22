#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <vector>

class GameOfLife {
  public:
    int rows = 20;
    int columns = 60;
    std::vector<std::vector<int>> grid;
    GameOfLife();
    GameOfLife(int rows, int columns);
    void Initialize();
    void Update();
    int CountNeighbours(int row, int column);
};

#endif
