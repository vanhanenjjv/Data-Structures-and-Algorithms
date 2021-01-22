#include <iostream>

#include "game-of-life/terminal.h"

int main() {
  // TODO: move this garbage to UI code
  int columns, rows;

  std::cout << "Amount of rows: ";
  std::cin >> rows;

  std::cout << "Amount of columns: ";
  std::cin >> columns;

  GameOfLife game(columns, rows);
  GameOfLifeTerminal ui(game);

  game.Initialize();

  ui.PrintInstructions();
  ui.PromptLivingCellCoordinates();
  ui.PrintCells();

  while (ui.PromptContinueGeneratingCells()) {
    game.Update();
    ui.PrintCells();
  }
  
  return 0;
}