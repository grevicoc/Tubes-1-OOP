#include "Command.hpp"
#include "../Generate/GenerateSkill.hpp"

Command::Command() {
}

void Command::inputCommand() {
  cout << ">>> ";
  cin >> currentCommand;
}

void Command::updateGameMode(char gm) {
  gameMode = gm;
}

void Command::executeCommand() {
  try {
    if (isCommandValid()) {
      if (currentCommand == "up" || currentCommand == "down"  || currentCommand == "left"  || currentCommand == "right"){
        resolvePlayerNewPosition(currentCommand);
        if (me.inputCommandMove == currentCommand) {
          me.moveActiveEngimon();
        }  
      } else if (currentCommand == "talk") {
        me.interactActiveEngimon();
      }
    }
  }
  catch (CommandException err) {
    // exceptions
  }
}

void Command::battleBetween(EngimonPlayer * eng1 , Engimon *eng2, Player& currentPlayer, vector<Skill*>& listOfSkillGenerated){
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
        }
        eng1->set_exp(sumSkill1-sumSkill2);
    }
}

float Command::elementAdvChart(string elemen1, string elemen2){
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

//engimon1 menyerang engimon2
float Command::getElementsAdvantage(Engimon* engimon1 , Engimon* engimon2){

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

vector<string> Command::elementsParser(string elements){
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

void Command::MoveCommand(Player& P, vector<Engimon*>& _listEng, const Peta& _map) {
  this->me = P;
  this->listEngimon = _listEng;
  this->map = _map;
}

void Command::executeMoveCommand() {
  Engimon activeEngimon = me.getActiveEngimon();

}

bool Command::validateNewPositionPlayer() {
  Point playerPosition = me.getPosisiPlayer();

}

bool Command::isPositionValid(Point P) {
  int x = P.getX();
  int y = P.getY();
  return (x >= 0) && (x < 12) && (y >= 0) && (y < 10);
}

bool Command::resolvePlayerNewPosition(string command) {
  Point oldPosition = me.getPosisiPlayer();
  int xDif = 0;
  int yDif = 0;

  if (command == "up" || command == "UP") xDif = -1;
  if (command == "down" || command == "DOWN") xDif = 1;
  if (command == "left" || command == "LEFT") yDif = -1;
  if (command == "right" || command == "RIGHT") yDif = 1;

  Point newPosition = Point(oldPosition.getX()+xDif, oldPosition.getY()+yDif);
  if (isPositionValid(newPosition)) {
    Point Ptemp;
    for (Engimon* Ei : this->listEngimon) {
      Ptemp = Ei->get_posisi();
      if (Ptemp.getX() == newPosition.getX() && Ptemp.getY() == newPosition.getY()) {
        // player tidak dapat bergerak ke arah sana
        return false;
      }
    }
    // player dapat bergerak
    me.setPosisiPlayer(newPosition);
    moveActiveEngimon(oldPosition);
    return true;
  }
  return false;
}

void Command::moveActiveEngimon(Point oldPlayerPosition) {  // Exception handling belom
    me.getActiveEngimon().set_posisi(oldPlayerPosition);
}

bool Command::isCommandValid() const{
  // if (currentCommand!="up"||currentCommand!="down"||currentCommand!="left"||currentCommand!="right"||currentCommand!="breeding" || currentCommand!="battle" || currentCommand!="showallengimon" || currentCommand!="showallskillitem" || currentCommand!="interact" || currentCommand!="swicthactiveengimon" || currentCommand!="learnskill" || currentCommand!="showspecificengimon"){
  //   return false;
  // }else{
  //   return true;
  // }

  CommandException error("INVALID_COMMAND", gameMode);
  throw error;
}