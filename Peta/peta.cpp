#include "peta.hpp"
#include <fstream>
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

Peta::Peta(){
    for(int i = 0; i<10; i++){
        for(int j=0; j<12; j++){
            peta[i][j].setX(i);
            peta[i][j].setY(j);
            peta[i][j].setCellType('.');
        }
    }
}

Peta::~Peta(){}

void Peta::movingWildEngimon(vector<Engimon*>& listOfWildEngimon){
    int xRandom = rand() % 12;
    int yRandom = rand() % 10;

    for (int i=0;i<listOfWildEngimon.size();i++){
        if (listOfWildEngimon.at(i)->get_elements()=="Ice" || listOfWildEngimon.at(i)->get_elements()=="Water" || listOfWildEngimon.at(i)->get_elements()=="Water/Ice"){
            if(yRandom>5 || xRandom<6){
                xRandom = rand() % 6;
                yRandom = rand() % 6;
            }
            Point newPosition(xRandom,yRandom);
            listOfWildEngimon.at(i)->set_posisi(newPosition);
        }else{
            while(yRandom<6 && xRandom>5){
                xRandom = rand() % 12;
                yRandom = rand() % 10;
            }
            Point newPosition(xRandom,yRandom);
            listOfWildEngimon.at(i)->set_posisi(newPosition);
        }
    }
    
    // Point PosTemp;
    // string type_elemen;
    // char type_peta;
    // int type_area;
    // int random_x;
    // int random_y;
    // int xTemp;
    // int yTemp;
    // bool valid_move;
    
    // type_elemen = engimon.get_elements();
    // xTemp = engimon.get_posisiX();
    // yTemp = engimon.get_posisiY();
    // valid_move = false;

    // // Penetuan variabel penambahan untuk bergerak ke empat arah
    // while(!valid_move){
    //     random_x = rand() % 2;
    //     random_y = rand() % 2;

    //     xTemp += random_x;
    //     yTemp += random_y;
    //     type_peta = peta[xTemp][yTemp].getCellType();

    //     // Penentuan area yang diperbolehkan bergerak
    //     if(type_elemen == "Fire"){
    //         valid_move = (type_peta == '-');
    //     }else if(type_elemen == "Electric"){
    //         valid_move = (type_peta == '-');
    //     }else if(type_elemen == "Water/Ice"){
    //         valid_move = (type_peta == 'o');
    //     }else if(type_elemen == "Water"){
    //         valid_move = (type_peta == 'o');
    //     }else if(type_elemen == "Ice"){
    //         valid_move = (type_peta == 'o');
    //     }else if(type_elemen == "Ground"){
    //         valid_move = (type_peta == '-');
    //     }else if(type_elemen == "Water/Ground"){
    //         valid_move = (type_peta == 'o') || (type_peta == '-');
    //     }else if(type_elemen == "Fire/Electric"){
    //         valid_move = (type_peta == '-');
    //     }
    // }


    // // Pengubahan Posisi baru engimon
    // PosTemp = Point(xTemp,yTemp);
    // engimon.set_posisi(PosTemp);

}
//void Peta::spawnWildEngimon();
void Peta::loadMap(){
    string line;
    ifstream myPeta("../Test/map1.txt");
    if(myPeta.is_open()){
        int i = 0;
        while(!myPeta.eof()){
            getline(myPeta,line);
            for (int j = 0; j <line.length(); j++){
                this->peta[i][j].setCellType(line[j]);
                this->peta[i][j].setX(i);
                this->peta[i][j].setY(j);
            }
            i++;
        }
    }else{
        cout<<"gagal me-load peta."<<endl;
    }
}

void Peta::printMap(vector<Engimon*>& listOfWildEngimon){
    for (int i=0; i<listOfWildEngimon.size();i++){
        char simbol;
        if (listOfWildEngimon.at(i)->get_elements()=="Fire"){
            if (listOfWildEngimon.at(i)->get_level()==35){
                simbol = 'F';
            }else{
                simbol = 'f';
            }
        }else if (listOfWildEngimon.at(i)->get_elements()=="Ground"){
            if (listOfWildEngimon.at(i)->get_level()==35){
                simbol = 'G';
            }else{
                simbol = 'g';
            }
        }else if (listOfWildEngimon.at(i)->get_elements()=="Electric"){
            if (listOfWildEngimon.at(i)->get_level()==35){
                simbol = 'E';
            }else{
                simbol = 'e';
            }
        }else if (listOfWildEngimon.at(i)->get_elements()=="Water"){
            if (listOfWildEngimon.at(i)->get_level()==35){
                simbol = 'W';
            }else{
                simbol = 'w';
            }
        }else if (listOfWildEngimon.at(i)->get_elements()=="Ice"){
            if (listOfWildEngimon.at(i)->get_level()==35){
                simbol = 'I';
            }else{
                simbol = 'i';
            }
        }else if (listOfWildEngimon.at(i)->get_elements()=="Fire/Electric"){
            if (listOfWildEngimon.at(i)->get_level()==35){
                simbol = 'L';
            }else{
                simbol = 'l';
            }
        }else if (listOfWildEngimon.at(i)->get_elements()=="Water/Ground"){
            if (listOfWildEngimon.at(i)->get_level()==35){
                simbol = 'S';
            }else{
                simbol = 's';
            }
        }else if (listOfWildEngimon.at(i)->get_elements()=="Water/Ice"){
            if (listOfWildEngimon.at(i)->get_level()==35){
                simbol = 'C';
            }else{
                simbol = 'c';
            }
        }
        peta[listOfWildEngimon.at(i)->get_posisiX()][listOfWildEngimon.at(i)->get_posisiY()].setCellType(simbol);
        cout<<simbol<<endl;
    }
    for (int i=0;i<10;i++){
        for (int j=0;j<12;j++){
            cout<<peta[i][j].getCellType();
        }
        cout<<endl;
    }
}   