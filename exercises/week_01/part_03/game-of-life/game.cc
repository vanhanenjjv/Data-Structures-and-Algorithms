#include "game.h"

#include <algorithm>

GameOfLife::GameOfLife() {}

GameOfLife::GameOfLife(int rows, int columns) {
  this->rows = rows;
  this->columns = columns;
}

void GameOfLife::Initialize() {
  // Set all of the cells to zero
  this->grid.resize(this->rows);

  for (int row = 0; row < this->rows; ++row)
    this->grid[row].resize(this->columns);
}

void GameOfLife::Update() {
  std::vector<std::vector<int>> new_grid(this->grid);

  for (int row = 0; row < this->rows; ++row) {
    for (int column = 0; column < this->columns; ++column) {
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

  for (int row = 0; row < this->rows; ++row)
    for (int column = 0; column < this->columns; ++column)
      this->grid[row][column] = new_grid[row][column];
}

int GameOfLife::CountNeighbours(int row, int column) {
  int count = 0;

  int row_from = std::max(row - 1, 0);
  int row_to   = std::min(row + 1, this->rows - 1);

  for (int r = row_from; r <= row_to; ++r) {
    int column_from = std::max(column - 1, 0);
    int column_to   = std::min(column + 1, this->columns - 1);
    
    for (int c = column_from; c <= column_to; ++c) 
      count += this->grid[r][c];
  }

  count -= this->grid[row][column];

  return count;
}
