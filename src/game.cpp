#include "game.h"

void Game::_print(std::array<t_num, SIZE_BOARD*SIZE_BOARD> *ptr_state){
    for (int r = 0; r < SIZE_BOARD; r++){
        if (r%3 == 0) printf("-------------\n");
        for (int c = 0; c < SIZE_BOARD; c++){
            if (c%3 == 0) printf("|");            
            printf("%u", (*ptr_state).at(r*SIZE_BOARD + c));

        }
        printf("|\n");
    }
    printf("-------------\n");
}

void Game::reset_game(){
    std::copy(std::begin(this->init_state), std::end(this->init_state), std::begin(this->state));
}

void Game::read_game_from_file(const char* fname){
    
    char ch;
    int cnt = 0;
    t_num num = 0;

    std::ifstream infile (fname);
    if (infile.is_open()){
        while(infile.get(ch))
        {
            if (ch == '.'){
                num = 0;
            } else if (ch == '\n'){
                break;
            } else {
                num = (t_num)((int)(ch) - (int)('0'));
            }
            this->init_state.at(cnt) = num;
            cnt++;
        }
        this->reset_game();
    } else {
        printf("ERROR: could not open file: %s", fname);
    }
}

void Game::print_state(){
    this->_print(&this->state);
}

void Game::print_init_state(){
    this->_print(&this->init_state);
}

void Game::set_field(t_num r, t_num c, t_num num){
    this->state.at(r*SIZE_BOARD + c) = num;
}
