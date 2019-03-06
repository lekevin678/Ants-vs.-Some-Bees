#include "user.hpp"

using namespace std;

User::User(){
    this-> food_bank = 50;
}

int get_int (string prompt) {
    int new_int = 0;
    for (int a = 0; a < prompt.length(); a++) {
        if (prompt[a] == 48) {
            continue;
        }
        else {
            new_int += (prompt[a] - 48) * pow(10, (prompt.length() - 1 - a));
        }
    }
    return new_int;
}

bool is_int(string num) {
    for (int a = 0; a < num.length(); a++) {
        if (num[a] >= 48 && num[a] <= 57) {
        }
        else {
            return false;
        }
    }
    return true;
}

bool User::valid_place(vector < vector <Insect*> > & vec, int k){
    int i = k-1;
    bool ant_detected = false;
    for (int j = 0; j < vec[i].size(); j++){
        if (vec[i][j]->get_name() == "G"){
            return false;
        }
        if (vec[i][j]->is_ant() == true){
            ant_detected == true;
        }

        if (ant_detected == false){
            return true;
        }
    }

    if (vec[i].size() == 0){
        return true;
    }

    return false;
}

void User::minus_food(string input){
    if (input == "1"){
        this-> food_bank -= 2;
    }
    if (input == "2"){
        this-> food_bank -= 4;
    }
    if (input == "3"){
        this-> food_bank -= 4;
    }
    if (input == "4"){
        this-> food_bank -= 3;
    }
    if (input == "5"){
        this-> food_bank -= 3;
    }
    if (input == "6"){
        this-> food_bank -= 4;
    }
    if (input == "7"){
        this-> food_bank -= 6;
    }
    if (input == "8"){
        this-> food_bank -= 4;
    }

    cout << "Food Bank: " << this-> food_bank << endl;
}

void User::place_ant(vector < vector <Insect*> > & vec, int i, string input){
    string empty;
    i --;
    if (input == "1"){
        vec[i].push_back(new Harvester);
    }
    if (input == "2"){
        vec[i].push_back(new Thrower);
    }
    if (input == "3"){
        vec[i].push_back(new Fire);
    }
    if (input == "4"){
        vec[i].push_back(new Long_thrower);
    }
    if (input == "5"){
        vec[i].push_back(new Short_thrower);
    }
    if (input == "6"){
        vec[i].push_back(new Wall);
    }
    if (input == "7"){
        vec[i].push_back(new Ninja);
    }
    if (input == "8"){
        vec[i].push_back(new Body_guard);
    }
    if (input == "0"){
        
    }
    minus_food(input);
    display_board(vec);
    cout << "                   press ENTER for ant attack." << endl;
    getline(cin, empty);
}

void User::print_ask_ant(vector < vector <Insect*> > & vec){
    string input = "";
    string place = "";
    int selection = 0;
    int temp = 0;
    cout << "1 : " << "Harvester        (H)" << endl;
    cout << "2 : " << "Thrower          (T)" << endl;
    cout << "3 : " << "Fire             (F)" << endl;
    cout << "4 : " << "Long Thrower     (L)" << endl;
    cout << "5 : " << "Short Thrower    (S)" << endl;
    cout << "6 : " << "Wall             (W)" << endl;
    cout << "7 : " << "Ninja            (N)" << endl;
    cout << "8 : " << "Bodyguard        (G)" << endl;
    cout << endl;
    cout << "0 : " << "NONE" << endl;
    cout << endl;
    do{
        cout<< "Which ANT?" << endl;
        getline(cin, input);
        selection = get_int(input);
    } while(selection < 0 || selection > 8);
    if(input != "0"){
        do{
            display_board(vec);
            cout<< "Where on the board?" << endl;
            getline(cin, place);
            temp = get_int(place);
        } while( (temp > 10 || temp <= 0) || valid_place(vec, temp) == false );

        place_ant(vec, temp, input);
    }   
}

void User::ant_attack(vector < vector <Insect*> > & vec, User & user){
    string empty;
    for (int i = 0; i < VEC_SIZE; i++){
        for (int j = 0; j < vec[i].size(); j++){
            if ( j < vec[i].size()){
                if (vec[i][j]->get_name() == "H"){
                    this->food_bank ++;
                    cout << "Harvester increased food bank by one: " << this-> food_bank << endl;
                }
                if (vec[i][j]->is_ant() == true){
                    vec[i][j]->ants_action_call(vec,i);
                }
            }
        }
    }
    for (int i = 0; i < VEC_SIZE; i++){
        for (int j = vec[i].size() - 1 ; j >= 0; j-- ){
            vec[i][j]->remove_from_vec(vec, i,j);
        }
    }
    cout << "                   press ENTER for bee attack." << endl;
    getline(cin, empty);
}

void User::bee_action(vector < vector <Insect*> > & vec){
    int counter = 0;
    for (int i = 0; i < VEC_SIZE; i++){
        for (int j = 0; j < vec[i].size(); j++){
            if (vec[i][j]->is_ant() == false){
                counter ++;
            }
        }
    }
    for (int i = 0; i < VEC_SIZE; i++){
        for (int j = 0; j < vec[i].size(); j++){
            if (vec[i][j]->is_ant() == false){
                vec[i][j]->bees_action_call(vec, i, & j);
                continue;
            }
        }
    }

    for (int i = 0; i < VEC_SIZE; i++){
        for (int j = vec[i].size() - 1 ; j >= 0; j-- ){
            vec[i][j]->remove_from_vec(vec, i,j);
        }
    }

    display_board(vec);
}

bool User::end_game_check(vector < vector <Insect*> > & vec){
    bool bee_detected = false;

    for (int i = 0 ; i < vec[0].size(); i++){
        if (vec[0][i]->is_ant() == false){
            cout << "You lost. A Bee has reached your Queen." << endl;
            return true;
        }
    }

    return false;
}


void User::game_loop(vector < vector <Insect*> > & vec, User & user){
    bool end = false;
    string empty = "";
    do{
        vec[9].push_back( new Bees );
        display_board( vec);
        print_ask_ant(vec);
        ant_attack(vec, user);
        bee_action(vec);
        cout << "                   press ENTER for next round." << endl;
        getline(cin, empty);
    } while (end_game_check(vec) == false);
}

void User::game_setup(vector < vector <Insect*> > & vec){
    vec[0].push_back( new Queen);   
}

void User::display_board(vector < vector <Insect*> > & vec){
    int temp = 0;
    for (int i = 0; i < vec.size(); i++){
        if (vec[i].size() > temp){
            temp = vec[i].size();
        }
        else{
            continue;
        }
    }
    for (int i = 0 ; i < VEC_SIZE; i++){
        cout << "   " << i + 1 << "  ";
    }
    cout << endl;
    for (int j = 0; j < temp; j++){
        for (int i = 0; i < VEC_SIZE; i++){
            if ( j < vec[i].size()){
                if(i == VEC_SIZE - 1){
                    cout << "|  " << vec[i][j]->get_name() << "  |";
                }
                else{
                    cout << "|  " << vec[i][j]->get_name() << "  ";
                }
            }
            else {
                if(i == VEC_SIZE - 1){
                    cout << "|  " << " " << "  |";
                }
                else{
                    cout << "|  " << " " << "  ";
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}