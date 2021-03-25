#include "BattleCommand.hpp"
#include "../Generate/GenerateSkill.hpp"

BattleCommand::BattleCommand(): Command(){}

BattleCommand::~BattleCommand(){}

void BattleCommand::battleBetween(EngimonPlayer * eng1 , Engimon *eng2, Player& currentPlayer, vector<Skill*>& listOfSkillGenerated){

    //Mendapatkan nilai elements advantage
    float eng1ElemenAdv = getElementsAdvantage(eng1,eng2);
    float eng2ElemenAdv = getElementsAdvantage(eng2,eng1);

    //Mendapatkan SUM(Basepower * mastery level)
    float sumLevel1 = (float) (eng1->get_level() * eng1ElemenAdv);
    cout<<eng1ElemenAdv<<endl;
    float sumSkill1 = 0;
    vector<EngimonSkill> tempSkill1 = eng1->getEngiSkill();
    
    for (int i = 0; i<tempSkill1.size();i++){
        sumSkill1 = sumSkill1 + (float)tempSkill1.at(i).damage();
    }
    float power1 = sumSkill1 + sumLevel1;

    float sumLevel2 = (float) (eng2->get_level()*eng2ElemenAdv);
    cout<<eng2ElemenAdv<<endl;
    float sumSkill2 = 0;
    vector<EngimonSkill> tempSkill2 = eng2->getEngiSkill();
    
    for (int i = 0; i<tempSkill2.size();i++){
        sumSkill2 = sumSkill2 + (float)tempSkill2.at(i).damage();
    }
    float power2 = sumSkill2 + sumLevel2;

    

    //cout<< "Power Level Player : " << PowerEngimon1 << endl;
    //cout<< "Power Level Lawan : " << PowerEngimon2 << endl;
    cout<<power1<<endl;
    cout<<power2<<endl;
    if ( power1 < power2){
        cout << eng1->get_name() << " Telah Kalah! " << endl;
        currentPlayer.deleteEngimonPlayer(eng1);
    }
    else{
        cout << eng1->get_name() << " Telah Menang! " << endl;
        if (Inventory<EngimonPlayer>::getMaxCapacity()-Inventory<EngimonPlayer>::getCurrentCapacity()==0){
            currentPlayer.skillInventory.addThing(GenerateSkill::generateSkill(listOfSkillGenerated));
            // cout<<currentPlayer.displayAllSkillItem()<<endl;
        }
        eng1->set_exp(sumSkill1-sumSkill2);
    }

}

//ini anggep kek database elements advantage nya
//elemen1 menyerang elemen2
float BattleCommand::elementAdvChart(string elemen1, string elemen2){
    if(elemen1 == "Fire"){
        if(elemen2 == "Fire"){ return 1.0;}
        else if(elemen2 == "Water"){ return 0.0;}
        else if(elemen2 == "Electric"){ return 1.0;}
        else if(elemen2 == "Ground"){ return 0.5;}
        else {return 2.0;}
    } else if(elemen1 == "Water"){
        if(elemen2 == "Fire") {return 2.0;}
        else if(elemen2 == "Water") {return 1.0;}
        else if(elemen2 == "Electric"){ return 0.0;}
        else if(elemen2 == "Ground"){ return 1.0;}
        else {return 1.0;}
    } else if(elemen1 == "Electric"){
        if(elemen2== "Fire"){ return 1.0;}
        else if(elemen2 == "Water"){ return 2.0;}
        else if(elemen2 == "Electric"){ return 1.0;}
        else if(elemen2 == "Ground"){ return 0.0;}
        else {return 1.5;}
    } else if(elemen1 == "Ground"){
        if(elemen2 == "Fire") {return 1.5;}
        else if(elemen2 == "Water") {return 1.0;}
        else if(elemen2 == "Electric"){ return 2.0;}
        else if(elemen2 == "Ground") {return 1.0;}
        else {return 0.0;}
    } else{
        if(elemen1 == "Fire") {return 0.0;}
        else if(elemen2 == "Water") {return 1.0;}
        else if(elemen2 == "Electric") {return 0.5;}
        else if(elemen2 == "Ground") {return 2.0;}
        else {return 1.0;}
    }
}


//Ga ngerti ngambil 2 elemennya
//engimon1 menyerang engimon2
float BattleCommand::getElementsAdvantage(Engimon* engimon1 , Engimon* engimon2){

    vector<string> elementsEngimon1 = elementsParser(engimon1->get_elements());
    vector<string> elementsEngimon2 = elementsParser(engimon2->get_elements());
    float max = 0;

    for (int i=0;i<elementsEngimon1.size();i++){
        for (int j=0;j<elementsEngimon2.size();j++){
            if (elementAdvChart(elementsEngimon1.at(i),elementsEngimon2.at(j)) > max){
                max = elementAdvChart(elementsEngimon1.at(i),elementsEngimon2.at(j));
            }
        }
    }
    return max;
}

vector<string> BattleCommand::elementsParser(string elements){
    vector<string> retVal;
    if (elements.find("/") != string::npos){
        string delimiter = "/";
        retVal.push_back(elements.substr(0, elements.find(delimiter))); 
        retVal.push_back(elements.substr(elements.find("/")+1,elements.size()));
        return retVal;
    }
    retVal.push_back(elements);
    return retVal;
}