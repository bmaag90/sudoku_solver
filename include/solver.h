#include <game.h>
#include <set>
#include <array>
#include <vector>
#include <algorithm>

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

        std::array<std::set<t_num>, SIZE_BOARD> missing_numbers_subgrids = {
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
        bool check_completeness_row(int id_row);
        bool check_completeness_column(int id_col);
        bool check_completeness_subgrid(int id_subgrid);
        std::set<t_num> get_possible_numbers(int id_row, int id_col);
        bool solve();
};