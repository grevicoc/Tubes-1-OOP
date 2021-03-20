#include "Skill.hpp"

Skill::Skill(){}

Skill::Skill(string _namaSkill, string elemen, int basePower){
    namaSkill = _namaSkill;
    unique = elemen;
    this->basePower = basePower;
}

Skill::~Skill(){}

string Skill::getNamaSkill() const{
    return namaSkill;
}
string Skill::getElemen() const{
    return unique;
}
int Skill::getBasePower() const{
    return basePower;
}

EngimonSkill::EngimonSkill(const Skill& baseSkill){
    namaSkill = baseSkill.getNamaSkill();
    basePower = baseSkill.getBasePower();
    unique = baseSkill.getElemen();
    masteryLevel = 1;
}

EngimonSkill::~EngimonSkill(){}