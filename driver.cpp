#include <iostream>
#include <string>
#include <vector>
#include "ants.hpp"
#include "bees.hpp"
#include "insect.hpp"
#include "user.hpp"
#include "no_class.hpp"

#define VEC_SIZE 10

using namespace std;

int main(){
    vector < vector <Insect*> > vec (10);
    start(vec);

    delete_func(vec);
    vec.clear();

}