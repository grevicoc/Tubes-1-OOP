#include "GenerateSkill.hpp"

Skill* GenerateSkill::generateSkill(vector<Skill*>& listOfSkillGenerated){
    vector<vector<string>> vectorOfSkill(Generate::readFromFile("Skill.txt"));
    //srand(time(0));
    int randomNumber = rand() % 25;
    cout<<randomNumber<<endl;

    Skill* retVal =  new Skill(vectorOfSkill[randomNumber][0],vectorOfSkill[randomNumber][1],stoi(vectorOfSkill[randomNumber][2]));

    bool isSkillExist = false;
    for (int i=0;i<listOfSkillGenerated.size();i++){
        if (listOfSkillGenerated[i]->getNamaSkill()==retVal->getNamaSkill()){   //objek yang digenerate sudah ada
            isSkillExist = true;

            /* Objek dihapus dan pointer diarahkan ke objek yang sudah ada */
            delete retVal;        
            retVal = listOfSkillGenerated[i];
        }
    }
    if (!isSkillExist){
        listOfSkillGenerated.push_back(retVal);
    }

    return retVal;
}