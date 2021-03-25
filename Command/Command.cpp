#include "Command.hpp"

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
      // if (currentCommand=="up" || currentCommand=="down"  || currentCommand=="left"  || currentCommand=="right" ){
        
      // }
    }
  }
  catch (CommandException err) {
    // exceptions
  }
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