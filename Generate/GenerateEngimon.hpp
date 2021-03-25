#ifndef GENERATEENGIMONL_HPP
#define GENERATEENGIMON_HPP

#include "Generate.hpp"
#include "../Engimon/engimon.hpp"
#include <cstdlib>
#include <ctime>

class GenerateEngimon: public Generate{
    public:
        static Engimon* generateEngimon();
};

#endif