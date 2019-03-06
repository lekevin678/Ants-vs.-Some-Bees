#include "no_class.hpp"

using namespace std;

void start(vector < vector <Insect*> > &vec){
    User user;
    user.game_setup( vec );
    user.game_loop(vec, user);
}

void delete_func(vector < vector <Insect*> > & vec){

    for (int i = 0; i < VEC_SIZE; i++){
        for (int j = 0; j < vec[i].size(); j++){
            delete vec[i][j];
        }
    }



    vec.clear();
}