//File peta.hpp

#ifndef PETA_HPP
#define PETA_HPP


#include "cell.hpp"
#include <iostream>

using namespace std;

class Peta{
    public:
        // konstruktor
        Peta();

        // Destructor
        ~Peta();

        // Method
        void movingWildEngimon();
        void spawnWildEngimon();
        void loadMap();

    protected:
        Cell peta[10][12];

};



#endif /* PETA_HPP */