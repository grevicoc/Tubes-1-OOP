#include "engimon.hpp"

#include <iostream>

using namespace std;

int main(){

    //ctor
    Engimon* engi1 = new Engimon();
    Engimon* engi2 = new Engimon("Igneel", "Dragneel", "Dragon", "Fire");
    Engimon* engi3 = new Engimon("Raichu", "Pikachu", "Cat", "Electric");
    Engimon* engi4 = new Engimon("Articuno", "Artic", "Bird", "Water/Ice");
    Engimon* engi5 = new Engimon("Magikarp", "Magi", "Fish", "Water");
    Engimon* engi6 = new Engimon("Octillery", "Remoraid", "Octopus", "Ice");
    Engimon* engi7 = new Engimon("Ivysaur", "Bulbasaur", "Plant", "Ground");
    Engimon* engi8 = new Engimon("Caterpie", "Cater", "Worm", "Water/Ground");
    Engimon* engi9 = new Engimon("Purugly", "Glameow", "Tiger", "Fire/Electric");

    Engimon* engi10 = new Engimon();

    //cctor
    Engimon* engi11 = new Engimon(*engi3);

    //operator
    engi10 = engi2;

    //level up
    engi2->levelUP(4900); cout << endl;
    //maksCumExp
    engi2->maksCumExp(); cout << endl;

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
