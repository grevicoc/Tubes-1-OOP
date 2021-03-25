#ifndef ENGIMONSKILL_HPP
#define ENGIMONSKILL_HPP

#include"Skill.hpp"
#include<iostream>

class EngimonSkill : public Skill{

    public:
        EngimonSkill();
        EngimonSkill(const Skill&);         //bakal berguna di method learn
        EngimonSkill(const EngimonSkill&);
        EngimonSkill& operator=(const EngimonSkill&);
        virtual ~EngimonSkill();

        int damage();
        int getMasteryLevel() const;
        void setMasteryLevel(int);

    protected:
        int masteryLevel;   
};

#endif