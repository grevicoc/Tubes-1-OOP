#include "GenerateEngimon.hpp"

Engimon* GenerateEngimon::generateEngimon(vector<Engimon*>& listOfWildEngimon){
    vector<vector<string>> vectorOfEngimon = Generate::readFromFile("Engimon.txt");
    // srand(time(0));
    int randomNumber = rand() % 27;         //ada 26 engimon
    
    if (listOfWildEngimon.size()<10){
        Point defaultPoint(0,0);
        Engimon* generatedEngimon = new Engimon(vectorOfEngimon[randomNumber][0],stoi(vectorOfEngimon[randomNumber][1]),defaultPoint);
    }

    return; 
}