#include "GenerateEngimon.hpp"
#include <vector>

Engimon* GenerateEngimon::generateEngimon(vector<Engimon*>& listOfWildEngimon){
    vector<vector<string>> vectorOfEngimon = Generate::readFromFile("Engimon.txt");
    // srand(time(0));
    int randomNumber = rand() % 27;         //ada 26 engimon
    
    // if (listOfWildEngimon.size()<8){
    //     Point defaultPoint(0,0);
    //     Engimon* generatedEngimon = new Engimon(vectorOfEngimon[randomNumber][0],stoi(vectorOfEngimon[randomNumber][1]),defaultPoint);
    //     generatedEngimon->displayEngiInfo();

    //     if (generatedEngimon->get_elements()=="Water" || generatedEngimon->get_elements()=="Water/Ice" || generatedEngimon->get_elements()=="Ice"){
    //         int xRandom = 6 + ( rand() % ( 11 - 6 + 1 ) );
    //         int yRandom = 0 + ( rand() % ( 5 - 0 + 1 ) );
            
    //         bool berhasil = false;
    //         while (!berhasil){
    //             int i=0;
    //             while(i<listOfWildEngimon.size()){
    //                 if (xRandom==listOfWildEngimon.at(i)->get_posisiX() && yRandom==listOfWildEngimon.at(i)->get_posisiY()){
    //                     break;
    //                 }
    //                 i++;
    //             }
    //             if (i==listOfWildEngimon.size()){
    //                 berhasil = true;
    //             }else{
    //                 //generate posisi baru
    //                 xRandom = 6 + ( rand() % ( 11 - 6 + 1 ) );
    //                 yRandom = 0 + ( rand() % ( 5 - 0 + 1 ) );
    //             }
                
    //         }
    //         Point fixPosition(xRandom,yRandom);
    //         generatedEngimon->set_Posisi(fixPosition);
    //     }else{
    //         int xRandom = 0 + ( rand() % ( 11 - 0 + 1 ) );
    //         int yRandom = 0 + ( rand() % ( 9 - 0 + 1 ) );
            
    //         bool berhasil = false;
    //         while (!berhasil){
    //             int i=0;
    //             while(i<listOfWildEngimon.size()){
    //                 if ((xRandom==listOfWildEngimon.at(i)->get_posisiX() && yRandom==listOfWildEngimon.at(i)->get_posisiY()) || (xRandom>5 && yRandom<6)){
    //                     break;
    //                 }
    //                 i++;
    //             }

    //             if (i==listOfWildEngimon.size()){
    //                 berhasil = true;
    //             }else{
    //                 //generate posisi baru
    //                 xRandom = 6 + ( rand() % ( 11 - 6 + 1 ) );
    //                 yRandom = 0 + ( rand() % ( 5 - 0 + 1 ) );
    //             }
                
    //         }
    //         Point fixPosition(xRandom,yRandom);
    //         generatedEngimon->set_Posisi(fixPosition);
    //     }

    //     listOfWildEngimon.push_back(generatedEngimon);
    //     return generatedEngimon;
        
    // }
    // return nullptr;
}