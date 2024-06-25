#include "addNumCommand.h"

void AddNumCommand::execute() {
        game.playMove(row-1,col-1,num,game);
    }