#include "Player.hpp"
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Inventory/Inventory.hpp"
// #include "../Point/Point.hpp"

#include <iostream>
#include <string>
using namespace std;

Player::Player(){
    posisi = Point(0,0);
}

Player::~Player(){}

EngimonPlayer& Player::getActiveEngimon() {
    return *(this->activeEngimon);
}

void Player::setActiveEngimon(EngimonPlayer* EP) {
    activeEngimon = EP;
}

void Player::displayAllEngimon(){
    // ini gatau cara akses per engimon gimana, gini bener ga?
    unordered_map<EngimonPlayer*,int> Test = engiInventory.getThings();
    unordered_map<EngimonPlayer*,int>::iterator itrTest;
    
    for (itrTest = Test.begin();itrTest!=Test.end();itrTest++){
        cout<<"======================================\n";
        cout<<"ID: "<<itrTest->first->get_idEngiPlayer()<<endl;
        cout<<"Nama: "<<itrTest->first->get_name()<<endl;
        cout<<"Level: "<<itrTest->first->get_level()<<endl;
        cout<<"======================================\n\n";
    }
}

EngimonPlayer* Player::findEngimon(int id){
    unordered_map<EngimonPlayer*,int> tempMap = engiInventory.getThings();
    unordered_map<EngimonPlayer*,int>::iterator itrTest;
    for (itrTest=tempMap.begin(); itrTest!=tempMap.end();itrTest++){
        if (itrTest->first->get_idEngiPlayer()==id){
            itrTest->first->displayEngiInfo();
            return itrTest->first;
        }
        
    }
}

void Player::switchActiveEngimon(){
    cout<<"Masukkan ID engimon: ";
    int idEngimon;
    cin>>idEngimon;
    
    EngimonPlayer* newActive = findEngimon(idEngimon);
    newActive->set_posisi(getActiveEngimon().get_posisi());
    getActiveEngimon().set_posisi(Point(-1,-1));
    
    setActiveEngimon(newActive);
    cout<<newActive->get_name()<<" berhasil menjadi aktif!\n";
}

//berdasarkan ID
void Player::displaySpecificEngimon(int id) {
    EngimonPlayer* tempEngi = findEngimon(id);
    tempEngi->displayEngiInfo();
}

void Player::displayAllSkillItem() {
    // ini gatau cara akses per engimon gimana, gini bener ga?
    unordered_map<Skill*,int> Test = skillInventory.getThings();
    unordered_map<Skill*,int>::iterator itrTest;
    int i=1;
    for (itrTest = Test.begin();itrTest!=Test.end();itrTest++){
        cout<<i<<". Item: "<<itrTest->first->getNamaSkill()<<endl;
        cout<<"   Base Power: "<<itrTest->first->getBasePower()<<endl;
        cout<<"   Elemen dibutuhkan: "<<itrTest->first->getElemen()<<endl;
        cout<<"   Jumlah saat ini: "<<itrTest->second;
    }
}

void Player::useSkillItem(){

}

// void Battle(); jadi kelas

void Player::interactActiveEngimon() {
    if (activeEngimon->get_species() == "Dragon") {
        cout << "[" << activeEngimon->get_name() << "]: Hhhuuaaaa...." << endl;  // ganti aja gaes gatau isi slogan apa
    } else if (activeEngimon->get_species() == "Cat") {
        cout << "[" << activeEngimon->get_name() << "]: Meoowww.. meoww...." << endl;  // ganti aja gaes gatau isi slogan apa
    } else if (activeEngimon->get_species() == "Bird") {
        cout << "[" << activeEngimon->get_name() << "]: Ciiuuiitt..." << endl;  // ganti aja gaes gatau isi slogan apa
    } else if (activeEngimon->get_species() == "Fish") {
        cout << "[" << activeEngimon->get_name() << "]: Mblututk...  blututk..." << endl;  // ganti aja gaes gatau isi slogan apa
    } else if (activeEngimon->get_species() == "Octopus") {
        cout << "[" << activeEngimon->get_name() << "]: Gatau ini suaranya..." << endl;  // ganti aja gaes gatau isi slogan apa
    } else if (activeEngimon->get_species() == "Plant") {
        cout << "[" << activeEngimon->get_name() << "]: ini ga bersuara:(" << endl;  // ganti aja gaes gatau isi slogan apa
    } else if (activeEngimon->get_species() == "Worm") {
        cout << "[" << activeEngimon->get_name() << "]: ini gatau juga" << endl;  // ganti aja gaes gatau isi slogan apa
    } else if (activeEngimon->get_species() == "Tiger") {
        cout << "[" << activeEngimon->get_name() << "]: Hrrgghhhh... Hauunngggg...." << endl;  // ganti aja gaes gatau isi slogan apa
    }
}

Point Player::getPosisiPlayer() {
    return this->posisi;
}

void Player::setPosisiPlayer(Point P) {
    this->posisi = P;
}

void Player::moveActiveEngimon() {  // Exception handling belom
    if (this->inputCommandMove == "up" || this->inputCommandMove == "UP") {
        if (Point::isValidPosisi(activeEngimon->get_posisiX()-1, activeEngimon->get_posisiY())) {
            activeEngimon->set_PosisiX(activeEngimon->get_posisiX()-1);
            activeEngimon->set_PosisiY(activeEngimon->get_posisiY());
        } else {
            cout << "Masih ada Player, tidak bisa pindah!" << endl;
        }
    }
    else if (this->inputCommandMove == "down" || this->inputCommandMove == "DOWN"){
        if (Point::isValidPosisi(activeEngimon->get_posisiX()+1, activeEngimon->get_posisiY())) {
            activeEngimon->set_PosisiX(activeEngimon->get_posisiX()+1);
            activeEngimon->set_PosisiY(activeEngimon->get_posisiY());
        } else {
            cout << "Masih ada Player, tidak bisa pindah!" << endl;
        }
    }
    else if (this->inputCommandMove == "right" || this->inputCommandMove == "RIGHT") {
        if (Point::isValidPosisi(activeEngimon->get_posisiX(), activeEngimon->get_posisiY()+1)) {
            activeEngimon->set_PosisiX(activeEngimon->get_posisiX());
            activeEngimon->set_PosisiY(activeEngimon->get_posisiY()+1);
        } else {
            cout << "Masih ada Player, tidak bisa pindah!" << endl;
        }
    }
    else if (this->inputCommandMove == "left" || this->inputCommandMove == "LEFT") {
        if (Point::isValidPosisi(activeEngimon->get_posisiX(), activeEngimon->get_posisiY()-1)) {
            activeEngimon->set_PosisiX(activeEngimon->get_posisiX());
            activeEngimon->set_PosisiY(activeEngimon->get_posisiY()-1);
        } else {
            cout << "Masih ada Player, tidak bisa pindah!" << endl;
        }
    }
    // ngubah peta posisi tujuan jd X dan posisi asal menjadi - atau o
}

void Player::addEngimonPlayer(EngimonPlayer* engi){
    engiInventory.addThing(engi);
    cout<<engi->get_name()<<" berhasil ditambahkan!\n";
}

void Player::addSkillItem(Skill* _skill){
    skillInventory.addThing(_skill);
    cout<<_skill->getNamaSkill()<<" berhasil ditambahkan!\n";
}

void Player::deleteEngimonPlayer(EngimonPlayer* object){
    engiInventory.deleteThing(object);
}