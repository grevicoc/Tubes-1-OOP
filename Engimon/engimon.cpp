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
        skill[i] = Skill("XXX", this->elements, 50);
    }
}
Engimon::Engimon(string species, int level, Point posisi) {
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
    this->level = 1;
    this->posisi = posisi;
    this->skill = new Skill[4];
    
    if (species == "Dragon" || species == "dragon") {
        string list_skill[4] = {"Fire Ball", "Fire Claw", "Fire Breathe", "Fire Punch"};
        int list_basePower[4] = {50, 100, 150, 110};
        for (int i = 0; i < 4; i++){
            skill[i].setNamaSkill(list_skill[i]);
            skill[i].setElemen(this->elements);
            skill[i].setBasePower(list_basePower[i]);
        }
    } else if (species == "Cat" || species == "cat") {
        string list_skill[4] = {"Electric Ball", "Electric Claw", "Electric Slash", "Giga Volt"};
        int list_basePower[4] = {65, 105, 140, 200};
        for (int i = 0; i < 4; i++){
            skill[i].setNamaSkill(list_skill[i]);
            skill[i].setElemen(this->elements);
            skill[i].setBasePower(list_basePower[i]);
        }
    } else if (species == "Bird" || species == "bird") {
        string list_skill[4] = {"Ice Ball", "Ice Smash", "Water Spread", "Water Bomb"};
        int list_basePower[4] = {45, 60, 130, 190};
        for (int i = 0; i < 4; i++){
            skill[i].setNamaSkill(list_skill[i]);
            skill[i].setElemen(this->elements);
            skill[i].setBasePower(list_basePower[i]);
        }
    } else if (species == "Fish" || species == "fish") {
        string list_skill[4] = {"Water Ball", "Water Float", "Water Spread", "Water Bomb"};
        int list_basePower[4] = {48, 65, 130, 190};
        for (int i = 0; i < 4; i++){
            skill[i].setNamaSkill(list_skill[i]);
            skill[i].setElemen(this->elements);
            skill[i].setBasePower(list_basePower[i]);
        }
    } else if (species == "Octopus" || species == "octopus") {
        string list_skill[4] = {"Ice Ball", "Ice Smash", "Ice punch", "Ice Bomb"};
        int list_basePower[4] = {55, 75, 145, 195};
        for (int i = 0; i < 4; i++){
            skill[i].setNamaSkill(list_skill[i]);
            skill[i].setElemen(this->elements);
            skill[i].setBasePower(list_basePower[i]);
        }
    } else if (species == "Plant" || species == "plant") {
        string list_skill[4] = {"Ground Ball", "Ground Punch", "Ground Smash", "Ground Bomb"};
        int list_basePower[4] = {60, 80, 145, 198};
        for (int i = 0; i < 4; i++){
            skill[i].setNamaSkill(list_skill[i]);
            skill[i].setElemen(this->elements);
            skill[i].setBasePower(list_basePower[i]);
        }
    } else if (species == "Worm" || species == "worm") {
        string list_skill[4] = {"Water Ball", "Ground Punch", "Water Spread", "Ground Bomb"};
        int list_basePower[4] = {48, 80, 130, 198};
        for (int i = 0; i < 4; i++){
            skill[i].setNamaSkill(list_skill[i]);
            skill[i].setElemen(this->elements);
            skill[i].setBasePower(list_basePower[i]);
        }
    } else if (species == "Tiger" || species == "tiger") {
        string list_skill[4] = {"Fire Ball", "Electric Claw", "Fire Breathe", "Giga Volt"};
        int list_basePower[4] = {50, 105, 150, 200};
        for (int i = 0; i < 4; i++){
            skill[i].setNamaSkill(list_skill[i]);
            skill[i].setElemen(this->elements);
            skill[i].setBasePower(list_basePower[i]);
        }
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
int Engimon::get_posisiX(){
    return this->posisi.getX(); 
}
int Engimon::get_posisiY(){
    return this->posisi.getY(); 
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
    cout << "Posisi : " << "(" << get_posisiX() << ", " << get_posisiY() << ")" << endl;
    cout << "Skill : " << endl;
    for (int i = 0 ; i < 4; i++) {
         cout << i+1 << ". " << skill[i].getNamaSkill() << ", Base Power : " << skill[i].getBasePower() << endl;
    }
}