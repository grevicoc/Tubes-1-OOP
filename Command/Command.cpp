#include "Command.hpp"

Command::inputCommand() {
  cout << ">>> ";
  cin >> currentCommand;
}

Command::updateGameMode(char gm) {
  gameMode = gm;
}

Command::executeCommand() {
  try {
    if (isCommandValid) {
      //
    }
  }
  catch (CommandException err) {
    // exceptions
  }
}

Command::isCommandValid() {
  if (gameMode == 'E') {  // exploration mode
    // cek
    // ...
    return true;
  }
  else if (gameMode == 'I') {   // inventory mode
    // cek
    // ...
    return true;
  }
  else if (gameMode == 'B') {   // battle mode
    // cek
    // ...
    return true;
  }
  CommandException error("INVALID_COMMAND", gameMode);
  throw error;
}