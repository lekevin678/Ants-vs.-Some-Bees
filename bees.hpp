#ifndef BEES
#define BEES
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "insect.hpp"

#define VEC_SIZE 10

using namespace std;

class Bees : public Insect {
    private:
        string name;
        
    public:
        Bees();
        Bees(const Bees &);
        Bees & operator= (const Bees &);
        ~Bees();
        string get_name();
        void minus_armor(int);
        bool is_ant();
        void bees_action_call(vector < vector <Insect*> > & , int ,int * );
};

#endif