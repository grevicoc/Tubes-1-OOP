#include "../Generate/Generate.hpp"
#include "../Generate/GenerateSkill.hpp"
#include "../Generate/GenerateEngimon.hpp"

#include "../Skill/Skill.hpp"
#include "../Skill/EngimonSkill.hpp"

#include "../Engimon/engimon.hpp"

#include "../Player/Player.hpp"

#include "../Battle/Battle.hpp"


#include <vector>

vector<Skill*> listOfSkillGenerated;
vector<Engimon*> listOfWildEngimon;

int main(){
    srand(time(0));

    Player P;
    EngimonPlayer* starterEngimon = new EngimonPlayer();
    P.addEngimonPlayer(starterEngimon);
    starterEngimon->displayEngiInfo();
    
    
    Skill* generatedSkill = GenerateSkill::generateSkill(listOfSkillGenerated);
    Engimon* generatedEngimon = GenerateEngimon::generateEngimon(listOfWildEngimon);
    generatedEngimon->displayEngiInfo();

    Battle::battleBetween(starterEngimon,generatedEngimon,P,listOfSkillGenerated);
    

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