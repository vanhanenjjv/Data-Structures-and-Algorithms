#include "game.h"

void GameOfLife::Initialize() {
  // Set all of the cells to zero
  for (int row = 0; row <= this->rows + 1; ++row)
    for (int column = 0; column <= this->columns + 1; ++column)
      this->grid[row][column] = 0;
}

void GameOfLife::Update() {
  int new_grid[this->rows + 2][this->columns + 2];

  for (int row = 1; row <= this->rows; ++row) {
    for (int column = 1; column <= this->columns; ++column) {
      switch (this->CountNeighbours(row, column)) {
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
