#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

#include "sudokuBoard.h"
#include "sudokuGame.h"

class SudokuSolver
{
    public:
        void checkSolutions(SudokuGame& game);
        bool solve(SudokuBoard board, SudokuGame& game);
        std::pair<int, int> findUnassignedPosition(const SudokuBoard& board);
        void printSolutions(const std::vector<SudokuBoard>& solutions);
};
#endif