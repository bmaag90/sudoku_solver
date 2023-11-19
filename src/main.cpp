#include "solver.h"

int main(int argc, char** argv){
    if (argc != 2){
        printf("Game file missing...");
        return 0;
    }
    const char* path_game = argv[1];

    Solver new_game = Solver();

    new_game.read_game_from_file(path_game);

    new_game.print_state();

    new_game.init_missing_numbers();

    new_game.print_missing_numbers();

    new_game.get_possible_numbers(0, 0);

    return 1;
}