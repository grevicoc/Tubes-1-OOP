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
    this->activeEngimon = EP;
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

}

// void displaySpecificEngimon();
// void displayAllSkillItem();
void Player::useSkillItem(){

}

void Player::Breeding() {

}

// void Battle(); jadi kelas
void Player::interactActiveEngimon() {

}

string Player::input() {
    string dest;
    cin >> dest;
    this->inputCommandMove = dest;
}

void Player::moveActiveEngimon() {
    if (this->inputCommandMove == "up" || this->inputCommandMove == "UP") {
        if (Point::isValidPosisi(activeEngimon->get_posisiX()-1, activeEngimon->get_posisiY())) {
            activeEngimon.setPosisiX(activeEngimon->get_posisiX()-1, activeEngimon->get_posisiY());
        } else {
            cout << "Masih ada Player, tidak bisa pindah!" << endl;
        }
    }
    else if (this->inputCommandMove == "down" || this->inputCommandMove == "DOWN"){
        if (Point::isValidPosisi(activeEngimon->get_posisiX()+1, activeEngimon->get_posisiY())) {
            activeEngimon.setPosisiX(activeEngimon->get_posisiX()+1, activeEngimon->get_posisiY());
        } else {
            cout << "Masih ada Player, tidak bisa pindah!" << endl;
        }
    }
    else if (this->inputCommandMove == "right" || this->inputCommandMove == "RIGHT") {
        if (Point::isValidPosisi(activeEngimon->get_posisiX(), activeEngimon->get_posisiY()+1)) {
            activeEngimon.setPosisiX(activeEngimon->get_posisiX(), activeEngimon->get_posisiY()+1);
        } else {
            cout << "Masih ada Player, tidak bisa pindah!" << endl;
        }
    }
    else if (this->inputCommandMove == "left" || this->inputCommandMove == "LEFT") {
        if (Point::isValidPosisi(activeEngimon->get_posisiX(), activeEngimon->get_posisiY()-1)) {
            activeEngimon.setPosisiX(activeEngimon->get_posisiX(), activeEngimon->get_posisiY()-1);
        } else {
            cout << "Masih ada Player, tidak bisa pindah!" << endl;
        }
    }
    // ngubah peta posisi tujuan jd P dan posisi asal ditempati engimon aktif
}