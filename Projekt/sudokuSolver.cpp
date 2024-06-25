#include "sudokuSolver.h"


void SudokuSolver::checkSolutions(SudokuGame& game){
    solve(game.currentBoard, game);
}

std::pair<int, int> SudokuSolver::findUnassignedPosition(const SudokuBoard& board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board.grid[row][col] == 0) {
                return std::make_pair(row, col);  // Zwróć współrzędne pierwszego pustego miejsca
            }
        }
    }
    return std::make_pair(-1, -1);  // Wszystkie komórki są przypisane
}

bool SudokuSolver::solve(SudokuBoard board, SudokuGame& game) {
    auto unassigned = findUnassignedPosition(board);
    int row = unassigned.first;
    int col = unassigned.second;
    

    if (row == -1 && col == -1) {
        game.solutions.push_back(board);
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (board.checkInput(row, col, num)) {
            board.grid[row][col] = num;

            if (solve(board, game)){
                return true;
            } else{
            board.grid[row][col] = 0;
            } 

        }
    }
    return false;
}


void SudokuSolver::printSolutions(const std::vector<SudokuBoard>& solutions) {
    int solutionCount = 1;
    std::cout<<std::endl;
    std::cout<<std::endl;
    for (const auto& board : solutions) {
        std::cout << "Rozwiazanie #" << solutionCount++ << ":\n";
        for (const auto& row : board.grid) {
            for (int num : row) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
}