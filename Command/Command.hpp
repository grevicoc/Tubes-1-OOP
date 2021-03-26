#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <fstream>
#include <string>
#include <iostream>
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Player/Player.hpp"
#include "../Skill/Skill.hpp"
#include "../Point/Point.hpp"
#include "../Peta/peta.hpp"
#include "../Peta/cell.hpp"
#include "../Breeding/Breeding.hpp"
#include <vector>

using namespace std;

class Command {
  protected:
    string currentCommand;
    char gameMode;
    static float getElementsAdvantage(Engimon* engimon1 , Engimon* engimon2);
    static float elementAdvChart(string,string);
    static vector<string> elementsParser(string);
    
    vector<Engimon*> listEngimon;
    Peta map;

  public:
    Command();
    void inputCommand();
    void updateGameMode(char);
    void executeCommand(vector<Engimon*>&, vector<Skill*>&);
    bool isCommandValid() const;
    static void battleBetween(EngimonPlayer*, Engimon*, Player& ,vector<Skill*>&,vector<Engimon*>&);
    void MoveCommand(Player&, vector<Engimon*>&, const Peta&);
    void executeMoveCommand();
    // bool validateNewPositionPlayer();
    bool isPositionValid(Point);
    bool resolvePlayerNewPosition(string);
    void moveActiveEngimon(Point);

    Player me;

    private:
      Engimon* findWildEngi(vector<Engimon*>& listOfWildEngimon);
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