#ifndef ANTS
#define ANTS
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include "insect.hpp"
#include "user.hpp"

#define VEC_SIZE 10

using namespace std;

class Ants : public Insect{
    protected:
        int food_cost;
        string name;
        int type;
    public:
        Ants();
        Ants(const Ants & );
        Ants & operator= (const Ants &);
        ~Ants();
        bool is_ant();
        int get_food_cost();
        string get_name();
};

class Harvester : public Ants{
    private:

    public: 
        Harvester();
};

class Thrower : public Ants{
    private:   

    public:
        Thrower();
        void ants_action_call(vector < vector <Insect*> > &, int );
};

class Fire : public Ants{
    private:

    public:
        Fire();
        void ants_action_call(vector < vector <Insect*> > &, int );
};

class Long_thrower : public Ants{
    private:

    public:
        Long_thrower();
        void ants_action_call(vector < vector <Insect*> > &, int );
};

class Short_thrower : public Ants{
    private:

    public: 
        Short_thrower();
        void ants_action_call(vector < vector <Insect*> > &, int );
};

class Wall : public Ants{
    public:
        Wall();
};

class Ninja : public Ants{
    public:
        Ninja();
        void ants_action_call(vector < vector <Insect*> > &, int );
};

class Body_guard : public Ants{
    public:
        Body_guard();
};

class Queen : public Ants{
    public:
        Queen();
};

#endif