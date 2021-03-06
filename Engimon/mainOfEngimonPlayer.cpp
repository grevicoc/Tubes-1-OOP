#include "engimon.hpp"
#include "engimon.cpp"
#include "engimonPlayer.hpp"
#include "engimonPlayer.cpp"
#include "../Point/Point.hpp"
#include "../Point/Point.cpp"
#include "../Skill/Skill.hpp"
#include "../Skill/Skill.cpp"
#include "../Skill/EngimonSkill.hpp"
#include "../Skill/EngimonSkill.cpp"
// #include "../Peta/peta.hpp"
// #include "../Peta/peta.cpp"
// #include "../Peta/cell.hpp"
// #include "../Peta/cell.cpp"

#include <iostream>

using namespace std;

int main() {
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

    //set default engimon player
    EngimonPlayer* player1 = new EngimonPlayer();
    player1->displayEngiInfo(); cout << endl;
    //set cum exp
    player1->set_cumExp(4800);
    //level up
    player1->levelUp(50); cout << endl;
    player1->displayEngiInfo(); cout << endl;
    //level up to level max
    player1->levelUp(100); cout << endl;
    player1->displayEngiInfo(); cout << endl;
    //level up again and engimon die
    player1->levelUp(50); cout << endl;

    //Get the engimon from the battle
    //cout << "Power " << player1->get_name() << " : " << player1->powerEngimon(engi2) << endl;
    EngimonPlayer* player2 = new EngimonPlayer(engi2);
    player2->EngimonPlayer::displayEngiInfo();
    
    return 0;
}
