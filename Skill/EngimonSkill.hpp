#ifndef ENGIMONSKILL_HPP
#define ENGIMONSKILL_HPP

#include"Skill.hpp"
#include<iostream>

class EngimonSkill : public Skill{

    public:
        EngimonSkill();
        EngimonSkill(const Skill&);
        ~EngimonSkill();
    protected:
        int masteryLevel;
    
};

#endif