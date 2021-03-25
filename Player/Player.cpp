#include "Player.hpp"
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Inventory/Inventory.hpp"
// #include "../Point/Point.hpp"

#include <iostream>
#include <string>
using namespace std;

Player::Player(){}

Player::~Player(){}

EngimonPlayer& Player::getActiveEngimon() {
    return *(this->activeEngimon);
}

void Player::setActiveEngimon(EngimonPlayer* EP) {
    int i, j;
    i = this->activeEngimon->get_posisiX();
    j = this->activeEngimon->get_posisiY();
    this->activeEngimon = EP;
    this->activeEngimon->set_PosisiX(i);
    this->activeEngimon->set_PosisiY(j);
}

// void Player::Bergerak() {
//     if (this->inputCommandMove == "up" || this->inputCommandMove == "UP") {
//         if (posisi.isValidPosisiRelatif(-1, 0)) {
//             if (posisi.getTypePeta(posisi.getX() - 1, posisi.getY()) == 'o' || posisi.getTypePeta(posisi.getX() - 1, posisi.getY()) == '-') {
//                 posisi.set(posisi.getX() - 1, posisi.getY());
//             } else {
//                 cout << "Tidak bisa pindah! Ada engimon." << endl;
//             }
//         } else {
//             cout << "Tidak bisa pindah ke luar peta!" << endl;
//         }
//     }
//     else if (this->inputCommandMove == "down" || this->inputCommandMove == "DOWN") {
//         if (posisi.isValidPosisiRelatif(1, 0)) {
//             if (posisi.getTypePeta(posisi.getX() + 1, posisi.getY()) == 'o' || posisi.getTypePeta(posisi.getX() + 1, posisi.getY()) == '-') {
//                 posisi.set(posisi.getX() + 1, posisi.getY());
//             } else {
//                 cout << "Tidak bisa pindah! Ada engimon." << endl;
//             }
//         } else {
//             cout << "Tidak bisa pindah ke luar peta!" << endl;
//         }
//     }
//     else if (this->inputCommandMove == "right" || this->inputCommandMove == "RIGHT") {
//         if (posisi.isValidPosisiRelatif(0, 1)) {
//             if (posisi.getTypePeta(posisi.getX(), posisi.getY() + 1) == 'o' || posisi.getTypePeta(posisi.getX(), posisi.getY() + 1) == '-') {
//                 posisi.set(posisi.getX(), posisi.getY() + 1);
//             } else {
//                 cout << "Tidak bisa pindah! Ada engimon." << endl;
//             }
//         } else {
//             cout << "Tidak bisa pindah ke luar peta!" << endl;
//         }
//     }
//     else if (this->inputCommandMove == "left" || this->inputCommandMove == "LEFT") {
//         if (posisi.isValidPosisiRelatif(0, -1)) {
//             if (posisi.getTypePeta(posisi.getX(), posisi.getY() - 1) == 'o' || posisi.getTypePeta(posisi.getX(), posisi.getY() - 1) == '-') {
//                 posisi.set(posisi.getX(), posisi.getY() - 1);
//             } else {
//                 cout << "Tidak bisa pindah! Ada engimon." << endl;
//             }
//         } else {
//             cout << "Tidak bisa pindah ke luar peta!" << endl;
//         }
//     }
//     // ngubah peta posisi tujuan jd P dan posisi asal ditempati engimon aktif
// }

void Player::displayAllEngimon(){
    // ini gatau cara akses per engimon gimana, gini bener ga?
    unordered_map<EngimonPlayer*,int> Test = engiInventory.getThings();
    unordered_map<EngimonPlayer*,int>::iterator itrTest = Test.begin();
    itrTest->first->displayEngiInfo();
}

void Player::displaySpecificEngimon(EngimonPlayer* EP) {
    EP->displayEngiInfo();
}

void Player::displayAllSkillItem() {
    // ini gatau cara akses per engimon gimana, gini bener ga?
    unordered_map<Skill*,int> Test = skillInventory.getThings();
    unordered_map<Skill*,int>::iterator itrTest = Test.begin();
    itrTest->first->getNamaSkill();
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

// string Player::input() {
//     string dest;
//     cin >> dest;
//     this->inputCommandMove = dest;
// }

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