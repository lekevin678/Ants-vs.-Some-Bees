#include "insect.hpp"

using namespace std;

Insect::Insect(){
    this-> armor = 0;
}

Insect::Insect(const Insect & copy){
    this-> armor = copy.armor;
}

Insect & Insect::operator= (const Insect & copy){
    this-> armor = copy.armor;
}

bool Insect::is_ant(){

}

int Insect::get_armor(){ return this-> armor;}

void Insect::set_armor(int i){
    this->armor = i;
}

void Insect::remove_from_vec(vector < vector <Insect*> > & vec, int i, int j){
    if(vec[i][j]->get_name() == "F"){
        for (int a = 0; a < vec[i].size(); a++){
            if (is_ant() == false){
                vec[i][a]->set_armor(0);
            }
        }
    }

    if(this->armor == 0){
        if (vec[i][j]->is_ant() == true){
            cout << "Ant at: " << i+1 << " removed." << endl;
            vec[i].erase(vec[i].begin() + j);
        }
        if (vec[i][j]->is_ant() == false){
            cout << "Bee at: " << i+1 << " removed." << endl;
            vec[i].erase(vec[i].begin() + j);
        }
    }
}


Insect::~Insect(){

}