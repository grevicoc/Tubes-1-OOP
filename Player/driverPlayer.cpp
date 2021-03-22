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
    P.addEngimonPlayer(EP1);
    P.addSkillItem(S1); 

    //waktu delete inventory engimonPlayer lamaa gatau kenapa
    return 0;
}