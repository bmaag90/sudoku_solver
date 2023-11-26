#include "solver.h"

bool Solver::check_completeness_row(int id_row){
    return this->missing_numbers_rows.at(id_row).empty();
}

bool Solver::check_completeness_column(int id_col){
    return this->missing_numbers_cols.at(id_col).empty();
}

bool Solver::check_completeness_subgrid(int id_subgrid){
    return this->missing_numbers_subgrids.at(id_subgrid).empty();
}

t_num Solver::get_subgrid_id(int id_row, int id_col){
    return (int)(id_row/3)*3 + (int)(id_col/3);
}

void Solver::remove_missing_number(int id_row, int id_col, t_num num){
    this->missing_numbers_rows.at(id_row).erase(num);
    this->missing_numbers_cols.at(id_col).erase(num);
    this->missing_numbers_subgrids.at(get_subgrid_id(id_row, id_col)).erase(num);
}

void Solver::add_missing_number(int id_row, int id_col, t_num num){
    this->missing_numbers_rows.at(id_row).insert(num);
    this->missing_numbers_cols.at(id_col).insert(num);
    this->missing_numbers_subgrids.at(get_subgrid_id(id_row, id_col)).insert(num);
}

std::set<t_num> Solver::get_possible_numbers(int id_row, int id_col){
    std::set<t_num> tmp, possible_numbers;
    // intersection between missing numbers at row nr. "id_row" and col nr. "id_col"
    std::set_intersection(
        this->missing_numbers_rows.at(id_row).begin(), this->missing_numbers_rows.at(id_row).end(),
        this->missing_numbers_cols.at(id_col).begin(), this->missing_numbers_cols.at(id_col).end(),
        std::inserter(tmp, tmp.begin())
    );
    // intersection between resulting set of previous intersection and missing numbers at subgrid nr. "s"
    std::set_intersection(
        tmp.begin(), tmp.end(),
        this->missing_numbers_subgrids.at(get_subgrid_id(id_row, id_col)).begin(), this->missing_numbers_subgrids.at(get_subgrid_id(id_row, id_col)).end(),
        std::inserter(possible_numbers, possible_numbers.begin())
    );

    return possible_numbers;
}

t_num Solver::get_next_empty_cell(){
    for (int i = 0; i < SIZE_BOARD*SIZE_BOARD; i++){
        if (this->state.at(i) == 0) return i;
    } 
    return SIZE_BOARD*SIZE_BOARD;
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

void Solver::init_missing_numbers(){
    for (int r = 0; r < SIZE_BOARD; r++){
        for (int c = 0; c < SIZE_BOARD; c++){
            if (this->state.at(r*SIZE_BOARD + c) != 0){
                this->missing_numbers_rows.at(r).erase(this->state.at(r*SIZE_BOARD + c));
                this->missing_numbers_cols.at(c).erase(this->state.at(r*SIZE_BOARD + c));
                this->missing_numbers_subgrids.at(get_subgrid_id(r, c)).erase(this->state.at(r*SIZE_BOARD + c));
            }
       }
    }
}

bool Solver::is_solved(){
    for (int rc = 0; rc < SIZE_BOARD; rc++){
        if (!this->check_completeness_row(rc)){
            return false;
        } 
        if (!this->check_completeness_column(rc)){
            return false;
        } 
        if (!this->check_completeness_subgrid(rc)){
            return false;
        } 
    }
    return true;
}


unsigned int Solver::get_count_solver_steps(){
    return this->count_solver_steps;
}

bool Solver::solve(){
    // new step, increase counter
    this->count_solver_steps += 1;
    t_num next_cell = this->get_next_empty_cell();

    // No empty cell left, let's check if the we solved the game
    if (next_cell == SIZE_BOARD*SIZE_BOARD){
        if (this->is_solved()){
            return true;
        } else {
            return false;
        }
    }
    // get all possible numbers for the current cell
    int r = next_cell / 9;
    int c = next_cell % 9;
    std::set<t_num> possible_numbers = this->get_possible_numbers(r, c);

    for (auto pn : possible_numbers){
        #ifdef DEBUG
            printf("Setting (%d, %d) to %u\n", r, c, pn);
        #endif      

        // Set a possibile number to the current cell    
        this->state.at(r*SIZE_BOARD + c) = pn;
        this->remove_missing_number(r, c, pn);
        // recursive call to solve (i.e. try next cell or check for solution)
        if (this->solve()){
            return true;
        }
        //  if we are here, the previous try was not successful, 
        // i.e. try another number and add the previous number to the missing numbers
        this->add_missing_number(r, c, pn);
    }
                
#ifdef DEBUG
    printf("Re-Setting (%d, %d) to %u\n", r,c, 0);
#endif          
    // if we are here, then we could not find any possible number for the current cell and we need to backtrack
    this->state.at(r*SIZE_BOARD + c) = 0;
    return false;
}

