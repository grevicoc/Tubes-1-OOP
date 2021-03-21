//File Player.hpp
#ifndef PLAYER_HPP
#define PLAYYER_HPP

#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Point/Point.hpp"

#include <string>

using namespace std;

class Player {
    public:
        EngimonPlayer& getActiveEngimon();
        void setActiveEngimon(EngimonPlayer*);
        void Bergerak();
        void displayAllEngimon();
        // void displaySpecificEngimon();
        // void displayAllSkillItem();
        void useSkillItem();
        void Breeding(EngimonPlayer*, EngimonPlayer*);
        // void Battle(); jadi kelas
        void interactActiveEngimon();
        string input();
        bool isFullInventory();
        void InventoryFull();
        
    protected:
        Point posisi;
        EngimonPlayer* activeEngimon;
        Inventory<EngimonPlayer> engiInventory;
        Inventory<Skill> skillInventory;
        string inputCommandMove;
    private:
        void moveActiveEngimon();
};

#endif