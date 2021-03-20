//File engimon.cpp
#include "engimon.hpp"

using namespace std;

Engimon::Engimon() {
    species = "XXX";
    elements = "XXX";
    level = 1;
    posisi = Point();
    skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        skill[i] = Skill("Fireball", "Api", 50);
    }
}
Engimon::Engimon(string species, int level, Point posisi) {
    if (species == "Dragon" || species == "dragon") {
        set_species(species);
        set_elements("Fire");
    } else if (species == "Cat" || species == "cat") {
        set_species(species);
        set_elements("Electric");
    } else if (species == "Bird" || species == "bird") {
        set_species(species);
        set_elements("Water/Ice");
    } else if (species == "Fish" || species == "fish") {
        set_species(species);
        set_elements("Water");
    } else if (species == "Octopus" || species == "octopus") {
        set_species(species);
        set_elements("Ice");
    } else if (species == "Plant" || species == "plant") {
        set_species(species);
        set_elements("Ground");
    } else if (species == "Worm" || species == "worm") {
        set_species(species);
        set_elements("Water/Ground");
    } else if (species == "Tiger" || species == "tiger") {
        set_species(species);
        set_elements("Fire/Electric");
    }
    this->level = 1;
    this->posisi = posisi;
    this->skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        skill[i] = Skill("Fireball", "Api", 50);
    }
}
Engimon::Engimon(const Engimon& otherEngimon) {
    //skill = new Skill[4];

    //for (int i = 0; i < 4; i++){
    //    this->skill[i] = otherEngimon.skill[i];
    //}
    this->species = otherEngimon.species;
    this->elements = otherEngimon.elements;
    this->level = otherEngimon.level;
    this->posisi = otherEngimon.posisi;
    skill = new Skill[4];
    for (int i = 0; i < 4; i++) {
        this->skill = otherEngimon.skill;
    }
}
Engimon::~Engimon() {
    delete [] skill;
    cout << "Engimon's has been dead!" << endl;
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
string Engimon::get_species(){
    return this->species;
}
string Engimon::get_elements(){
    return this->elements;
}
int Engimon::get_level(){
    return this->level;
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

void Engimon::displayEngiInfo(){
    cout << "~~ Profile Engimon ~~" << endl;
    cout << "Species : " << get_species() << endl;
    cout << "Elements : " << get_elements() << endl;
    cout << "Level : " << get_level() << endl;
    cout << "Posisi : " << "(" << posisi.getX() << ", " << posisi.getY() << ")" << endl;
    cout << "Skill : " << endl;
    for (int i = 0 ; i < 4; i++) {
         cout << i+1 << ". " << skill[i].getNamaSkill() << endl;
    }
}