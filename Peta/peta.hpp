//File peta.hpp

#ifndef PETA_HPP
#define PETA_HPP


#include "cell.hpp"
#include "../Engimon/engimon.hpp"
#include "../Point/Point.hpp"
#include <iostream>

using namespace std;

class Peta{
    public:
        // konstruktor
        Peta();

        // Destructor
        ~Peta();

        // Method
        // void movingWildEngimon(Engimon&);
        void spawnWildEngimon();
        void loadMap();

    protected:
        Cell peta[10][12];

};



#endif /* PETA_HPP */