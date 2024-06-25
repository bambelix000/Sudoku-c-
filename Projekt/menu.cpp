#include "menu.h"




void Menu::displayMainMenu(){
    std::cout<<""<<std::endl;
    std::cout<<"Witaj w SUDOKU"<<std::endl;
    std::cout<<"1 - Wygeneruj nowa plansze"<<std::endl;
    std::cout<<"2 - Wczytaj zapisana plansze"<<std::endl;
    std::cout<<"3 - Wyjdz"<<std::endl;
    std::cout<<""<<std::endl;
}
void Menu::chooseLevel(){
    std::cout<<""<<std::endl;
    std::cout<<"Wybierz poziom trudnosci"<<std::endl;
    std::cout<<"1 - latwy"<<std::endl;
    std::cout<<"2 - sredni"<<std::endl;
    std::cout<<"3 - trudny"<<std::endl;
    std::cout<<""<<std::endl;
}
int Menu::optionSelector(){
    int choice = 0;
    std::cin>>choice;
    return choice;
}
void Menu::displayMove(){
    std::cout<<""<<std::endl;
    std::cout<<"Podaj rzad, kolumne oraz cyfre ktora chcesz tam umiescic"<<std::endl;
    std::cout<<""<<std::endl;
}
void Menu::displayHint(){
    std::cout<<""<<std::endl;
    std::cout<<"Podaj rzad oraz kolumne w ktorej chcialbys dostac podpowiedz"<<std::endl;
    std::cout<<""<<std::endl;
}
void Menu::displayGameMenu(){
    std::cout<<""<<std::endl;
    std::cout<<"1 - Dodaj kolejna cyfre"<<std::endl;
    std::cout<<"2 - Cofnij ostatni ruch"<<std::endl;
    std::cout<<"3 - Popros o podpowiedz"<<std::endl;
    std::cout<<"4 - Pokaz rozwiazanie"<<std::endl;
    std::cout<<"5 - Zapisz plansze"<<std::endl;
    std::cout<<"6 - Wyjdz"<<std::endl;
    std::cout<<""<<std::endl;
}

void Menu::displayGameLost(int mistakeCount, int hintCount){
    std::cout<<""<<std::endl;
    std::cout<<"KONIEC GRY!"<<std::endl;
    std::cout<<"Niestety nie udalo Ci sie wygrac"<<std::endl;
    std::cout<<"Liczba popelnionych bledow: "<<mistakeCount<<std::endl;
    std::cout<<"Liczba uzytych podpowiedzi: "<<hintCount<<std::endl;
    std::cout<<""<<std::endl;
}

void Menu::displayGameWon(int mistakeCount, int hintCount){
    std::cout<<""<<std::endl;
    std::cout<<"GRATULACJE!"<<std::endl;
    std::cout<<"Udalo Ci sie ukonczyc plansze"<<std::endl;
    std::cout<<"Liczba popelnionych bledow: "<<mistakeCount<<std::endl;
    std::cout<<"Liczba uzytych podpowiedzi: "<<hintCount<<std::endl;
    std::cout<<""<<std::endl;
}

void Menu::makeMove(int row, int col, int num, SudokuGame& game){
        AddNumCommand addCmd(row,col,num, game);
        addCmd.execute();
}
void Menu::undoMove(SudokuGame& game){
    RemoveNumCommand removeCmd(game);
    removeCmd.execute();
}

int Menu::playGame(SudokuBoard& board, SudokuGame& game, SudokuSolver& solver, int level){
    
    solver.checkSolutions(game);
    
    int row, col, num;
    while(!game.solved(game.currentBoard)){
        game.showBoard();
        displayGameMenu();
        switch (optionSelector())
        {
        case 1:
            displayMove();
            row = optionSelector();
            col = optionSelector();
            num = optionSelector();
            makeMove(row, col, num, game);
            break;

        case 2:
            undoMove(game);    
            break;

        case 3:
            displayHint();
            row = optionSelector();
            col = optionSelector();
            game.getHint(row-1, col-1);
            break;
        case 4:
            solver.printSolutions(game.solutions);
            displayGameLost(game.mistakes, game.hints);
            return 0;
        case 5:
            board.saveToFile("previousSavedGame.txt", game.currentBoard);
            break;
        case 6:
            return 0;
        default:
        std::cout<<std::endl;
        std::cout<<"Wybierz liczbe z przedzialu 1-6"<<std::endl;
            break;
        }
        
    }
    displayGameWon(game.mistakes, game.hints);
    return 0;
}

int Menu::mainGamePanel(){
    displayMainMenu();

    SudokuBoard board;
    SudokuGame game;
    SudokuSolver solver;
    int level;
    bool correctInput = false;
    do{
        switch(optionSelector()){
            case 1:
                chooseLevel();   
                do{ 
                    switch (optionSelector()) {
                        case 1: // Łatwy
                            board.loadRandomBoard(1); 
                            correctInput = true;
                            break;
                        case 2: // Średni
                            board.loadRandomBoard(2); 
                            correctInput = true;
                            break;
                        case 3: // Trudny
                            board.loadRandomBoard(3);  
                            correctInput = true;
                            break;
                        default:
                            std::cout<<"Aby wybrac poziom wybierz - 1(Latwy), 2(Sredni), 3(Trudny)"<<std::endl;
                    }
                }while(!correctInput);
                game.setBoard(board);
                playGame(board, game, solver, level);
                correctInput = true;
                break;

            case 2:
                board.loadFromFile("previousSavedGame.txt");
                game.setBoard(board);
                playGame(board, game, solver, level);
                correctInput = true;
                break;

            case 3:
                return 0;
            default:
                std::cout<<"wybierz - 1(Wygeneruj nowa plansze), 2(Wczytaj zapisana plansze), 3(Wyjdz)"<<std::endl;    
        }
    }while(!correctInput);
    return 0;
}

