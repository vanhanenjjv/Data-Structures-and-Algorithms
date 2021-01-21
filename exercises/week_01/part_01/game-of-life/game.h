#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

#include <vector>

class GameOfLife {
  public:
    int rows = 20;
    int columns = 60;
    int grid[20 + 2][60 + 2];
    void Initialize();
    void Update();
    int CountNeighbours(int row, int column);
};

#endif
