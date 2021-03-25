//File engimonPlayer.cpp
#include "engimonPlayer.hpp"

using namespace std;

int EngimonPlayer::numOfEngimonPlayer = 0;

EngimonPlayer::EngimonPlayer() : Engimon("Dragon", 1, Point(5,8)), idEngiPlayer(EngimonPlayer::numOfEngimonPlayer+1) {
    name = "Pikachu";
    parentsName = "Pika";
    numOfEngimonPlayer = numOfEngimonPlayer+1;
    exp = 0;
    cumExp = level*100;
}

EngimonPlayer::EngimonPlayer(Engimon& wildEngi) : Engimon(wildEngi.get_species(), wildEngi.get_level(), posisi), idEngiPlayer(EngimonPlayer::numOfEngimonPlayer+1){
    cout << "\nYou got a engimon!" << endl; cout << endl;
    wildEngi.displayEngiInfo(); cout << endl;
    //set_name(); cout << endl;
    this->parentsName = "Unknown";
    this->numOfEngimonPlayer = this->numOfEngimonPlayer+1;
    this->exp = 0;
    this->cumExp = this->level*100;
}

EngimonPlayer::EngimonPlayer(const EngimonPlayer& other) : idEngiPlayer(other.idEngiPlayer) {
    this->name = other.name;
    this->parentsName = other.parentsName;
    this->exp = other.exp;
    this->cumExp = other.cumExp;
}

EngimonPlayer::~EngimonPlayer() {
    cout<<"Engimon kamu DIED!\n";
}

EngimonPlayer& EngimonPlayer::operator=(const EngimonPlayer& other) {
    this->name = other.name;
    this->parentsName = other.parentsName;
    this->species = other.species;
    this->elements = other.elements;
    this->posisi = other.posisi;
    this->engiSkill = other.engiSkill;
    this->level = other.level;
    this->exp = other.exp;
    this->cumExp = other.cumExp;

    return *this;
}

string EngimonPlayer::get_name() {
    return this->name;
}

string EngimonPlayer::get_parentsName() {
    return this->parentsName;
}

int EngimonPlayer::get_exp() {
    return this->exp;
}

int EngimonPlayer::get_cumExp() {
    return this->cumExp;
}

int EngimonPlayer::get_idEngiPlayer() const {
    return this->idEngiPlayer;
}
void EngimonPlayer::set_name() {
    string name;
    cout << "Masukkan nama engimon : " << endl;
    cin >> name;
    this->name = name;
}

void EngimonPlayer::set_parentsName(string parentsName) {
    this->parentsName = parentsName;
}

void EngimonPlayer::set_exp(int exp) {
    this->exp = exp;
    this->cumExp += exp;
    if (exp == 100){
        this->level += exp/100;
    } else if (exp > 100) {
        this->exp += exp-100;
        this->level += exp/100;
    }
}

void EngimonPlayer::set_cumExp(int cumExp) {
    this->cumExp = cumExp;
    if (cumExp > 5000) {
        cout << "Your input is more than maximum cumExp!" << endl;
    } else if (100 <= cumExp <= 5000) {
        this->level = this->level + cumExp/100;
    }
}

void EngimonPlayer::set_PosisiX(int x) {
    this->posisi.setX(x);

}
void EngimonPlayer::set_PosisiY(int y) {
    this->posisi.setY(y);
}

void EngimonPlayer::levelUp(int exp) {
    this->cumExp += exp;
    if (this->cumExp < 5000){
        if (exp >= 100) {
            this->level = this->level+(exp/100);
            this->exp = 0;
            cout << "Your engimon is level up!" << endl;
        } else if (0 <= exp < 100){
            this->cumExp += exp;
            this->exp += exp;
        }
    } else if (this->cumExp == 5000) {
        cout << "Your engimon's level is max! Can't earn more exp! or your engimon will die!" << endl;
    } else if (this->cumExp > 5000) {
        cout << "Your engimon die" << endl;
        this->Engimon::~Engimon();
    }
}

void EngimonPlayer::displayEngiInfo() {
    cout << "~~ Profile Engimon ~~" << endl;
    cout << "Id : " << get_idEngiPlayer() << endl;
    cout << "Name : " << get_name() << endl;
    cout << "Parents Name : " << get_parentsName() << endl;
    cout << "Species : " << get_species() << endl;
    cout << "Elements : " << get_elements() << endl;
    cout << "Level : " << get_level() << endl;
    cout << "Posisi : " << "(" << get_posisiX() << ", " << get_posisiY() << ")" << endl;
    cout << "Exp : " << get_exp() << endl;
    cout << "Cumulative Exp : " << get_cumExp() << endl;
    cout << "Skill : " << endl;
    for (int i = 0 ; i < engiSkill.size(); i++) {
        cout << i+1 << ". " << engiSkill.at(i).getNamaSkill() << ", Base Power : " << engiSkill.at(i).getBasePower() << endl;
    }
}