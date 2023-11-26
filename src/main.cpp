#include "solver.h"

int main(int argc, char** argv){
    if (argc != 2){
        printf("Game file missing...");
        return 1;
    }
    const char* path_game = argv[1];

    Solver new_game = Solver();

    new_game.read_game_from_file(path_game);

    new_game.print_state();

    new_game.init_missing_numbers();

    new_game.print_missing_numbers();

    bool is_solved = new_game.solve();

    if (is_solved){
        printf("\n+++++\nSOLUTION FOUND:\n");
        new_game.print_state();
        printf("Solver took %u steps\n", new_game.get_count_solver_steps());
    } else {
        printf("\n-----\nNO SOLUTION FOUND:\n");
        new_game.print_state();
        printf("Solver took %u steps\n", new_game.get_count_solver_steps());
    }

    

    return 0;
}