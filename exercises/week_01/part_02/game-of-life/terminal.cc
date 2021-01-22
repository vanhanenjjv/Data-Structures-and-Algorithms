#include "terminal.h"

#include <iostream>

#include "../console/console.h"

void GameOfLifeTerminal::PrintInstructions() {
  std::cout 
    << "Welcome to Conway's game of Life.\n"
    << "This game uses a grid of size " << game.rows << " by " << game.columns << " in which\n"
    << "each cell can either be occupied by an organism or not.\n"
    << "The occupied cells change from generation to generation\n"
    << "according to the number of neighboring cells which are alive.\n";

  std::cout << '\n';
}

void GameOfLifeTerminal::PrintCells() {
  std::cout << "The current Life configuration is:\n";

  for (int row = 1; row <= this->game.rows; ++row) {
    for (int column = 1; column <= this->game.columns; ++column) 
      std::cout << (this->game.grid[row][column] == 1 ? '*' : ' ');

    std::cout << '\n';
  }

  std::cout << '\n';
}

// Update console::Prompt to read these as well?
void GameOfLifeTerminal::PromptLivingCellCoordinates() {
  std::cout << "List the coordinates for living cells.\n"
            << "Terminate the list with the special pair -1 -1\n";

  int row, column;
  std::cin >> row >> column;

  // TODO: Fix this mess
  while (row != -1 || column != -1) {
    if (row >= 1 && row <= this->game.rows) {
      if (column >= 1 && column <= this->game.columns) {
        this->game.grid[row][column] = 1;
      } else {
        std::cout << "Column " << column << " is out of range.\n";
      }
    } else {
      std::cout << "Row " << row << " is out of range.\n";
    }

    std::cin >> row >> column;
  }

  std::cout << '\n';
}

bool GameOfLifeTerminal::PromptContinueGeneratingCells() {
  return console::Prompt("Continue viewing new generations");
}
