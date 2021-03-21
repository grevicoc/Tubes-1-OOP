//File engimonPlayer.cpp
#include "engimonPlayer.hpp"

using namespace std;

int EngimonPlayer::numOfEngimonPlayer = 0;

EngimonPlayer::EngimonPlayer() : idEngiPlayer(EngimonPlayer::numOfEngimonPlayer+1) {
    name = "Pikachu";
    parentsName = "Pika";
    species = "Cat";
    elements = "Electric";
    numOfEngimonPlayer = numOfEngimonPlayer+1;
    posisi = Point(5,8);
    level = 1;
    skill = new Skill[4];
    string list_skill[4] = {"Electric Ball", "Electric Claw", "Electric Slash", "Giga Volt"};
    int list_basePower[4] = {65, 105, 140, 200};
    for (int i = 0; i < 4; i++){
        skill[i].setNamaSkill(list_skill[i]);
        skill[i].setElemen(this->elements);
        skill[i].setBasePower(list_basePower[i]);
    }
    exp = 0;
    cumExp = level*100;
}

EngimonPlayer::EngimonPlayer(Engimon& wildEngi) : idEngiPlayer(EngimonPlayer::numOfEngimonPlayer+1){
    cout << "You got a engimon!" << endl; cout << endl;
    wildEngi.displayEngiInfo(); cout << endl;
    set_name(this->name); cout << endl;
    this->parentsName = "-";
    this->numOfEngimonPlayer = this->numOfEngimonPlayer+1;
    this->species = wildEngi.get_species();
    this->elements = wildEngi.get_elements();
    this->level = wildEngi.get_level();
    this->posisi.setX(wildEngi.get_posisiX());
    this->posisi.setY(wildEngi.get_posisiY());
    this->skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        this->skill[i] = wildEngi.skill[i];
    }
    this->exp = 0;
    this->cumExp = this->level*100;
}

EngimonPlayer::EngimonPlayer(const EngimonPlayer& other) : idEngiPlayer(other.idEngiPlayer) {
    this->name = other.name;
    this->parentsName = other.parentsName;
    this->species = other.species;
    this->elements = other.elements;
    this->posisi = other.posisi;
    this->level = other.level;
    this->skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        skill[i] = other.skill[i];
    }
    this->exp = other.exp;
    this->cumExp = other.cumExp;
}

EngimonPlayer::~EngimonPlayer() {
    delete [] skill;
}

EngimonPlayer& EngimonPlayer::operator=(const EngimonPlayer& other) {
    this->name = other.name;
    this->parentsName = other.parentsName;
    this->species = other.species;
    this->elements = other.elements;
    this->posisi = other.posisi;
    skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        skill[i] = other.skill[i];
    }
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
}

void EngimonPlayer::set_cumExp(int cumExp) {
    this->cumExp = cumExp;
}

void EngimonPlayer::set_PosisiX(int x) {
    this->posisi.setX(x);

}
void EngimonPlayer::set_PosisiY(int y) {
    this->posisi.setY(y);
}

void EngimonPlayer::levelUp(int exp) {
    if (this->cumExp < 5000) {
        this->cumExp += exp;
        this->level = this->level+(exp/100);
        cout << "Your engimon is level up!" << endl;
    } else {
        cout << "Your engimon's level is max!" << endl;
    }
}

void EngimonPlayer::maksCumExp() {
    // if (this->cumExp >= 5000) {
    //     if (levelUp(exp)) {
    //         ~EngimonPlayer();
    //     }
    // }
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
    for (int i = 0 ; i < 4; i++) {
        cout << i+1 << ". " << skill[i].getNamaSkill() << ", Base Power : " << skill[i].getBasePower() << endl;
    }
}