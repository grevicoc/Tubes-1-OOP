#ifndef MOVECOMMAND_HPP
#define MOVECOMMAND_HPP

#include <vector>
#include "../Player/Player.hpp"
#include "../Point/Point.hpp"
#include "Command.hpp"

class MoveCommand : public Command {
	private:
		Player me;
		vector<Engimon*> listEngimon;
		Peta map;
	public:
			// vector<Engimon*> listOfWildEngimon;
		MoveCommand(Player&, vector<Engimon*>&, const Peta&);

		void executeMoveCommand();
		bool validateNewPositionPlayer();
		bool isPositionValid(Point);
		bool resolvePlayerNewPosition(string);

		void moveActiveEngimon(Point);
};

#endif