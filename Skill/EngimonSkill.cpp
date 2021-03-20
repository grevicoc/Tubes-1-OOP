#include "EngimonSkill.hpp"

EngimonSkill::EngimonSkill(){}

EngimonSkill::EngimonSkill(const Skill& baseSkill){
    namaSkill = baseSkill.getNamaSkill();
    basePower = baseSkill.getBasePower();
    unique = baseSkill.getElemen();
    masteryLevel = 1;
}

EngimonSkill::~EngimonSkill(){}

int EngimonSkill::damage(){
    return basePower*masteryLevel;
}