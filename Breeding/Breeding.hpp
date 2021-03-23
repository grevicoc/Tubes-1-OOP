//File Breeding.hpp
#ifndef BREEDING_HPP
#define BREEDING_HPP

#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Point/Point.hpp"
#include "../Player/Player.hpp"
#include "../Skill/Skill.hpp"

#include <string>

using namespace std;

class Breeding {
    public:
        EngimonPlayer& makeBreeding(EngimonPlayer*, EngimonPlayer*);
        int getRandom(int);
        void setParentName(EngimonPlayer*, EngimonPlayer*, EngimonPlayer*);
        void setElement(EngimonPlayer*, EngimonPlayer*, EngimonPlayer* C);
        void setSpecies(EngimonPlayer*, EngimonPlayer*, EngimonPlayer* C);
        Skill& inheritSkill(Inventory<Skill>);
};
#endif;