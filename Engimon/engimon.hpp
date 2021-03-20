//File Engimon.hpp
#ifndef ENGIMON_HPP
#define ENGIMON_HPP

#include <iostream>
#include "../Point/Point.hpp"
#include "../Skill/Skill.hpp"

using namespace std;

class Engimon {
    public :
        //ctor, cctor, dtor, operator
        Engimon();
        Engimon(string species, int level, Point posisi);
        Engimon(const Engimon&);
        ~Engimon();
        Engimon& operator=(const Engimon&);

        //getter, setter, methods
        string get_species();
        string get_elements();
        int get_level();
        int get_cumExp();
        void set_species(string);
        void set_elements(string);
        void set_level(int);

        //methods
        virtual void displayEngiInfo();

    protected :
        string species;
        string elements;
        int level;
        Point posisi;
        Skill* skill;
};

#endif
