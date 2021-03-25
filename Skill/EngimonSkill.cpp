#include "EngimonSkill.hpp"

EngimonSkill::EngimonSkill(): Skill(){}

EngimonSkill::EngimonSkill(const Skill& baseSkill): Skill(baseSkill){
    masteryLevel = 1;
}

EngimonSkill::EngimonSkill(const EngimonSkill& ES){
    namaSkill = ES.namaSkill;
    basePower = ES.basePower;
    unique = ES.unique;
    masteryLevel = ES.masteryLevel;
}
        
EngimonSkill& EngimonSkill::operator=(const EngimonSkill& other){
    this->namaSkill = other.getNamaSkill();
    this->unique = other.getElemen();
    this->basePower = other.getBasePower();
    this->masteryLevel = other.getMasteryLevel();
    return *this;
}

EngimonSkill::~EngimonSkill(){}

int EngimonSkill::damage(){
    return basePower*masteryLevel;
}

int EngimonSkill::getMasteryLevel() const{
    return this->masteryLevel;
}

void EngimonSkill::setMasteryLevel(int masteryLevel) {
    this->masteryLevel = masteryLevel;
}