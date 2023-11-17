#include <game.h>
#include <set>
#include <array>
#include <vector>

class Solver : public Game
{
    private:
        std::set<t_num> set_complete_number{1,2,3,4,5,6,7,8,9};

        std::array<std::set<t_num>, SIZE_BOARD> missing_numbers_rows = {
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9}};

        std::array<std::set<t_num>, SIZE_BOARD> missing_numbers_cols = {
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9},
            std::set<t_num>{1,2,3,4,5,6,7,8,9}};

    public: 
        void print_missing_numbers();   
        void init_missing_numbers();
        bool is_solved();
        bool check_completeness_row(t_num id_row);
        bool check_completeness_column(t_num id_column);
        bool check_completeness_subgrid(t_num id_subgrid);
};