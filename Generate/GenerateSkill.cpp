#include "GenerateSkill.hpp"

Skill* GenerateSkill::generateSkill(){
    vector<vector<string>> vectorOfSkill = Generate::readFromFile("Skill.txt");
    srand(time(0));
    int randomNumber = rand() % 26;

    return new Skill(vectorOfSkill[randomNumber][0],vectorOfSkill[randomNumber][1],stoi(vectorOfSkill[randomNumber][2]));; 
}