//File engimon.cpp
#include "engimon.hpp"

using namespace std;

Engimon::Engimon() {
    name = "XXX";
    parentsName = "XXX";
    species = "XXX";
    elements = "XXX";
    exp = 0;
    level = 1;
    cumExp = 0;
    //skill = new Skill[4];
}
Engimon::Engimon(string name, string parentsName, string species, string elements) {
    this->name = name;
    this->parentsName = parentsName;
    this->species = species;
    this->elements = elements;
    this->exp = 0;
    this->cumExp = 0;
    this->level = 1;
    //skill = new Skill[4];
}
Engimon::Engimon(const Engimon& otherEngimon) {
    //skill = new Skill[4];

    //for (int i = 0; i < 4; i++){
    //    this->skill[i] = otherEngimon.skill[i];
    //}

    this->name = otherEngimon.name;
    this->parentsName = otherEngimon.parentsName;
    this->species = otherEngimon.species;
    this->elements = otherEngimon.elements;
    this->exp = otherEngimon.exp;
    this->cumExp = otherEngimon.cumExp;
    this->level = otherEngimon.level;
}
Engimon::~Engimon() {
    //delete [] skill;
    cout << get_name() << "'s has been dead!" << endl;
}
Engimon& Engimon::operator=(const Engimon& otherEngimon) {
    // if (this != &otherEngimon){
    //     delete [] skill;
    //     skill = nullptr;
    //     skill = new Skill[4];
    //     copy(otherEngimon.skill, 4+otherEngimon.skill, skill);
    // }
    return *this;
}
string Engimon::get_name(){
    return this->name;
}
string Engimon::get_parentsName(){
    return this->parentsName;
}
string Engimon::get_species(){
    return this->species;
}
string Engimon::get_elements(){
    return this->elements;
}
int Engimon::get_level(){
    return this->level;
}
int Engimon::get_exp(){
    return this->exp;
}
int Engimon::get_cumExp(){
    return this->cumExp;
}
string Engimon::get_ability() const {
    return this->ability;
}
string Engimon::get_nature() const {
    return this->nature;
}
void Engimon::set_name(string _name){
    this->name = _name;
}
void Engimon::set_parentsName(string _parentsName){
    this->parentsName = _parentsName;
}
void Engimon::set_species(string _species){
    this->species = _species;
}
void Engimon::set_elements(string _elements){
    this->elements = _elements;
}
void Engimon::set_ability(string _ability){
    this->ability = _ability;
}
void Engimon::set_nature(string _nature){
    this->nature = _nature;
}
void Engimon::set_level(int _level){
    this->level = _level;
}
void Engimon::set_exp(int _exp){
    this->exp = _exp;
}
void Engimon::set_cumExp(int _cumExp){
    this->cumExp = _cumExp;
}
void Engimon::levelUP(int exp){
    if (exp <= 4900) {
        if (this->level <= 50 && this->exp%100==0){
            this->level = this->level+(exp/100);
            this->cumExp += exp;
            cout << get_name() << " is Level Up!" << endl;
        }
    }
}
void Engimon::maksCumExp(){
    if (this->level>50 && this->cumExp > 4900){
        return;
    } else if (this->level == 50 && this->cumExp == 4900){
        cout << get_name() << " has reach the maximum level!" << endl;
    }
}
void Engimon::displayEngiInfo(){
    cout << "~~ Profile Engimon ~~" << endl;
    cout << "Name : " << get_name() << endl;
    cout << "Parent Name : " << get_parentsName() << endl;
    cout << "Species : " << get_species() << endl;
    cout << "Elements : " << get_elements() << endl;
    cout << "Level : " << get_level() << endl;
    cout << "Exp : " << get_exp() << endl;

    // for (int i = 0 ; i < 4; i++){
    //     cout << "Skill : " << endl
    //     cout << i+1 << ". " << skill[i] << endl;
    // }
}