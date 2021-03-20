//FILE Skill.hpp

#ifndef SKILL_HPP
#define SKILL_HPP

#include<iostream>
#include<fstring>

class Skill{
    protected :
        string namaSkill;
        int basePower;
        string uniqueSkill;

    public :
        //constructor
        Skill();
        //destructor
        ~Skill();
        Skill(string namaSkill, string uniqueSkill, int basePower);
        Skill(const Skill&);
        Skill& operator=(const Skill&);

}

#endif