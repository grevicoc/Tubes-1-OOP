#include "Inventory.hpp"
#include "Inventory.cpp"
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimon.cpp"
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

int main(){
    Inventory<Engimon> IE;
    
    Point posisi1 = Point();
    Point posisi2 = Point(2,4);
    Point posisi3 = Point(3,6);
    Point posisi4 = Point(4,8);

    Engimon* engi2 = new Engimon("Dragon", 10, posisi1);
    Engimon* engi3 = new Engimon("Cat", 4, posisi2);
    Engimon* engi4 = new Engimon("Bird", 6, posisi3);
    Engimon* engi5 = new Engimon("Fish", 8, posisi4);

    IE.addThing(engi2);
    IE.addThing(engi3);
    IE.addThing(engi4);
    IE.addThing(engi5);

    unordered_map<Engimon*,int> Test = IE.getThings();
    unordered_map<Engimon*,int>::iterator itrTest = Test.begin();
    itrTest->first->displayEngiInfo();

    cout<<"Kapasitas Inventory: "<<IE.getMaxCapacity()<<endl;
    cout<<"Jumlah Sekarang: "<<IE.getCurrentCapacity()<<endl;
}