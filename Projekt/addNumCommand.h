#ifndef ADD_NUM_COMMAND_H
#define ADD_NUM_COMMAND_H

#include "command.h"
#include "sudokuGame.h"

class AddNumCommand : public Command{
    private:
        SudokuGame& game;
        int row, col, num;
    public:
        AddNumCommand(int r, int c, int n, SudokuGame& g) : row(r), col(c), num(n), game(g){}
        void execute() override;
};
#endif