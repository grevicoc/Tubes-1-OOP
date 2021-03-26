#ifndef GENERATEENGIMONL_HPP
#define GENERATEENGIMON_HPP

#include "Generate.hpp"
#include <cstdlib>
#include <ctime>
#include "../Engimon/engimon.hpp"
#include "../Player/Player.hpp"


class GenerateEngimon: public Generate{
    public:
        static Engimon* generateEngimon(vector<Engimon*>&, Player&);
};

#endif