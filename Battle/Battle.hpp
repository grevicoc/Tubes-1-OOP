#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>
#include "../Skill/Skill.hpp"
#include "../Skill/EngimonSkill.hpp"
#include "../Point/Point.hpp"
#include "../Player/Player.hpp"
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Inventory/Inventory.hpp"



#include <string>

using namespace std;

class Battle{
    public:
        Battle();
        ~Battle();
        static void battleBetween(EngimonPlayer*, Engimon*, Player& ,vector<Skill*>& listOfSkillGenerated);

    private:
        static float getElementsAdvantage(Engimon* engimon1 , Engimon* engimon2);
        static float elementAdvChart(string,string);
        static vector<string> elementsParser(string);

};

#endif