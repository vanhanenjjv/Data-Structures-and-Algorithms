#include "game.h"

GameOfLife::GameOfLife() {}

GameOfLife::GameOfLife(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;
}

void GameOfLife::Initialize() {
  // Set all of the cells to zero
  this->grid.resize(this->rows + 2);

  for (int row = 0; row < this->rows + 2; ++row)
    this->grid[row].resize(this->columns + 2);
}

void GameOfLife::Update() {
  std::vector<std::vector<int>> new_grid(this->grid);

  for (int row = 1; row <= this->rows; ++row) {
    for (int column = 1; column <= this->columns; ++column) {
      int neighbours_count = this->CountNeighbours(row, column);

      switch (neighbours_count) {
        case 2: /* Cell stays the same */ {
          new_grid[row][column] = this->grid[row][column];
          break;
        }
        case 3: /* Cell is now alive */ {
          new_grid[row][column] = 1;               
          break;
        }
        default: /* Cell is now dead */
          new_grid[row][column] = 0;
        }
      }
    }

  for (int row = 1; row <= this->rows; ++row)
    for (int column = 1; column <= this->columns; ++column)
      this->grid[row][column] = new_grid[row][column];
}

int GameOfLife::CountNeighbours(int row, int column) {
  int count = 0;

  for (int r = row - 1; r <= row + 1; ++r) 
    for (int c = column - 1; c <= column + 1; ++c) 
      count += this->grid[r][c];

  count -= this->grid[row][column];

  return count;
}
