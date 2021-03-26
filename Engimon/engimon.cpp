//File engimon.cpp
#include "engimon.hpp"

using namespace std;

int Engimon::numOfEngimon = 0;

Engimon::Engimon() : id(Engimon::numOfEngimon+1) {
    species = "XXX";
    elements = "XXX";
    level = 1;
    numOfEngimon = numOfEngimon+1;
    posisi = Point();
}
Engimon::Engimon(string species, int level, Point posisi) : id(Engimon::numOfEngimon+1) {
    if (species == "Dragon" || species == "dragon") {
        set_elements("Fire");
    } else if (species == "Cat" || species == "cat") {
        set_elements("Electric");
    } else if (species == "Bird" || species == "bird") {
        set_elements("Water/Ice");
    } else if (species == "Fish" || species == "fish") {
        set_elements("Water");
    } else if (species == "Octopus" || species == "octopus") {
        set_elements("Ice");
    } else if (species == "Plant" || species == "plant") {
        set_elements("Ground");
    } else if (species == "Worm" || species == "worm") {
        set_elements("Water/Ground");
    } else if (species == "Tiger" || species == "tiger") {
        set_elements("Fire/Electric");
    }
    this->species = species;
    this->level = level;
    this->numOfEngimon = this->numOfEngimon+1;
    this->posisi.setX(posisi.getX());
    this->posisi.setY(posisi.getY());
    
    if (species == "Dragon" || species == "dragon") {
        string list_skill[4] = {"Fire Ball", "Fire Claw", "Fire Breathe", "Fire Punch"};
        int list_basePower[4] = {50, 100, 150, 180};
        for (int i = 0; i < 4; i++){
            EngimonSkill skill = EngimonSkill(list_skill[i], list_basePower[i], this->elements);  
            engiSkill.push_back(skill);
        }
    } else if (species == "Cat" || species == "cat") {
        string list_skill[4] = {"Electric Ball", "Electric Claw", "Electric Slash", "Giga Volt"};
        int list_basePower[4] = {65, 105, 140, 185};
        for (int i = 0; i < 4; i++){
            EngimonSkill skill = EngimonSkill(list_skill[i], list_basePower[i], this->elements);  
            engiSkill.push_back(skill);
        }
    } else if (species == "Bird" || species == "bird") {
        string list_skill[4] = {"Ice Ball", "Ice Smash", "Water Spread", "Water Bomb"};
        int list_basePower[4] = {45, 60, 130, 190};
        for (int i = 0; i < 4; i++){
            EngimonSkill skill = EngimonSkill(list_skill[i], list_basePower[i], this->elements);  
            engiSkill.push_back(skill);
        }
    } else if (species == "Fish" || species == "fish") {
        string list_skill[4] = {"Water Ball", "Water Float", "Water Spread", "Water Bomb"};
        int list_basePower[4] = {48, 65, 130, 190};
        for (int i = 0; i < 4; i++){
            EngimonSkill skill = EngimonSkill(list_skill[i], list_basePower[i], this->elements);  
            engiSkill.push_back(skill);
        }
    } else if (species == "Octopus" || species == "octopus") {
        string list_skill[4] = {"Ice Ball", "Ice Smash", "Ice punch", "Ice Bomb"};
        int list_basePower[4] = {55, 75, 145, 180};
        for (int i = 0; i < 4; i++){
            EngimonSkill skill = EngimonSkill(list_skill[i], list_basePower[i], this->elements);  
            engiSkill.push_back(skill);
        }
    } else if (species == "Plant" || species == "plant") {
        string list_skill[4] = {"Ground Ball", "Ground Punch", "Ground Smash", "Ground Bomb"};
        int list_basePower[4] = {60, 80, 145, 180};
        for (int i = 0; i < 4; i++){
            EngimonSkill skill = EngimonSkill(list_skill[i], list_basePower[i], this->elements);  
            engiSkill.push_back(skill);
        }
    } else if (species == "Worm" || species == "worm") {
        string list_skill[4] = {"Water Ball", "Ground Punch", "Water Spread", "Ground Bomb"};
        int list_basePower[4] = {48, 80, 130, 180};
        for (int i = 0; i < 4; i++){
            EngimonSkill skill = EngimonSkill(list_skill[i], list_basePower[i], this->elements);  
            engiSkill.push_back(skill);
        }
    } else if (species == "Tiger" || species == "tiger") {
        string list_skill[4] = {"Fire Ball", "Electric Claw", "Fire Breathe", "Giga Volt"};
        int list_basePower[4] = {50, 105, 150, 185};
        for (int i = 0; i < 4; i++){
            EngimonSkill skill = EngimonSkill(list_skill[i], list_basePower[i], this->elements);  
            engiSkill.push_back(skill);
        }
    }
}
Engimon::Engimon(const Engimon& otherEngimon) : id(otherEngimon.id) {
    this->species = otherEngimon.species;
    this->elements = otherEngimon.elements;
    this->level = otherEngimon.level;
    this->posisi = otherEngimon.posisi;
    this->engiSkill = otherEngimon.getEngiSkill();
}
Engimon::~Engimon(){}
Engimon& Engimon::operator=(const Engimon& otherEngimon) {
    this->species = otherEngimon.species;
    this->elements = otherEngimon.elements;
    this->level = otherEngimon.level;
    for (int i = 0; i < engiSkill.size(); i++){
        engiSkill.at(i) = otherEngimon.engiSkill.at(i);
    }
    return *this;
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
int Engimon::get_posisiX(){
    return this->posisi.getX(); 
}
int Engimon::get_posisiY(){
    return this->posisi.getY(); 
}
Point Engimon::get_posisi() {
    return this->posisi;
}
int Engimon::get_id() const{
    return this->id;
}
void Engimon::set_posisi(Point P){
    posisi.setX(P.getX());
    posisi.setY(P.getY());
}
void Engimon::set_species(string _species){
    this->species = _species;
}
void Engimon::set_elements(string _elements){
    this->elements = _elements;
}
void Engimon::set_level(int _level){
    this->level = _level;
}
vector<EngimonSkill> Engimon::getEngiSkill() const{
    return engiSkill;
}
void Engimon::displayEngiInfo(){
    cout << "~~ Profile Engimon ~~" << endl;
    cout << "Id : " << get_id() << endl;
    cout << "Species : " << get_species() << endl;
    cout << "Elements : " << get_elements() << endl;
    cout << "Level : " << get_level() << endl;
    cout << "Posisi : " << "(" << get_posisiX() << ", " << get_posisiY() << ")" << endl;
    cout << "Skill : " << endl;
    for (int i = 0 ; i < engiSkill.size(); i++) {
        cout << i+1 << ". " << engiSkill.at(i).getNamaSkill() << ", Base Power : " << engiSkill.at(i).getBasePower() << endl;
    }
}
