//File engimonPlaye.cpp
#include "engimonPlayer.hpp"

using namespace std;

EngimonPlayer::EngimonPlayer() {
    name = "XXX";
    parentsName = "XXX";
    Engimon::Engimon();
    exp = 0;
    cumExp = level*100;
}

EngimonPlayer::EngimonPlayer(Engimon& wildEngi) {
    cin << "Masukkan nama engimon : " << this->name << endl;
    this->parentsName = NULL;
    this->species = wildEngi.species;
    this->elements = wildEngi.elements;
    this->level = wildEngi.level;
    this->posisi - wildEngi.posisi;
    this->exp = 0;
    this->cumExp = this->level*100;
}

EngimonPlayer::EngimonPlayer(const EngimonPlayer& other) {
    this->name = other.name;
    this->parentsName = other.parentsName;
    this->species = other.species;
    this->elements = other.elements;
    this->posisi = other.posisi;
    this->level = other.level;
    this->exp = other.exp;
    this->cumExp = other.cumExp;
}

EngimonPlayer::~EngimonPlayer() {
    cout << "Your Engimon's has been dead" << endl;
}

EngimonPlayer& EngimonPlayer::operator=(const EngimonPlayer& other) {
    this->name = other.name;
    this->parentsName = other.parentsName;
    this->species = other.species;
    this->elements = other.elements;
    this->posisi = other.posisi;
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