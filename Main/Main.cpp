#include "../Generate/Generate.hpp"
#include "../Generate/GenerateSkill.hpp"
#include "../Generate/GenerateEngimon.hpp"

#include "../Skill/Skill.hpp"
#include "../Skill/EngimonSkill.hpp"

#include "../Engimon/engimon.hpp"


#include <vector>

vector<Skill*> listOfSkillGenerated;
vector<Engimon*> listOfWildEngimon;

int main(){
    srand(time(0));
    Skill* generatedSkill = GenerateSkill::generateSkill(listOfSkillGenerated);
    Engimon* generatedEngimon = GenerateEngimon::generateEngimon(listOfWildEngimon);
    cout<<generatedSkill->getNamaSkill()<<endl;
    generatedSkill = GenerateSkill::generateSkill(listOfSkillGenerated);
    cout<<generatedSkill->getNamaSkill()<<endl;
    generatedSkill = GenerateSkill::generateSkill(listOfSkillGenerated);
    cout<<generatedSkill->getNamaSkill()<<endl;
    cout<<listOfSkillGenerated.size()<<endl;
    listOfWildEngimon[0]->displayEngiInfo();

    return 0;
}