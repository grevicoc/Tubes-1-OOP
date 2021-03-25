//File Engimon.hpp
#ifndef ENGIMON_HPP
#define ENGIMON_HPP

#include <iostream>
#include <vector>
#include "../Point/Point.hpp"
#include "../Skill/EngimonSkill.hpp"

using namespace std;

class Engimon {
    public :
        //ctor, cctor, dtor, operator
        Engimon();
        Engimon(string species, int level, Point posisi);
        Engimon(const Engimon&);
        virtual ~Engimon();
        Engimon& operator=(const Engimon&);

        //getter, setter, methods
        string get_species();
        string get_elements();
        int get_level();
        int get_posisiX();
        int get_posisiY();
        int get_id() const;
        void set_species(string);
        void set_elements(string);
        void set_level(int);
        int powerEngimon(Engimon&);
        int powerEngimon2(Engimon&);
        vector<EngimonSkill> getEngiSkill() const;

        //methods
        virtual void displayEngiInfo();
        //public atribut
        vector<EngimonSkill> engiSkill;

    protected :
        string species;
        string elements;
        int level;
        Point posisi;      
        static int numOfEngimon;
        const int id;
};

#endif