#include "Skill.hpp"

Skill::Skill(){}

Skill::Skill(string _namaSkill, string elemen, int basePower){
    namaSkill = _namaSkill;
    unique = elemen;
    this->basePower = basePower;
}

Skill& Skill::operator=(const Skill& other) {
    this->namaSkill = other.namaSkill;
    this->unique = other.unique;
    this->basePower = other.basePower;
    return *this;
}

Skill::~Skill(){}

string Skill::getNamaSkill() {
    return namaSkill;
}

string Skill::getElemen() {
    return unique;
}
int Skill::getBasePower() {
    return basePower;
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