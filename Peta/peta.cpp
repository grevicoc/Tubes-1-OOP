#include "peta.hpp"
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Peta::Peta(){
    for(int i = 0; i<10; i++){
        for(int j=0; j<12; j++){
            peta[i][j].x = i;
            peta[i][j].y = j;
            peta[i][j].cellType = '.';
        }
    }
}

Peta::~Peta(){}

//void Peta::movingWildEngimon();
//void Peta::spawnWildEngimon();

void Peta::loadMap(){
    string line;
    ifstream myPeta("map1.txt");
    if(myPeta.is_open()){
        int i = 0;
        while(!myPeta.eof()){
            getline(myPeta,line);
            for (int j = 0; j <line.length(); j++){
                this->peta[i][j].cellType = line[j];
                this->peta[i][j].x = i;
                this->peta[i][j].y = j;
            }

            i++;
        }
    }else{
        cout<<"gagal me-load peta."<<endl;
    }
}