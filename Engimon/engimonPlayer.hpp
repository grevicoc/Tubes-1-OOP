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
        int get_idEngiPlayer() const;
        void set_name();
        void set_parentsName(string);
        void set_exp(int);
        void set_cumExp(int);
        void set_PosisiX(int);
        void set_PosisiY(int);

        //methods
        void levelUp(int);
        void maksCumExp();
        void displayEngiInfo();
    
    protected :
        string name;
        string parentsName;
        int exp;
        int cumExp;
        const int idEngiPlayer;
        static int numOfEngimonPlayer;
};

#endif