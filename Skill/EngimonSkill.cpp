#include "EngimonSkill.hpp"

EngimonSkill::EngimonSkill(){}

EngimonSkill::EngimonSkill(Skill& baseSkill){
    namaSkill = baseSkill.getNamaSkill();
    basePower = baseSkill.getBasePower();
    unique = baseSkill.getElemen();
    masteryLevel = 1;
}

EngimonSkill::~EngimonSkill(){}

string EngimonSkill::getEngimonNamaSkill() {
    return this->namaSkill;
}

string EngimonSkill::getEngimonElemen() {
    return this->unique;
}
int EngimonSkill::getEngimonBasePower() {
    return this->basePower;
}

void EngimonSkill::setEngimonNamaSkill(string namaskill){
    this->namaSkill = namaskill;
}

void EngimonSkill::setEngimonElemen(string element){
    this->unique = element;
}

void EngimonSkill::setEngimonBasePower(int base) {
    this->basePower = base;
}

int EngimonSkill::damage(){
    return basePower*masteryLevel;
}

int EngimonSkill::getMasteryLevel() {
    return this->masteryLevel;
}

void EngimonSkill::setMasteryLevel(int masteryLevel) {
    this->masteryLevel = masteryLevel;
}