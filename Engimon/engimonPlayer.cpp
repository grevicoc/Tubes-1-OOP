//File engimonPlaye.cpp
#include "engimonPlayer.hpp"

using namespace std;

EngimonPlayer::EngimonPlayer() {
    name = "XXX";
    parentsName = "XXX";
    species = "XXX";
    elements = "XXX";
    posisi = Point(-1,-1);
    level = 1;
    skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        skill[i] = Skill("Fireball", "Fire", 50);
    }
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
    this->skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        skill[i] = Skill("Fireball", "Fire", 50);
    }
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
    this->skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        skill[i] = other.skill[i];
    }
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