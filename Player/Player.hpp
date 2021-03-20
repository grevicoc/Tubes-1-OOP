//File Player.hpp
#ifndef PLAYER_HPP
#define PLAYYER_HPP

#include "../Engimon/engimon.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Point/Point.hpp"

#include <string>

using namespace std;

class Player {
    public:
        void getActiveEngimon();
        int setActiveEngimon();
        void Bergerak();
        void displayAllEngimon();
        // void displaySpecificEngimon();
        // void displayAllSkillItem();
        void useSkillItem();
        void Breeding();
        // void Battle(); jadi kelas
        void interactActiveEngimon();
        
    protected:
        Point posisi;
        int activeEngimon;
        //Inventory inventory; blom bisa
        void moveActiveEngimon();
};

#endif