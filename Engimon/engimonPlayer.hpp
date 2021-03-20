#ifndef ENGIMON_PLAYER_HPP
#define ENGIMON_PLAYER_HPP

#include <iostream>
#include "../Engimon/engimon.hpp"

class EngimonPlayer :  public Engimon {
    public :
        //ctor, cctor, dtor, operator
        EngimonPlayer();
        EngimonPlayer(Engimon&);
        EngimonPlayer(const EngimonPlayer&);
        ~EngimonPlayer();
        EngimonPlayer& operator=(const EngimonPlayer&);

        //getter, setter
        string get_name();
        string get_parentsName();
        int get_exp();
        int get_cumExp();
        void set_name(string);
        void set_parentsName(string);
        void set_exp(int);
        void set_cumExp(int);

        //methods
        void levelUp(int);
        void maksCumExp();
        void displayEngiInfo();
    
    protected :
        string name;
        string parentsName;
        int exp;
        int cumExp;
};

#endif