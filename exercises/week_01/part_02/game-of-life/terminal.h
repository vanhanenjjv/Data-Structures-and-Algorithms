#ifndef GAME_OF_LIFE_TERMINAL_H
#define GAME_OF_LIFE_TERMINAL_H

#include "game.h"

class GameOfLifeTerminal {
  private:
    GameOfLife &game;

  public:
    GameOfLifeTerminal(GameOfLife &game) : game(game) {}
    void PrintInstructions();
    void PrintCells();
    void PromptLivingCellCoordinates();
    bool PromptContinueGeneratingCells();
};

#endif
