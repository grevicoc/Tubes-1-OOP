#include "GenerateEngimon.hpp"
#include <vector>
#include "../Peta/peta.hpp"


Engimon* GenerateEngimon::generateEngimon(vector<Engimon*>& listOfWildEngimon,Player& P){
    vector<vector<string>> vectorOfEngimon(Generate::readFromFile("Engimon.txt"));
    // srand(time(0));
    int randomNumber = rand() % 24;         //ada 24 engimon
    
    
    if (listOfWildEngimon.size()<8){
        Point defaultPoint(0,0);
        Engimon* generatedEngimon = new Engimon(vectorOfEngimon[randomNumber][0],stoi(vectorOfEngimon[randomNumber][1]),defaultPoint);
        

        if (generatedEngimon->get_elements()=="Water" || generatedEngimon->get_elements()=="Water/Ice" || generatedEngimon->get_elements()=="Ice"){
            int xRandom = 0 + ( rand() % ( 5 - 0 + 1 ) );   //0-5
            int yRandom =  6 + ( rand() % ( 11 - 6 + 1 ) );  //6-11
            
            Point fixPosition(xRandom,yRandom);
            bool berhasil = false;
            
            while (!Peta::checkAvailability(fixPosition,listOfWildEngimon,P)){
                
                xRandom = 0 + ( rand() % ( 5 - 0 + 1 ) );
                yRandom = 6 + ( rand() % ( 11 - 6 + 1 ) );
                fixPosition = Point(xRandom,yRandom); 

            }
            generatedEngimon->set_posisi(fixPosition);

        }else{
            int xRandom = 0 + ( rand() % ( 9 - 0 + 1 ) );
            int yRandom = 0 + ( rand() % ( 11 - 0 + 1 ) );
            
            bool berhasil = false;
            Point fixPosition(xRandom,yRandom);
            while (!Peta::checkAvailability(fixPosition,listOfWildEngimon,P) || (xRandom<6 && yRandom>5)){
            
                xRandom = 0 + ( rand() % ( 9 - 0 + 1 ) );
                yRandom = 0 + ( rand() % ( 11 - 0 + 1 ) );
                fixPosition = Point(xRandom,yRandom);

            }
            generatedEngimon->set_posisi(fixPosition);
        }
        
        listOfWildEngimon.push_back(generatedEngimon);
        return generatedEngimon;
        
    }
    return nullptr;
}