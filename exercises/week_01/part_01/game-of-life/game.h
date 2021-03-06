#ifndef GAME_OF_LIFE_H
#define GAME_OF_LIFE_H

const int kRows = 20;
const int kColumns = 60;

class GameOfLife {
  public:
    int rows = kRows;
    int columns = kColumns;
    int grid[kRows + 2][kColumns + 2];
    void Initialize();
    void Update();
    int CountNeighbours(int row, int column);
};

#endif
