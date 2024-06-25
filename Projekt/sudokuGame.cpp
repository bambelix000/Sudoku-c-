#include "sudokuGame.h"


bool SudokuGame::compareSolution(int row, int col, int num, SudokuGame& game){
    for (const auto& solution : solutions) {
            if (solution.grid[row][col] == num) {
                return true; 
            }
        }
    return false;
}

void SudokuGame::playMove(int row, int col, int value, SudokuGame& game){
    int prevValue = currentBoard.grid[row][col];
    if(compareSolution(row, col, value, game) && row >=0 && row <9 && col >=0 && col <9 && value >=0 && value <=9){
        currentBoard.grid[row][col] = value;
        game.userMoves.push_back(Move(row, col, value, prevValue));
    }else{
        std::cout<<"Błąd"<<std::endl;
        mistakes++;
    }
}

void SudokuGame::showBoard(){
    std::cout<<std::endl;
    currentBoard.showBoard();
    std::cout<<std::endl;
}

bool SudokuGame::solved(SudokuBoard& board){
    if(currentBoard.isSolved(board)){
        return true;
    }
    return false;
}

void SudokuGame::saveToFile(const std::string& filename){
    currentBoard.saveToFile(filename, currentBoard);
}

void SudokuGame::undoMove() {
        if (!userMoves.empty()) {
            Move lastMove = userMoves.back();         
            userMoves.pop_back();                    
            currentBoard.grid[lastMove.row][lastMove.col] = lastMove.prevValue; 
        } else {
            std::cout << "Nie wykonales zadnego ruchu ktory moglbys cofnac!" << std::endl;
        }
    }

void SudokuGame::getHint(int row, int col){
    std::vector<int> ans;
    for(const auto& solutions : solutions)
    ans.push_back(solutions.grid[row][col]);

    std::cout<<"Pasujace cyfry w miejscu ["<<row+1<<";"<<col+1<<"] to ";
    for(auto el : ans){
        std::cout<<el<<" ";
    }
    hints++;
}

void SudokuGame::setBoard(SudokuBoard& board){
    currentBoard = board;
}