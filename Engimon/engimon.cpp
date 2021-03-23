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
    skill = new Skill[4];   //biarin kosong dulu aja
    // for (int i = 0; i < 4; i++){
    //     skill[i] = Skill("XXX", this->elements, 50);
    // }
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
    this->level = 1;
    this->numOfEngimon = this->numOfEngimon+1;
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
Engimon::Engimon(const Engimon& otherEngimon) : id(otherEngimon.id) {
    this->species = otherEngimon.species;
    this->elements = otherEngimon.elements;
    this->level = otherEngimon.level;
    this->posisi = otherEngimon.posisi;
    skill = new Skill[4];
    for (int i = 0; i < 4; i++) {
        this->skill[i] = otherEngimon.skill[i];
    }
}
Engimon::~Engimon(){
    // delete[] skill;  //masalahnya di sini gara2 engimonPlayer ngedelete skill tp karena engimonPlayer turunan dari engimon, waktu dia ngedestroy parentnya ngedelete skill lagi (2x delete skill)
    cout<<"DESTRUCTOR ENGIMON\n";
}
Engimon& Engimon::operator=(const Engimon& otherEngimon) {
    delete [] skill;
    this->species = otherEngimon.species;
    this->elements = otherEngimon.elements;
    this->level = otherEngimon.level;
    skill = new Skill[4];
    for (int i = 0; i < 4; i++){
        skill[i] = otherEngimon.skill[i];
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
int Engimon::get_id() const{
    return this->id;
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
    cout << "Id : " << get_id() << endl;
    cout << "Species : " << get_species() << endl;
    cout << "Elements : " << get_elements() << endl;
    cout << "Level : " << get_level() << endl;
    cout << "Posisi : " << "(" << get_posisiX() << ", " << get_posisiY() << ")" << endl;
    cout << "Skill : " << endl;
    for (int i = 0 ; i < 4; i++) {
        cout << i+1 << ". " << skill[i].getNamaSkill() << ", Base Power : " << skill[i].getBasePower() << endl;
    }
}

int Engimon::powerEngimon(Engimon& other) {
    int power = 0;
    int sum = 0;
    engiSkill = new EngimonSkill[4];
    for (int i = 0; i<4; i++){
        engiSkill[i] = skill[i];
    }
    for (int k = 0; k<4; k++){
        sum = sum + engiSkill[k].damage();
    }
    if (this->elements == "Fire" && other.elements == "Water") {
        power = this->level*0+sum;
    } else if (this->elements == "Water" && other.elements == "Fire") {
        power = this->level*2+sum;
    } else if (this->elements == "Fire" && other.elements == "Fire") {
        power = this->level*1+sum;
    } else if (this->elements == "Water" && other.elements == "Water") {
        power = this->level*1+sum;
    } else if (this->elements == "Fire" && other.elements == "Electric") {
        power = this->level*1+sum;
    } else if (this->elements == "Electric" && other.elements == "Fire") {
        power = this->level*1+sum;
    } else if (this->elements == "Electric" && other.elements == "Electric") {
        power = this->level*1+sum;
    } else if (this->elements == "Fire" && other.elements == "Ground") {
        power = this->level*0.5+sum;
    } else if (this->elements == "Ground" && other.elements == "Fire") {
        power = this->level*1.5+sum;
    } else if (this->elements == "Ground" && other.elements == "Ground") {
        power = this->level*1+sum;
    } else if (this->elements == "Fire" && other.elements == "Ice") {
        power = this->level*2+sum;
    } else if (this->elements == "Ice" && other.elements == "Fire") {
        power = this->level*0+sum;
    } else if (this->elements == "Ice" && other.elements == "Ice") {
        power = this->level*1+sum;
    } else if (this->elements == "Water" && other.elements == "Electric") {
        power = this->level*0+sum;
    } else if (this->elements == "Electric" && other.elements == "Water") {
        power = this->level*2+sum;
    } else if (this->elements == "Water" && other.elements == "Ground") {
        power = this->level*1+sum;
    } else if (this->elements == "Ground" && other.elements == "Water") {
        power = this->level*1+sum;
    } else if (this->elements == "Water" && other.elements == "Ice") {
        power = this->level*1+sum;
    } else if (this->elements == "Ice" && other.elements == "Water") {
        power = this->level*1+sum;
    } else if (this->elements == "Electric" && other.elements == "Ground") {
        power = this->level*0+sum;
    } else if (this->elements == "Ground" && other.elements == "Electric") {
        power = this->level*2+sum;
    } else if (this->elements == "Electric" && other.elements == "Ice") {
        power = this->level*1.5+sum;
    } else if (this->elements == "Ice" && other.elements == "Electric") {
        power = this->level*0.5+sum;
    }
    return power;
}