#include "../Generate/Generate.hpp"
#include "../Generate/GenerateSkill.hpp"
#include "../Generate/GenerateEngimon.hpp"

#include "../Skill/Skill.hpp"
#include "../Skill/EngimonSkill.hpp"

#include "../Engimon/engimon.hpp"

#include "../Player/Player.hpp"

#include "../Command/BattleCommand.hpp"

#include "../Breeding/Breeding.hpp"

#include "../Peta/peta.hpp"

#include <vector>

vector<Skill*> listOfSkillGenerated;
vector<Engimon*> listOfWildEngimon;

int main(){
    srand(time(0));
    Engimon* generatedEngimon = GenerateEngimon::generateEngimon(listOfWildEngimon);
    generatedEngimon->displayEngiInfo();
    
    Peta P;
    P.loadMap();
    P.printMap(listOfWildEngimon);

    // Player P;
    // EngimonPlayer* starterEngimon1 = new EngimonPlayer();
    // starterEngimon1->set_level(35);
    // P.addEngimonPlayer(starterEngimon1);
    // starterEngimon1->displayEngiInfo();
    // EngimonPlayer* starterEngimon2 = new EngimonPlayer(*generatedEngimon);
    // P.addEngimonPlayer(starterEngimon2);
    // starterEngimon2->set_level(35);
    // starterEngimon2->set_name();
    // starterEngimon2->displayEngiInfo();
    // //dummy
    // Breeding B;
    // EngimonPlayer* childStarterEngimon = B.makeBreeding(starterEngimon1,starterEngimon2);
    // childStarterEngimon->displayEngiInfo();
    // starterEngimon2->displayEngiInfo();
    
    
    // Skill* generatedSkill = GenerateSkill::generateSkill(listOfSkillGenerated);

    // BattleCommand::battleBetween(starterEngimon1,generatedEngimon,P,listOfSkillGenerated);
    

    // cout<<generatedSkill->getNamaSkill()<<endl;
    // generatedSkill = GenerateSkill::generateSkill(listOfSkillGenerated);
    // cout<<generatedSkill->getNamaSkill()<<endl;
    // generatedSkill = GenerateSkill::generateSkill(listOfSkillGenerated);
    // cout<<generatedSkill->getNamaSkill()<<endl;
    // cout<<listOfSkillGenerated.size()<<endl;
    // listOfWildEngimon[0]->displayEngiInfo();
    // generatedEngimon = GenerateEngimon::generateEngimon(listOfWildEngimon);
    // listOfWildEngimon[1]->displayEngiInfo();

    return 0;
}