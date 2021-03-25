#include"Battle.hpp"



Battle::Battle(){}

Battle::~Battle(){}

Battle::Battle(EngimonPlayer * eng1 , EngimonPlayer *eng2){

    //Mendapatkan nilai elements advantage
    double eng1ElemenAdv = eng1.getElementAdvantage();
    double eng2ElemenAdv = eng2.getElementAdvantage();

    //Mendapatkan SUM(Basepower * mastery level)
    int sumskill1 = 0;
    engiSkill1 = new EngimonSkill[4];
    for (int i = 0; i<4; i++){
        engiSkill1[i] = skill[i];
    }
    for (int k = 0; k<4; k++){
        sumskill1 = sumskill1 + engiSkill1[k].damage();
    }

    int sumskill2 = 0;
    engiSkill2 = new EngimonSkill[4];
    for (int i = 0; i<4; i++){
        engiSkill2[i] = skill[i];
    }
    for (int k = 0; k<4; k++){
        sumskill2 = sumskill2 + engiSkill2[k].damage();
    }

    //Menghitung nilai power
    double PowerEngimon1 = (eng1.get_level()*eng1ElemenAdv + sumskill1);
    double PowerEngimon2 = (eng2.get_level()*eng2ElemenAdv + sumskill2);

    //cout<< "Power Level Player : " << PowerEngimon1 << endl;
    //cout<< "Power Level Lawan : " << PowerEngimon2 << endl;
    
    if ( PowerEngimon1 < PowerEngimon2){
        cout << eng1->get_name() << " Telah mati " << endl;
        this->IE.deleteThing(eng1);
    }
    else{
        cout << eng1->get_name() << " Telah Menang! " << endl;
        if (!getMaxCapacity()){
            IE.addThing(eng2);
        }
        eng1->set_Exp(eng1->get_exp());
        eng1->levelUp(eng1->set_cumExp());

        //getskillmusuh, ga ngerti

    }

}

//ini anggep kek database elements advantage nya
float Battle::elementAdvChart(Engimon& other){
    if(this->elements == "Fire"){
        if(this->other.elements == "Fire") return 1;
        else if(other.element == "Water") return 0;
        else if(other.element == "Electric") return 1;
        else if(other.element == "Ground") return 0.5;
        else return 2;
    } else if(this->element == "Water"){
        if(other.element == "Fire") return 2;
        else if(other.element == "Water") return 1;
        else if(other.element == "Electric") return 0;
        else if(other.element == "Ground") return 1;
        else return 1;
    } else if(this->elements == "Electric"){
        if(other.element== "Fire") return 1;
        else if(other.elements == "Water") return 2;
        else if(other.elements == "Electric") return 1;
        else if(other.elements == "Ground") return 0;
        else return 1.5;
    } else if(this->elements == "Ground"){
        if(other.elements == "Fire") return 1.5;
        else if(other.elements == "Water") return 1;
        else if(other.elements == "Electric") return 2;
        else if(other.elements == "Ground") return 1;
        else return 0;
    } else{
        if(this->elements == "Fire") return 0;
        else if(other.elements == "Water") return 1;
        else if(other.elements == "Electric") return 0.5;
        else if(other.elements == "Ground") return 2;
        else return 1;
    }
}


//Ga ngerti ngambil 2 elemennya
float Battle::getElementAdvantage(string countElementsPlayer , string countElementsLawan){
    float max = 0;
    for (int i = 0; i < this->countElementsPlayer; i++){
        for(int j = 0; j < this->countElementsLawan; j++){
            if(elementAdvChart(this->elementsPlayer[i], this->elementsLawan[j]) > max) max = elementAdvChart(this->elementsPlayer[i], this->elementsLawan[j]);
        }
    }
    return max;
}
