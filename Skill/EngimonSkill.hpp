#ifndef ENGIMONSKILL_HPP
#define ENGIMONSKILL_HPP

#include"Skill.hpp"
#include<iostream>

class EngimonSkill : public Skill{

    public:
        EngimonSkill();
        EngimonSkill(Skill&);
        ~EngimonSkill();

        string getEngimonNamaSkill();
        string getEngimonElemen();
        int getEngimonBasePower();
        void setEngimonNamaSkill(string);
        void setEngimonElemen(string);
        void setEngimonBasePower(int);
        int damage();
        int getMasteryLevel();
        void setMasteryLevel(int);
    protected:
        int masteryLevel;   
};

#endif