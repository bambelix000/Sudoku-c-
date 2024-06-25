#include "sudokuBoard.h"

//operatory przeciążające
std::istream& operator>>(std::istream& in, SudokuBoard& board) {
    board.grid.resize(9, std::vector<int>(9, 0));  
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            in >> board.grid[i][j];
        }
    }
    return in;
}

std::ostream& operator<<(std::ostream& out, SudokuBoard& board) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            out << board.grid[i][j] << " ";
        }
        out << std::endl; 
    }
    return out;
}
//Pliki - odczyt zapis
void SudokuBoard::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    file >> *this;
    file.close();
}

void SudokuBoard::saveToFile(const std::string& filename, SudokuBoard& board){
    std::ofstream file(filename);
    if (file.is_open()) {
        file << board; 
        file.close();
    }
}

void SudokuBoard::showBoard(){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout<< this->grid[i][j] << " ";
        }
        std::cout<<std::endl;
    }
}

bool SudokuBoard::isSolved(SudokuBoard& board){
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if(board.grid[i][j] == 0){
                return false;
            }
        }
    }
    return true;
}

bool SudokuBoard::checkInput(int row, int col, int value){
    // Sprawdzenie wiersza
    for (int i = 0; i < 9; ++i) {
        if (grid[row][i] == value) {
            return false; 
        }
    }
    // Sprawdzenie kolumny
    for (int i = 0; i < 9; ++i) {
        if (grid[i][col] == value) {
            return false; 
        }
    }
    // Sprawdzenie bloku 3x3
    int startRow = row - row % 3; 
    int startCol = col - col % 3; 
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == value) {
                return false;
            }
            
        }
    }
    return true;
}


void SudokuBoard::loadRandomBoard(int level){
    std::string filename;
    grid = std::vector<std::vector<int>>(9, std::vector<int>(9, 0));
    std::srand(std::time(nullptr));
    const int SIZE = 9;
    switch(level){
        case 1:
            filename = "easy.txt";
            break;
        case 2:
            filename = "medium.txt";
            break;
        case 3:
            filename = "hard.txt";
            break;
    }
    std::ifstream file(filename);
    
     int gridNumber = std::rand() % 10 + 1;
        std::string searchGrid = "GRID" + std::to_string(gridNumber);
        std::string line;
        bool startReading = false;

        while (getline(file, line)) {
            if (line.find(searchGrid) != std::string::npos) {
                startReading = true;
                continue;
            }

            if (startReading) {
                if (line.empty() || isalpha(line[0])) {
                    break; 
                }
                
                static int row = 0;
                std::istringstream iss(line);
                for (int col = 0; col < SIZE; ++col) {
                    iss >> grid[row][col];
                }
                row++;
                if (row >= SIZE) break;
            }
        }

        file.close();
    
}

