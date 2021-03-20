#ifndef SKILL_HPP
#define SKILL_HPP

#include"Skill.hpp"
#include<iostream>

class EngimonSkill : public Skill{

    public:
        EngimonSkill();
        ~EngimonSkill();
    protected:
        int masteryLevel;
    
};

#endif