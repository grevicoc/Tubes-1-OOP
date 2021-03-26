//File peta.hpp

#ifndef PETA_HPP
#define PETA_HPP

#include "../Engimon/engimon.hpp"
#include "../Point/Point.hpp"
#include "../Player/Player.hpp"
#include <iostream>
#include <vector>

using namespace std;

class Peta{
    public:
        // konstruktor
        Peta();

        // Destructor
        ~Peta();

        // Method
        void movingWildEngimon(vector<Engimon*>&,Player&);
        void spawnWildEngimon();
        void loadMap();
        void printMap(vector<Engimon*>& listOfWildEngimon,Player& P);
        static bool checkAvailability(Point wantToCheck, vector<Engimon*>& listOfWildEngimon, Player& P);
        
    protected:
        Cell peta[10][12];
};



#endif /* PETA_HPP */