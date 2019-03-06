#include "bees.hpp"

using namespace std;

Bees::Bees(){
    this-> armor = 3;
    this-> name = "B";
}

Bees::Bees(const Bees & copy){
    this-> armor = copy.armor;
    this-> name = copy.name;
}

Bees & Bees::operator= (const Bees & copy){
    this-> armor = copy.armor;
    this-> name = copy.name;
}

Bees::~Bees(){
    
}

// void Bees::minus_armor(int m){
//     this->armor -= m;
//     if (this-> armor == 0){

//     }
// }

void Bees::bees_action_call(vector < vector <Insect*> > & vec, int i ,int * a){
    int armor = 0;
    bool ant_detected = false;
    int t = *a;
    for (int j = 0; j < vec[i].size(); j++){
        if (vec[i][j]->get_name() == "G" && vec[i][j]->get_armor() > 0){
                armor = vec[i][j]->get_armor();
                armor--;
                vec[i][j]->set_armor(armor);
                cout << "Bodyguard at " << i+1 << " lost one armor due to Bee at "<< i+1 << ". New ARMOR of Bodyguard: " << vec[i][j]->get_armor() << endl;
                ant_detected = true;
                return;
        }
    }
    for (int j = 0; j < vec[i].size(); j++){
        if(vec[i][j]->is_ant() == true && vec[i][j]->get_name() != "N" && vec[i][j]->get_armor() > 0){
            armor = vec[i][j]->get_armor();
            armor--;
            vec[i][j]->set_armor(armor);
            cout << "Ant at " << i+1 << " lost one armor due to Bee at "<< i+1 << ". New ARMOR of Ant: " << vec[i][j]->get_armor() << endl;
            ant_detected = true;
            return;
        }
    }

    vec[i-1].push_back(vec[i][*a]);
    vec[i].erase(vec[i].begin() + (*a) );
    cout << "Bee at " << i+1 << " moved" << endl; 
    *a = *a - 1;
    return;
}

string Bees::get_name(){ return this-> name; }

bool Bees::is_ant(){
    return false;
}