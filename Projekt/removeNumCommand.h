#ifndef REMOVE_NUM_COMMAND_H
#define REMOVE_NUM_COMMAND_H

#include "command.h"
#include "sudokuGame.h"

class RemoveNumCommand : public Command{
    private:
        SudokuGame& game;
    public:
        RemoveNumCommand(SudokuGame& g) : game(g) {}
        void execute() override;
};
#endif
