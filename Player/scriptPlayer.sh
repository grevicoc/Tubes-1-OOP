#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ ./driverPlayer.cpp ./Player.cpp ../Engimon/engimon.cpp ../Engimon/engimonPlayer.cpp ../Inventory/Inventory.cpp ../Point/Point.cpp ../Skill/Skill.cpp ../Skill/EngimonSkill.cpp ../Peta/peta.cpp ../Peta/cell.cpp -o driverPlayer
exit 0