#ifndef MENU_H
#define MENU_H

#include "sudokuBoard.h"
#include "sudokuGame.h"
#include "sudokuSolver.h"
#include "addNumCommand.h"
#include "removeNumCommand.h"



class Menu{
    public:
        int optionSelector();
        void displayMainMenu();
        void displayGameMenu();
        void displayMove();
        void displayHint();
        void displayGameLost(int mistakeCount, int hintCount);
        void displayGameWon(int mistakeCount, int hintCount);
        int mainGamePanel();
        int playGame(SudokuBoard& board, SudokuGame& game, SudokuSolver& solver, int level);
        void chooseLevel();
        void makeMove(int row, int col, int num, SudokuGame& game);
        void undoMove(SudokuGame& game);
};
#endif