//File Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Inventory/Inventory.hpp"
#include "../Point/Point.hpp"

#include <string>

using namespace std;

class Player {
    public:
        Player();
        ~Player();
        EngimonPlayer* getActiveEngimon();
        void setActiveEngimon(EngimonPlayer*);
        
        void displayAllEngimon();
        void displaySpecificEngimon();
        void displayAllSkillItem();
        void useSkillItem();
        
        EngimonPlayer* findEngimon(int);
        void switchActiveEngimon();
        void learnSkill(vector<Skill*>& listOfGeneratedSkill);
        
        void interactActiveEngimon();
        string input();
        void addEngimonPlayer(EngimonPlayer*);
        void addSkillItem(Skill*);
        void deleteEngimonPlayer(EngimonPlayer*);
        Inventory<EngimonPlayer> engiInventory;
        Inventory<Skill> skillInventory;
        Point getPosisiPlayer();
        void setPosisiPlayer(Point);
        void moveActiveEngimon();
        string inputCommandMove;
        
    protected:
        Point posisi;
        EngimonPlayer* activeEngimon;
        
};

#endif