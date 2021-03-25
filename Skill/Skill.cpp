#include "Skill.hpp"

Skill::Skill(){
    namaSkill;
    unique;
    basePower;
}

Skill::Skill(string _namaSkill, string elemen, int basePower){
    namaSkill = _namaSkill;
    unique = elemen;
    this->basePower = basePower;
}

Skill::Skill(const Skill& S){
    namaSkill = S.namaSkill;
    unique = S.unique;
    basePower = S.basePower;
}

Skill& Skill::operator=(const Skill& other) {
    this->namaSkill = other.namaSkill;
    this->unique = other.unique;
    this->basePower = other.basePower;
    return *this;
}

Skill::~Skill(){
    cout<<"Skill hilang!\n";    //buat debugging
}

string Skill::getNamaSkill() {
    return this->namaSkill;
}

string Skill::getElemen() {
    return this->unique;
}
int Skill::getBasePower() {
    return this->basePower;
}

void Skill::setNamaSkill(string namaskill){
    this->namaSkill = namaskill;
}

void Skill::setElemen(string element){
    this->unique = element;
}

void Skill::setBasePower(int base) {
    this->basePower = base;
}