#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>
#include "../Skill/Skill.hpp"
#include "../Skill/EngimonSkill.hpp"
#include "../Point/Point.hpp"
#include "../Player/Player.hpp"
#include "../Engimon/engimon.hpp"

#include <string>

using namespace std;

class Battle{
    public:
        Battle();
        ~Battle();
        Battle(EngimonPlayer *, EngimonPlayer * );
        float elementAdvChart(Engimon&);
        float getElementsAdvantage(string countElementsPlayer , string countElementsLawan);

        Skill* skill;
        EngimonSkill* engiSkill1;
        EngimonSkill* engiSkill2;
        Inventory<EngimonPlayer> IE;
        Inventory<Skill> skillMusuh;

        

};

#endif