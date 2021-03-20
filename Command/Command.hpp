#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

class Command {
protected:
  string currentCommand;
  char gameMode;
public:
  void inputCommand();
  void updateGameMode(char);
  void executeCommand();
  bool isCommandValid() const;
};

class CommandException {
public:
  string errorCode;
  char gameMode;

  CommandException(string err, char gm) {
    errorCode = err;
    gameMode = gm;
  }
};

#endif