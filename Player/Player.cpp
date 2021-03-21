#include "Player.hpp"
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Point/Point.hpp"

#include <iostream>
#include <string>
using namespace std;

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

void Player::Bergerak() {
    if (this->inputCommandMove == "up" || this->inputCommandMove == "UP") {
        if (Point::isValidPosisi(posisi.getX() - 1, posisi.getY())) {
            if (posisi.getTypePeta(posisi.getX() - 1, posisi.getY()) == 'o' || posisi.getTypePeta(posisi.getX() - 1, posisi.getY()) == '-') {
                posisi.set(posisi.getX() - 1, posisi.getY());
            } else {
                cout << "Tidak bisa pindah! Ada engimon." << endl;
            }
        } else {
            cout << "Tidak bisa pindah ke luar peta!" << endl;
        }
    }
    else if (this->inputCommandMove == "down" || this->inputCommandMove == "DOWN") {
        if (Point::isValidPosisi(posisi.getX() + 1, posisi.getY())) {
            if (posisi.getTypePeta(posisi.getX() + 1, posisi.getY()) == 'o' || posisi.getTypePeta(posisi.getX() + 1, posisi.getY()) == '-') {
                posisi.set(posisi.getX() + 1, posisi.getY());
            } else {
                cout << "Tidak bisa pindah! Ada engimon." << endl;
            }
        } else {
            cout << "Tidak bisa pindah ke luar peta!" << endl;
        }
    }
    else if (this->inputCommandMove == "right" || this->inputCommandMove == "RIGHT") {
        if (Point::isValidPosisi(posisi.getX(), posisi.getY() + 1)) {
            if (posisi.getTypePeta(posisi.getX(), posisi.getY() + 1) == 'o' || posisi.getTypePeta(posisi.getX(), posisi.getY() + 1) == '-') {
                posisi.set(posisi.getX(), posisi.getY() + 1);
            } else {
                cout << "Tidak bisa pindah! Ada engimon." << endl;
            }
        } else {
            cout << "Tidak bisa pindah ke luar peta!" << endl;
        }
    }
    else if (this->inputCommandMove == "left" || this->inputCommandMove == "LEFT") {
        if (Point::isValidPosisi(posisi.getX(), posisi.getY() - 1)) {
            if (posisi.getTypePeta(posisi.getX(), posisi.getY() - 1) == 'o' || posisi.getTypePeta(posisi.getX(), posisi.getY() - 1) == '-') {
                posisi.set(posisi.getX(), posisi.getY() - 1);
            } else {
                cout << "Tidak bisa pindah! Ada engimon." << endl;
            }
        } else {
            cout << "Tidak bisa pindah ke luar peta!" << endl;
        }
    }
    // ngubah peta posisi tujuan jd P dan posisi asal ditempati engimon aktif
}

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

