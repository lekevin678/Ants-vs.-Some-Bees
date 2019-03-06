#ifndef USER
#define USER
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "ants.hpp"
#include "bees.hpp"
#include "insect.hpp"

#define VEC_SIZE 10

class User{
    private:
        int food_bank;

    public:
        User();
        void game_setup(vector < vector <Insect*> > &);
        void display_board(vector < vector <Insect*> > &);
        void print_ask_ant(vector < vector <Insect*> > &);
        bool valid_place(vector < vector <Insect*> > &, int);
        void place_ant(vector < vector <Insect*> > &, int, string);
        void game_loop(vector < vector <Insect*> > &, User &);
        void ant_attack(vector < vector <Insect*> > &, User &);
        void bee_action(vector < vector <Insect*> > &);
        bool end_game_check(vector < vector <Insect*> > &);
        void minus_food(string );
};

int get_int(string);
bool is_int(string);

#endif