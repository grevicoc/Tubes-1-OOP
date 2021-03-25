#ifndef BATTLECOMMAND_HPP
#define BATTLECOMMAND_HPP

#include "Command.hpp"
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Player/Player.hpp"
#include "../Skill/Skill.hpp"
#include <vector>

class BattleCommand : public Command {
  public:
        BattleCommand();
        ~BattleCommand();
        static void battleBetween(EngimonPlayer*, Engimon*, Player& ,vector<Skill*>& listOfSkillGenerated);

    private:
        static float getElementsAdvantage(Engimon* engimon1 , Engimon* engimon2);
        static float elementAdvChart(string,string);
        static vector<string> elementsParser(string);
};

#endif