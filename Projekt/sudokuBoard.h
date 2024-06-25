#ifndef SUDOKU_BOARD_H
#define SUDOKU_BOARD_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <sstream>

class SudokuBoard
{
    friend std::istream& operator>>(std::istream& in, SudokuBoard& board);
    friend std::ostream& operator<<(std::ostream& out, SudokuBoard& board);
    public:
        void loadFromFile(const std::string& filename);
        void saveToFile(const std::string& filename, SudokuBoard& board);
        bool isSolved(SudokuBoard& board);
        void showBoard();
        bool checkInput(int row, int col, int value);
        void loadRandomBoard(int level);
    
       std::vector<std::vector<int>> grid;
};
#endif