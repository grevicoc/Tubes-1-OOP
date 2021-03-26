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

void Peta::movingWildEngimon(vector<Engimon*>& listOfWildEngimon, Player& P){
    int xDiff = -1 + (rand() % 3);
    int yDiff = -1 + (rand() % 3);

    for (int i=0;i<listOfWildEngimon.size();i++){
        int xCurrent = listOfWildEngimon.at(i)->get_posisiX();
        int yCurrent = listOfWildEngimon.at(i)->get_posisiY();
        
        //kondisi engimon yang bisa di water
        if (listOfWildEngimon.at(i)->get_elements()=="Ice" || listOfWildEngimon.at(i)->get_elements()=="Water" || listOfWildEngimon.at(i)->get_elements()=="Water/Ice"){
            while(xCurrent+xDiff>5 || yCurrent+yDiff<6 || xCurrent+xDiff>9 || yCurrent+yDiff>11 || xCurrent+xDiff<0 || yCurrent+yDiff<0){
                xDiff = -1 + (rand() % 3);
                yDiff = -1 + (rand() % 3);
                
            }
            Point newPosition(xCurrent+xDiff,yCurrent+yDiff);


            //cek apakah point tersebut sudah ada yang nempatin atau belum
            if (checkAvailability(newPosition,listOfWildEngimon,P)){
                listOfWildEngimon.at(i)->set_posisi(newPosition);
            }

        }else{
            while((xCurrent+xDiff<6 && yCurrent+yDiff>5) || (xCurrent+xDiff>9 || yCurrent+yDiff>11 ||xCurrent+xDiff<0 || yCurrent+yDiff<0)){
                xDiff = -1 + (rand() % 3);
                yDiff = -1 + (rand() % 3);
                
            }
            
            Point newPosition(xCurrent+xDiff,yCurrent+yDiff);

            //cek apakah point tersebut sudah ada yang nempatin atau belum
            if (checkAvailability(newPosition,listOfWildEngimon,P)){
                listOfWildEngimon.at(i)->set_posisi(newPosition);
            }
        }
    }
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

void Peta::printMap(vector<Engimon*>& listOfWildEngimon, Player& P){
    loadMap();
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
        
    }
    peta[P.getPosisiPlayer().getX()][P.getPosisiPlayer().getY()].setCellType('P');
    peta[P.getActiveEngimon()->get_posisiX()][P.getActiveEngimon()->get_posisiY()].setCellType('A');

    for (int i=0;i<10;i++){
        for (int j=0;j<12;j++){
            cout<<peta[i][j].getCellType();
        }
        cout<<endl;
    }
}

bool Peta::checkAvailability(Point wantToCheck, vector<Engimon*>& listOfWildEngimon, Player& P){
    bool retVal = true;
    int i=0;
    while (i<listOfWildEngimon.size() && retVal){
        if (wantToCheck==listOfWildEngimon.at(i)->get_posisi()){
            retVal = false;
        }
        i++;
    }
    if (retVal){
        if (wantToCheck==P.getPosisiPlayer() || wantToCheck==P.getActiveEngimon()->get_posisi()){
            retVal = false;
        }
    }
    return retVal;
}
