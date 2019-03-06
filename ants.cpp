#include "ants.hpp"

using namespace std;

Ants::Ants(){
    this-> armor = 0;
    this-> food_cost = 0;
    this-> name = "";
}

Ants::Ants(const Ants & copy){
    this-> armor = copy.armor;
    this-> food_cost = copy.food_cost;
    this-> name = copy.name;
}

Ants & Ants::operator= (const Ants & copy){
    this-> armor = copy.armor;
    this-> food_cost = copy.food_cost;
    this-> name = copy.name;
}

Ants::~Ants(){

}

int Ants::get_food_cost(){return this-> food_cost; }

string Ants::get_name(){ return this-> name; }

bool Ants::is_ant(){
    return true;
}







Harvester::Harvester(){
    this-> armor = 1;
    this-> food_cost = 2;
    this-> name = "H";
}

Thrower:: Thrower(){
    this-> armor = 1;
    this-> food_cost = 4;
    this-> name = "T";
}

void Thrower::ants_action_call(vector < vector <Insect*> > & vec, int i){
    int armor = 0;
    int a = i;
    for (int j = 0; j < vec[i].size(); j++){
        if (vec[i][j]->is_ant() == false){
            armor = vec[i][j]->get_armor();
            armor --;
            vec[i][j]->set_armor(armor);
            cout << "Bee at " << i+1 << " lost one armor due to THROWER at "<< a+1 << ". New ARMOR of bee: " << vec[i][j]->get_armor() << endl;
            return;
        }
        
    }
}


Fire:: Fire(){
    this-> armor = 1;
    this-> food_cost = 4;
    this-> name = "F";
}

void Fire::ants_action_call(vector < vector <Insect*> > & vec, int i){
    if(this->armor <= 0){
        for (int j = 0; j < vec[i].size(); j++){
            if (vec[i][j]->is_ant() == false){
                vec[i][j]->set_armor(0);
            }
        }
    }
}

Long_thrower::Long_thrower(){
    this-> armor = 1;
    this-> food_cost = 3;
    this-> name = "L";
}

void Long_thrower::ants_action_call(vector < vector <Insect*> > & vec, int i){
    int armor = 0;
    int a = i;
    if ( i < 6){
        for (i + 4; i < VEC_SIZE; i++){
            for (int j = 0; j < vec[i].size(); j++){
                if (vec[i][j]->get_armor() == 0){
                    continue;
                }
                if (j == vec[i].size() - 1){
                    if (vec[i][j]->is_ant() == false){
                        armor = vec[i][j]->get_armor();
                        armor --;
                        vec[i][j]->set_armor(armor);
                        cout << "Bee at " << i+1 << " lost one armor due to LONG THROWER at " << a+1 << ". : New ARMOR of bee: " << vec[i][j]->get_armor() << endl;
                        return;
                    }
                }
                if (vec[i][j]->is_ant() == false){
                    armor = vec[i][j]->get_armor();
                    armor --;
                    vec[i][j]->set_armor(armor);
                    cout << "Bee at " << i+1 << " lost one armor due to LONG THROWER at " << a+1 << ". : New ARMOR of bee: " << vec[i][j]->get_armor() << endl;
                }
            }
        }
    }
}

Short_thrower::Short_thrower(){
    this-> armor = 1;
    this-> food_cost = 3;
    this-> name = "S";
}

void Short_thrower::ants_action_call(vector < vector <Insect*> > & vec, int i){
    int a = i;

    if ( i < 8){
        for (i ; i <= a + 2; i++){
            cout << i << endl;
            for (int j = 0; j < vec[i].size(); j++){
                if (vec[i][j]->get_armor() == 0){
                    continue;
                }

                if (j == vec[i].size() - 1){
                    if (vec[i][j]->is_ant() == false){
                        armor = vec[i][j]->get_armor();
                        armor --;
                        vec[i][j]->set_armor(armor);
                        cout << "Bee at " << i+1 << " lost one armor due to SHORT THROWER at "<< a+1 << ". New ARMOR of Bee of bee: " << vec[i][j]->get_armor() << endl;
                        return;
                    }
                }
                if (vec[i][j]->is_ant() == false){
                    armor = vec[i][j]->get_armor();
                    armor --;
                    vec[i][j]->set_armor(armor);
                    cout << "Bee at " << i+1 << " lost one armor due to SHORT THROWER at "<< a+1 << ". New ARMOR of Bee of bee: " << vec[i][j]->get_armor() << endl;
                }
            }
        }
    }
    
}

Wall::Wall(){
    this-> armor = 4;
    this-> food_cost = 4;
    this-> name = "W";

}


Ninja::Ninja(){
    this-> armor = 1;
    this-> food_cost = 6;
    this-> name = "N";
}

void Ninja::ants_action_call(vector < vector <Insect*> > & vec, int i){
    int armor = 0;
    int a = i -1;
    for (int j = 0; j < vec[i-1].size(); j++){
        if (vec[i-1][j]->get_armor() == 0){
                    continue;
                }

        if (vec[i - 1][j]->is_ant() == false){
            armor = vec[i-1][j]->get_armor();
            armor --;
            vec[i-1][j]->set_armor(armor);
            cout << "Bee at " << i << " lost one armor due to Ninja at "<< i+1 << ". New ARMOR of Bee of bee: " << vec[i-1][j]->get_armor() << endl;
        }
    }
}

Body_guard::Body_guard(){
    this-> armor = 2;
    this-> food_cost = 4;
    this-> name = "G";
}

Queen::Queen(){
    this-> armor = 1;
    this-> food_cost = 0;
    this-> name = "Q";
}


