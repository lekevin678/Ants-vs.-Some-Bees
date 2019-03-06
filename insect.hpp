#ifndef INSECT
#define INSECT
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

#define VEC_SIZE 10

using namespace std;

class Insect{
    protected:
        int armor;
    public:
        Insect();
        Insect(const Insect & );
        Insect & operator= (const Insect &);
        ~Insect();
        int get_armor();
        void set_armor(int);
        virtual bool is_ant() = 0;
        virtual string get_name() = 0;
        virtual void remove_from_vec(vector < vector <Insect*> > &, int, int);
        virtual void ants_action_call(vector < vector <Insect*> > & , int){};
        virtual void bees_action_call(vector < vector <Insect*> > & , int, int *){};


};

#endif