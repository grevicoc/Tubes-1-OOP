#include "Player.hpp"
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Point/Point.hpp"
#include "../Skill/Skill.hpp"
#include "../Skill/EngimonSkill.hpp"


int main(){

    Player P;
    EngimonPlayer* EP1 = new EngimonPlayer();
    Skill* S1 = new Skill("fireball","api",50);
    // Skill* S2 = new Skill("fireball","api",50);
    // Skill* S3 = new Skill("fireball","api",50);
    // Skill* S4 = new Skill("fireball","api",50);
    // Skill* S5 = new Skill("fireball","api",50);
    // Skill* S6 = new Skill("fireball","api",50);
    // Inventory<Skill> testInventory;
    // testInventory.addThing(S1);
    // testInventory.addThing(S2);
    // testInventory.addThing(S3);
    // testInventory.addThing(S4);
    // testInventory.addThing(S5);
    // testInventory.addThing(S6);
    P.addEngimonPlayer(EP1);
    P.addSkillItem(S1); 
    
    

    // waktu delete inventory engimonPlayer lamaa gatau kenapa
    return 0;
}