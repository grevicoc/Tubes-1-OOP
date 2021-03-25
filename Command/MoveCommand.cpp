#include "MoveCommand.hpp"

MoveCommand::MoveCommand(Player& P, vector<Engimon*>& _listEng, const Peta& _map) {
  this->me = P;
  this->listEngimon = _listEng;
  this->map = _map;
}

void MoveCommand::executeMoveCommand() {
  Engimon activeEngimon = me.getActiveEngimon();

}

bool MoveCommand::validateNewPositionPlayer() {
  Point playerPosition = me.getPosisiPlayer();

}

bool MoveCommand::isPositionValid(Point P) {
  int x = P.getX();
  int y = P.getY();
  return (x >= 0) && (x < 12) && (y >= 0) && (y < 10);
}

bool MoveCommand::resolvePlayerNewPosition(string command) {
  Point oldPosition = me.getPosisiPlayer();
  int xDif = 0;
  int yDif = 0;

  if (command == "up" || command == "UP") xDif = -1;
  if (command == "down" || command == "DOWN") xDif = 1;
  if (command == "left" || command == "LEFT") yDif = -1;
  if (command == "right" || command == "RIGHT") yDif = 1;

  Point newPosition = new Point(oldPosition.getX()+xDif, oldPosition.getY()+yDif);
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



void MoveCommand::moveActiveEngimon(Point oldPlayerPosition) {  // Exception handling belom
    me.getActiveEngimon().set_Posisi(oldPlayerPosition);
}