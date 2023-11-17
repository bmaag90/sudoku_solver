#include "solver.h"


void Solver::init_missing_numbers(){
    for (int r = 0; r < SIZE_BOARD; r++){
        for (int c = 0; c < SIZE_BOARD; c++){
            if (this->state.at(r*SIZE_BOARD + c) != 0){
                this->missing_numbers_rows.at(r).erase(this->state.at(r*SIZE_BOARD + c));
                this->missing_numbers_cols.at(c).erase(this->state.at(r*SIZE_BOARD + c));
            }
       }
    }
}

void Solver::print_missing_numbers(){
    printf("---MISSING NUMBERS---\n");
    for (int i = 0; i < SIZE_BOARD; i++){
        printf("\nROW %d: ", i);
            for (auto nr : this->missing_numbers_rows.at(i)) printf("%d ", nr);
        printf("\nCOL %d: ", i);
            for (auto nc : this->missing_numbers_cols.at(i)) printf("%d ", nc);
    }
    printf("\n---\n");
}


bool Solver::is_solved(){
    for (int rc = 0; rc < SIZE_BOARD; rc++){
        if (!this->check_completeness_row(rc)) return false;
        if (!this->check_completeness_column(rc)) return false;
        if (!this->check_completeness_subgrid(rc)) return false;
    }
    return true;
}

bool Solver::check_completeness_row(t_num id_row){
    // std::set<t_num> set_row{std::begin(this->state)+id_row*SIZE_BOARD, std::begin(this->state)+(id_row+1)*SIZE_BOARD};

    // return set_row == set_complete_numbers;
    return false;
}

bool Solver::check_completeness_column(t_num id_column){
    return false;
}

bool Solver::check_completeness_subgrid(t_num id_subgrid){
    return false;
}