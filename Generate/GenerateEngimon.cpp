#include "GenerateEngimon.hpp"

Engimon* GenerateEngimon::generateEngimon(){
    vector<vector<string>> vectorOfEngimon = Generate::readFromFile("Skill.txt");
    srand(time(0));
    int randomNumber = rand() % 26;

    return; 
}