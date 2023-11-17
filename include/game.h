#include <array>
#include <fstream>
#include <iostream>

#define SIZE_BOARD 9
typedef unsigned short t_num;

class Game{

    private:
        void _print(std::array<t_num, SIZE_BOARD*SIZE_BOARD> *ptr_state);

    public:
        std::array<t_num, SIZE_BOARD*SIZE_BOARD> init_state;
        std::array<t_num, SIZE_BOARD*SIZE_BOARD> state;

        void reset_game();
        void read_game_from_file(const char* fname);

        void print_state();
        void print_init_state();

        void set_field(t_num r, t_num c, t_num num);
};