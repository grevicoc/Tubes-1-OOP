//File Engimon.hpp
#ifndef ENGIMON_HPP
#define ENGIMON_HPP

#include <iostream>

using namespace std;

class Engimon {
    public :
        //ctor, cctor, dtor, op=
        Engimon();
        Engimon(string name, string parentsName, string species, string elements);
        Engimon(const Engimon&);
        ~Engimon();
        Engimon& operator=(const Engimon&);

        //getter, setter, methods
        string get_name();
        string get_parentsName();
        string get_species();
        string get_elements();
        string get_nature() const;
        string get_ability() const;
        int get_level();
        int get_exp();
        int get_cumExp();

        void set_name(string);
        void set_parentsName(string);
        void set_species(string);
        void set_elements(string);
        void set_nature(string);
        void set_ability(string);
        void set_level(int);
        void set_exp(int);
        void set_cumExp(int);

        void levelUP(int);
        void maksCumExp();
        virtual void displayEngiInfo();

    protected :
        string name;
        string parentsName;
        string species;
        string elements;
        string nature;
        string ability;
        int level;
        int exp;
        int cumExp;
        //Skill* skill;
};

#endif
