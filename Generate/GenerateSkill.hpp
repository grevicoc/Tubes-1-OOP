#ifndef GENERATESKILL_HPP
#define GENERATESKILL_HPP

#include "Generate.hpp"
#include <cstdlib>
#include <ctime>
#include "../Skill/Skill.hpp"

class GenerateSkill: public Generate{
    public:
        static Skill* generateSkill(vector<Skill*>&);
};

#endif