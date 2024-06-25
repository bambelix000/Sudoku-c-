#ifndef SUDOKU_GAME_H
#define SUDOKU_GAME_H

#include "SudokuBoard.h"

struct Move{
    int row;
    int col;
    int value;
    int prevValue;

    Move(int r, int c, int val, int prevVal)
        : row(r), col(c), value(val), prevValue(prevVal) {}
};

class SudokuGame
{
    public:
        SudokuGame() : mistakes(0), hints(0) {}

        void playMove(int row, int col, int value, SudokuGame& game);
        void undoMove();
        void getHint(int row, int col);
        bool compareSolution(int row, int col, int num, SudokuGame& game);
        void saveToFile(const std::string& filename);
        void showBoard();
        void setBoard(SudokuBoard& board);
        bool solved(SudokuBoard& board); 
        std::vector<SudokuBoard> solutions;
        SudokuBoard currentBoard;
        int mistakes;
        int hints;
    private:
        std::vector<Move> userMoves;
        
};
#endif