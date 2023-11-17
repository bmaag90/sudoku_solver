#include "solver.h"

int main(){
    const char* path_game = "/home/balz/Code/sudoku/backtracking/games/game_0.txt";

    Solver new_game = Solver();

    new_game.read_game_from_file(path_game);

    new_game.print_state();

    new_game.init_missing_numbers();

    new_game.print_missing_numbers();

    return 1;
}