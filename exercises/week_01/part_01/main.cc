#include "game-of-life/terminal.h"

int main() {
  GameOfLife game;
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