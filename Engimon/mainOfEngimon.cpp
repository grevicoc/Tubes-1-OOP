#include "engimon.hpp"
#include "engimon.cpp"
#include "../Point/Point.hpp"
#include "../Point/Point.cpp"
#include "../Skill/Skill.hpp"
#include "../Skill/Skill.cpp"
#include "../Skill/EngimonSkill.hpp"
#include "../Skill/EngimonSkill.cpp"
#include "../Peta/peta.hpp"
#include "../Peta/peta.cpp"
#include "../Peta/cell.hpp"
#include "../Peta/cell.cpp"

#include <iostream>
#include <vector>

using namespace std;

int main(){

    //ctor
    Point posisi = Point();
    Point posisi2 = Point(1, 2);
    Point posisi3 = Point(2, 4);
    Point posisi4 = Point(9, 4);
    Point posisi5 = Point(10, 6);
    Point posisi6 = Point(12, 6);
    Point posisi7 = Point(3, 6);
    Point posisi8 = Point(4, 8);
    Point posisi9 = Point(5, 5);

    Engimon engi1 = Engimon();
    Engimon engi2 = Engimon("Dragon", 2, posisi2);
    Engimon engi3 = Engimon("Cat", 3, posisi3);
    Engimon engi4 = Engimon("Bird", 4, posisi4);
    Engimon engi5 = Engimon("Fish", 3, posisi5);
    Engimon engi6 = Engimon("Octopus", 2, posisi6);
    Engimon engi7 = Engimon("Plant", 4, posisi7);
    Engimon engi8 = Engimon("Worm", 5, posisi8);
    Engimon engi9 = Engimon("Tiger", 5, posisi9);

    //cctor
    Engimon engi10 = Engimon(engi3);

    //get posisi
    cout << "Posisi engimon 1 : " << "(" << engi1.get_posisiX() << ", " << engi1.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 2 : " << "(" << engi2.get_posisiX() << ", " << engi2.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 3 : " << "(" << engi3.get_posisiX() << ", " << engi3.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 4 : " << "(" << engi4.get_posisiX() << ", " << engi4.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 5 : " << "(" << engi5.get_posisiX() << ", " << engi5.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 6 : " << "(" << engi6.get_posisiX() << ", " << engi6.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 7 : " << "(" << engi7.get_posisiX() << ", " << engi7.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 8 : " << "(" << engi8.get_posisiX() << ", " << engi8.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 9 : " << "(" << engi9.get_posisiX() << ", " << engi9.get_posisiY() << ")" << endl;
    cout << "Posisi engimon 10 : " << "(" << engi10.get_posisiX() << ", " << engi10.get_posisiY() << ")" << endl;
    cout << endl;

    //power
    /*cout << "Power " << engi5.get_species() << " : " << engi5.powerEngimon(engi2)<< endl;
    cout << "Power " << engi2.get_species() << " : " << engi2.powerEngimon(engi5)<< endl;
    cout << endl;*/

    //display
    engi1.displayEngiInfo(); cout << endl;
    //starting wild engimon
    engi2.displayEngiInfo(); cout << endl;
    engi3.displayEngiInfo(); cout << endl;
    engi4.displayEngiInfo(); cout << endl;
    engi5.displayEngiInfo(); cout << endl;
    engi6.displayEngiInfo(); cout << endl;
    engi7.displayEngiInfo(); cout << endl;
    engi8.displayEngiInfo(); cout << endl;
    engi9.displayEngiInfo(); cout << endl;
    engi10.displayEngiInfo(); cout << endl;

    //dtor
    engi1.~Engimon();
    engi2.~Engimon();
    engi3.~Engimon();
    engi4.~Engimon();
    engi5.~Engimon();
    engi6.~Engimon();
    engi7.~Engimon();
    engi8.~Engimon();
    engi9.~Engimon();
    engi10.~Engimon();

    return 0;
}