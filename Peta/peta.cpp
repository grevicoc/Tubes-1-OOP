#include "peta.hpp"
#include <fstream>
#include <string>
#include <cstdlib>
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

void Peta::movingWildEngimon(Engimon& engimon){
    Point PosTemp;
    string type_elemen;
    char type_peta;
    int type_area;
    int random_x;
    int random_y;
    int xTemp;
    int yTemp;
    bool valid_move;
    
    type_elemen = engimon.get_elements();
    xTemp = engimon.get_posisiX();
    yTemp = engimon.get_posisiY();
    valid_move = false;

    // Penetuan variabel penambahan untuk bergerak ke empat arah
    while(!valid_move){
        random_x = rand() % 2;
        random_y = rand() % 2;

        xTemp += random_x;
        yTemp += random_y;
        type_peta = peta[xTemp][yTemp].cellType;

        // Penentuan area yang diperbolehkan bergerak
        if(type_elemen == "Fire"){
            valid_move = (type_peta == '-');
        }else if(type_elemen == "Electric"){
            valid_move = (type_peta == '-');
        }else if(type_elemen == "Water/Ice"){
            valid_move = (type_peta == 'o');
        }else if(type_elemen == "Water"){
            valid_move = (type_peta == 'o');
        }else if(type_elemen == "Ice"){
            valid_move = (type_peta == 'o');
        }else if(type_elemen == "Ground"){
            valid_move = (type_peta == '-')
        }else if(type_elemen == "Water/Ground"){
            valid_move = (type_peta == 'o') || (type_peta == '-');
        }else if(type_elemen == "Fire/Electric"){
            valid_move = (type_peta == '-');
        }
    }


    // Pengubahan Posisi baru engimon
    PosTemp = Point(xTemp,yTemp);
    engimon.set_Posisi(PosTemp);

}
//void Peta::spawnWildEngimon();
void Peta::loadMap(){
    string line;
    ifstream myPeta();
    if(myPeta.is_open("../Test/map1.txt")){
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