void Player::Breeding(EngimonPlayer* A, EngimonPlayer* B) { // inherit skillnya belom
    int random;
    if (A->get_level() >= 30 && B->get_level() >= 30) {
        EngimonPlayer* child = new EngimonPlayer();
        child->set_name();
        string parentA(A->get_name());
        string parentB(B->get_name());
        parentA.append("/");
        child->set_parentsName(parentA.append(parentB));
        if (A->get_elements() == B->get_elements()) {
            child->set_elements(A->get_elements());
            random = rand()%2;
            if (random == 0) {
                child->set_species(A->get_species());
            } else {
                child->set_species(B->get_species());
            }
        } else {
            if (A->get_elements() == "Fire") {
                if (B->get_elements() == "Water") {
                    child->set_elements(B->get_elements());
                    child->set_species(B->get_species());
                } else if (B->get_elements() == "Electric") {
                    child->set_elements("Fire/Electric");
                    random = rand()%5;
                    if (random == 0) {
                        child->set_species("Bird");
                    } else if (random == 1) {
                        child->set_species("Fish");
                    } else if (random == 2) {
                        child->set_species("Octopus");
                    } else if (random == 3) {
                        child->set_species("Plant");
                    } else {
                        child->set_species("Worm");
                    }
                } else if (B->get_elements() == "Ground") {
                    child->set_elements(B->get_elements());
                    child->set_species(B->get_species());
                } else if (B->get_elements() == "Ice") {
                    child->set_elements(A->get_elements());
                    child->set_species(A->get_species());
                } else {
                    // kombinasi fire dengan engimon dua elemen
                }
            } else if (A->get_elements() == "Water") {
                if (B->get_elements() == "Fire") {
                    child->set_elements(A->get_elements());
                    child->set_species(A->get_species());
                } else if (B->get_elements() == "Electric") {
                    child->set_elements(B->get_elements());
                    child->set_species(B->get_species());
                } else if (B->get_elements() == "Ground") {
                    child->set_elements("Water/Ground");
                    random = rand()%4;
                    if (random == 0) {
                        child->set_species("Dragon");
                    } else if (random == 1) {
                        child->set_species("Cat");
                    } else if (random == 2) {
                        child->set_species("Octopus");
                    } else {
                        child->set_species("Tiger");
                    }
                } else if (B->get_elements() == "Ice") {
                    child->set_elements("Water/Ice");
                    random = rand()%4;
                    if (random == 0) {
                        child->set_species("Dragon");
                    } else if (random == 1) {
                        child->set_species("Cat");
                    } else if (random == 2) {
                        child->set_species("Plant");
                    } else {
                        child->set_species("Tiger");
                    }
                } else {
                    // kombinasi water dengan engimon dua elemen
                }
            } else if (A->get_elements() == "Electric") {
                if (B->get_elements() == "Fire") {
                    child->set_elements("Fire/Electric");
                    random = rand()%5;
                    if (random == 0) {
                        child->set_species("Bird");
                    } else if (random == 1) {
                        child->set_species("Fish");
                    } else if (random == 2) {
                        child->set_species("Octopus");
                    } else if (random == 3) {
                        child->set_species("Plant");
                    } else {
                        child->set_species("Worm");
                    }
                } else if (B->get_elements() == "Water") {
                    child->set_elements(A->get_elements());
                    child->set_species(A->get_species());
                } else if (B->get_elements() == "Ground") {
                    child->set_elements(B->get_elements());
                    child->set_species(B->get_species());
                } else if (B->get_elements() == "Ice") {
                    child->set_elements(A->get_elements());
                    child->set_species(A->get_species());
                } else {
                    // kombinasi electric dengan engimon dua element
                }
            } else if (A->get_elements() == "Ground") {
                if (B->get_elements() == "Fire") {
                    child->set_elements(A->get_elements());
                    child->set_species(A->get_species());
                } else if (B->get_elements() == "Water") {
                    child->set_elements("Fire/Ground");
                    random = rand()%4;
                    if (random == 0) {
                        child->set_species("Cat");
                    } else if (random == 1) {
                        child->set_species("Bird");
                    } else if (random == 2) {
                        child->set_species("Fish");
                    } else {
                        child->set_species("Octopus");
                    }
                } else if (B->get_elements() == "Electric") {
                    child->set_elements(A->get_elements());
                    child->set_species(A->get_species());
                } else if (B->get_elements() == "Fire") {
                    child->set_elements(B->get_elements());
                    child->set_species(B->get_species());
                } else {
                    // kombinasi ground dengan engimon dua elementt
                }
            } else if (A->get_elements() == "Ice") {
                if (B->get_elements() == "Fire") {
                    child->set_elements(B->get_elements());
                    child->set_species(B->get_species());
                } else if (B->get_elements() == "Water") {
                    child->set_elements("Water/Ice");
                    random = rand()%4;
                    if (random == 0) {
                        child->set_species("Dragon");
                    } else if (random == 1) {
                        child->set_species("Cat");
                    } else if (random == 2) {
                        child->set_species("Plant");
                    } else {
                        child->set_species("Tiger");
                    }
                } else if (B->get_elements() == "Electric") {
                    child->set_elements(B->get_elements());
                    child->set_species(B->get_species());
                } else if (B->get_elements() == "Ground") {
                    child->set_elements(A->get_elements());
                    child->set_species(A->get_species());
                } else {
                    // kombinasi Ice dengan engimon dua element
                }
            } else {
                // kombinasi engimon dua elemen dengan engimon dua element
            }
        }
        A->set_level(A->get_level() - 30);
        B->set_level(B->get_level() - 30);
        engiInventory.addThing(child);
    } else {
        cout << "Level parent belum cukup untuk breeding!" << endl;
    }
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

string Player::input() {
    string dest;
    cin >> dest;
    this->inputCommandMove = dest;
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