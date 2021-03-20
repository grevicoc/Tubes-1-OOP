#include "engimon.hpp"
#include "engimon.cpp"
#include "../Point/Point.hpp"
#include "../Point/Point.cpp"
#include "../Skill/Skill.hpp"
#include "../Skill/Skill.cpp"

#include <iostream>

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

    Engimon* engi1 = new Engimon();
    Engimon* engi2 = new Engimon("Dragon", 2, posisi2);
    Engimon* engi3 = new Engimon("Cat", 3, posisi3);
    Engimon* engi4 = new Engimon("Bird", 4, posisi4);
    Engimon* engi5 = new Engimon("Fish", 3, posisi5);
    Engimon* engi6 = new Engimon("Octopus", 2, posisi6);
    Engimon* engi7 = new Engimon("Plant", 4, posisi7);
    Engimon* engi8 = new Engimon("Worm", 5, posisi8);
    Engimon* engi9 = new Engimon("Tiger", 5, posisi9);

    Engimon* engi10 = new Engimon();

    //cctor
    Engimon* engi11 = new Engimon(*engi3);

    //operator
    engi10 = engi2;

    //display
    engi1->displayEngiInfo(); cout << endl;
    //starting engimon
    engi2->displayEngiInfo(); cout << endl;
    engi3->displayEngiInfo(); cout << endl;
    engi4->displayEngiInfo(); cout << endl;
    engi5->displayEngiInfo(); cout << endl;
    engi6->displayEngiInfo(); cout << endl;
    engi7->displayEngiInfo(); cout << endl;
    engi8->displayEngiInfo(); cout << endl;
    engi9->displayEngiInfo(); cout << endl;
    engi10->displayEngiInfo(); cout << endl;
    engi11->displayEngiInfo(); cout << endl;

    //dtor
    engi1->~Engimon();
    engi2->~Engimon();
    engi3->~Engimon();
    engi4->~Engimon();
    engi5->~Engimon();
    engi6->~Engimon();
    engi7->~Engimon();
    engi8->~Engimon();
    engi9->~Engimon();
    engi10->~Engimon();
    engi11->~Engimon();

    return 0;
}
