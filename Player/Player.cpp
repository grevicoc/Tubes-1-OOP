#include "Player.hpp"
#include "../Engimon/engimon.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Point/Point.hpp"

void Player::getActiveEngimon() {

}

int Player::setActiveEngimon() {

}

void Player::Bergerak() {
    string dest;
    cin >> dest;
    if (dest == "up" || dest == "UP") {
        if (Point::isValidPosisi(posisi.getX()-1, posisi.getY())) {
            if (Point::isNextWater(posisi.getX()-1, posisi.getY()) || Point::isValidPosisi(posisi.getX()-1, posisi.getY())) {
                this->posisi = Point::Point(posisi.getX()-1, posisi.getY());
            }
        }
    } else if (dest == "down" || dest == "DOWN") {
        if (Point::isValidPosisi(posisi.getX()+1, posisi.getY())) {
            if (Point::isNextWater(posisi.getX()+1, posisi.getY()) || Point::isValidPosisi(posisi.getX()+1, posisi.getY())) {
                this->posisi = Point::Point(posisi.getX()+1, posisi.getY());
            }
        }
    } else if (dest == "right" || dest == "RIGHT") {
        if (Point::isValidPosisi(posisi.getX(), posisi.getY()+1)) {
            if (Point::isNextWater(posisi.getX(), posisi.getY()+1) || Point::isValidPosisi(posisi.getX(), posisi.getY()+1)) {
                this->posisi = Point::Point(posisi.getX(), posisi.getY()+1);
            }
        }
    } else if (dest == "left" || dest == "LEFT") {
        if (Point::isValidPosisi(posisi.getX(), posisi.getY()-1)) {
            if (Point::isNextWater(posisi.getX(), posisi.getY()-1) || Point::isValidPosisi(posisi.getX(), posisi.getY()-1)) {
                this->posisi = Point::Point(posisi.getX(), posisi.getY()-1);
            }
        }
    }
    // ngubah peta posisi tujuan jd P dan posisi asal ditempati engimon aktif
}

void displayAllEngimon(){

}

// void displaySpecificEngimon();
// void displayAllSkillItem();
void useSkillItem(){

}

void Breeding() {

}

// void Battle(); jadi kelas
void interactActiveEngimon() {

}