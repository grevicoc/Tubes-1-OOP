#include "Inventory.hpp"
#include "../Engimon/engimon.hpp"

int main(){
    Inventory<Engimon> IE;
    
    Engimon* engi2 = new Engimon("Igneel", "Dragneel", "Dragon", "Fire");
    Engimon* engi3 = new Engimon("Raichu", "Pikachu", "Cat", "Electric");
    Engimon* engi4 = new Engimon("Articuno", "Artic", "Bird", "Water/Ice");
    Engimon* engi5 = new Engimon("Magikarp", "Magi", "Fish", "Water");

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