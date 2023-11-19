#include "solver.h"

void Solver::init_missing_numbers(){
    for (int r = 0; r < SIZE_BOARD; r++){
        for (int c = 0; c < SIZE_BOARD; c++){
            if (this->state.at(r*SIZE_BOARD + c) != 0){
                this->missing_numbers_rows.at(r).erase(this->state.at(r*SIZE_BOARD + c));
                this->missing_numbers_cols.at(c).erase(this->state.at(r*SIZE_BOARD + c));
                int s = (int)(r/3)*3 + (int)(c/3);
                this->missing_numbers_subgrids.at(s).erase(this->state.at(r*SIZE_BOARD + c));
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
        printf("\nSUBGRID %d: ", i);
            for (auto ns : this->missing_numbers_subgrids.at(i)) printf("%d ", ns);
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

bool Solver::check_completeness_row(int id_row){
    return this->missing_numbers_rows.at(id_row).empty();
}

bool Solver::check_completeness_column(int id_col){
    return this->missing_numbers_cols.at(id_col).empty();
}

bool Solver::check_completeness_subgrid(int id_subgrid){
    return this->missing_numbers_subgrids.at(id_subgrid).empty();
}

std::set<t_num> Solver::get_possible_numbers(int id_row, int id_col){
    std::set<t_num> possible_numbers;
    std::set_intersection(
        this->missing_numbers_rows.at(id_row).begin(), this->missing_numbers_rows.at(id_row).end(),
        this->missing_numbers_cols.at(id_col).begin(), this->missing_numbers_cols.at(id_col).end(),
        std::inserter(possible_numbers, possible_numbers.begin())
    );

#ifdef DEBUG
    for (auto n : possible_numbers) printf("%d ", n);
    printf("\n");
#endif

    return possible_numbers;
}

bool Solver::solve(){
    return false;
}