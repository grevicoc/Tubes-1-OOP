#include "Breeding.hpp"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

EngimonPlayer* Breeding::makeBreeding(EngimonPlayer* A, EngimonPlayer* B) {
    if (A->get_level() >= 30 && B->get_level() >= 30) {
        EngimonPlayer* child = new EngimonPlayer();
        child->set_name();
        setParentName(A, B, child);
        setElementSpecies(A, B, child);
        if (child->get_species() == A->get_species()) {
            child->engiSkill.at(0) = A->engiSkill[0];
        } else {
            child->engiSkill.at(0) = B->engiSkill[0];
        } inheritSkill(A, B, child);
        A->set_level(A->get_level() - 30);
        B->set_level(B->get_level() - 30);
        return child;
    }else{
        throw 6;
    }
}

// int Breeding::getRandom(int n) {
//     int hasilRandom;
//     hasilRandom = rand()%n;
//     return hasilRandom;
// }

void Breeding::setParentName(EngimonPlayer* A, EngimonPlayer* B, EngimonPlayer* C) {
    string parentA(A->get_name());
    string parentB(B->get_name());
    parentA.append("/");
    C->set_parentsName(parentA.append(parentB));
}

void Breeding::setElementSpecies(EngimonPlayer* A, EngimonPlayer* B, EngimonPlayer* C) {
    if (A->get_elements() == B->get_elements()) {
        C->set_elements(A->get_elements());
        C->set_species(A->get_species());
    } else {
        if (A->get_elements() == "Fire") {
            if (B->get_elements() == "Water") {
                C->set_elements(B->get_elements());
                C->set_species(B->get_species());
            } else if (B->get_elements() == "Electric") {
                C->set_elements("Fire/Electric");
                C->set_species("Tiger");
            } else if (B->get_elements() == "Ground") {
                C->set_elements(B->get_elements());
                C->set_species(B->get_species());
            } else if (B->get_elements() == "Ice") {
                C->set_elements(A->get_elements());
                C->set_species(A->get_species());
            } else {
                // kombinasi fire dengan engimon dua elemen
            }
        } else if (A->get_elements() == "Water") {
            if (B->get_elements() == "Fire") {
                C->set_elements(A->get_elements());
                C->set_species(A->get_species());
            } else if (B->get_elements() == "Electric") {
                C->set_elements(B->get_elements());
                C->set_species(B->get_species());
            } else if (B->get_elements() == "Ground") {
                C->set_elements("Water/Ground");
                C->set_species("Worm");
            } else if (B->get_elements() == "Ice") {
                C->set_elements("Water/Ice");
                C->set_species("Bird");
            } else {
                // kombinasi water dengan engimon dua elemen
            }
        } else if (A->get_elements() == "Electric") {
            if (B->get_elements() == "Fire") {
                C->set_elements("Fire/Electric");
                C->set_species("Tiger");
            } else if (B->get_elements() == "Water") {
                C->set_elements(A->get_elements());
                C->set_species(A->get_species());
            } else if (B->get_elements() == "Ground") {
                C->set_elements(B->get_elements());
                C->set_species(B->get_species());
            } else if (B->get_elements() == "Ice") {
                C->set_elements(A->get_elements());
                C->set_species(A->get_species());
            } else {
                // kombinasi electric dengan engimon dua element
            }
        } else if (A->get_elements() == "Ground") {
            if (B->get_elements() == "Fire") {
                C->set_elements(A->get_elements());
                C->set_species(A->get_species());
            } else if (B->get_elements() == "Water") {
                C->set_elements("Fire/Ground");
                C->set_species("Worm");
            } else if (B->get_elements() == "Electric") {
                C->set_elements(A->get_elements());
                C->set_species(A->get_species());
            } else if (B->get_elements() == "Fire") {
                C->set_elements(B->get_elements());
                C->set_species(B->get_species());
            } else {
                // kombinasi ground dengan engimon dua elementt
            }
        } else if (A->get_elements() == "Ice") {
            if (B->get_elements() == "Fire") {
                C->set_elements(B->get_elements());
                C->set_species(B->get_species());
            } else if (B->get_elements() == "Water") {
                C->set_elements("Water/Ice");
                C->set_species("Bird");
            } else if (B->get_elements() == "Electric") {
                C->set_elements(B->get_elements());
                C->set_species(B->get_species());
            } else if (B->get_elements() == "Ground") {
                C->set_elements(A->get_elements());
                C->set_species(A->get_species());
            } else {
                // kombinasi Ice dengan engimon dua element
            }
        } else {
            // kombinasi engimon dua elemen dengan engimon dua element
        }
    }
}

// void Breeding::setSpecies(EngimonPlayer* A, EngimonPlayer* B, EngimonPlayer* C) {
//     int random;
//     vector<string> combin1 = {"Bird", "Fish", "Octopus", "Plant", "Worm"};    // Fire Electric
//     vector<string> combin2 = {"Dragon", "Cat", "Octopus", "Tiger"};   // Water Ground
//     vector<string> combin3 = {"Dragon", "Cat", "Plant", "Tiger"}; // Water Ice

//     if (A->get_elements() == B->get_elements()) {
//         random = getRandom(2);
//         if (random == 0) {
//             C->set_species(A->get_species());
//         } else {
//             C->set_species(B->get_species());
//         }
//     } else {
//         if (A->get_elements() == "Fire") {
//             if (B->get_elements() == "Water") {
//                 C->set_species(B->get_species());
//             } else if (B->get_elements() == "Electric") {
//                 random = getRandom(5);
//                 C->set_species(combin1[random]);
//             } else if (B->get_elements() == "Ground") {
//                 C->set_species(B->get_species());
//             } else if (B->get_elements() == "Ice") {
//                 C->set_species(A->get_species());
//             } else {
//                 // kombinasi fire dengan engimon dua elemen
//             }
//         } else if (A->get_elements() == "Water") {
//             if (B->get_elements() == "Fire") {
//                 C->set_species(A->get_species());
//             } else if (B->get_elements() == "Electric") {
//                 C->set_species(B->get_species());
//             } else if (B->get_elements() == "Ground") {
//                 random = getRandom(4);
//                 C->set_species(combin2[random]);
//             } else if (B->get_elements() == "Ice") {
//                 random = getRandom(4);
//                 C->set_species(combin3[random]);
//             } else {
//                 // kombinasi water dengan engimon dua elemen
//             }
//         } else if (A->get_elements() == "Electric") {
//             if (B->get_elements() == "Fire") {
//                 random = getRandom(5);
//                 C->set_species(combin1[random]);
//             } else if (B->get_elements() == "Water") {
//                 C->set_species(A->get_species());
//             } else if (B->get_elements() == "Ground") {
//                 C->set_species(B->get_species());
//             } else if (B->get_elements() == "Ice") {
//                 C->set_species(A->get_species());
//             } else {
//                 // kombinasi electric dengan engimon dua element
//             }
//         } else if (A->get_elements() == "Ground") {
//             if (B->get_elements() == "Fire") {
//                 C->set_species(A->get_species());
//             } else if (B->get_elements() == "Water") {
//                 random = getRandom(4);
//                 C->set_species(combin2[random]);
//             } else if (B->get_elements() == "Electric") {
//                 C->set_species(A->get_species());
//             } else if (B->get_elements() == "Fire") {
//                 C->set_species(B->get_species());
//             } else {
//                 // kombinasi ground dengan engimon dua elementt
//             }
//         } else if (A->get_elements() == "Ice") {
//             if (B->get_elements() == "Fire") {
//                 C->set_species(B->get_species());
//             } else if (B->get_elements() == "Water") {
//                 random = getRandom(4);
//                 C->set_species(combin3[random]);
//             } else if (B->get_elements() == "Electric") {
//                 C->set_species(B->get_species());
//             } else if (B->get_elements() == "Ground") {
//                 C->set_species(A->get_species());
//             } else {
//                 // kombinasi Ice dengan engimon dua element
//             }
//         } else {
//             // kombinasi engimon dua elemen dengan engimon dua element
//         }
//     }
// }

void Breeding::inheritSkill(EngimonPlayer* A, EngimonPlayer* B, EngimonPlayer* C) {
    int countA, countB, i;
    i = 1;
    countA = 1;
    countB = 1;
    while (i < 4) {
        bool sama = false;
        int j = 1;
        if (A->engiSkill[countA].getMasteryLevel() > B->engiSkill[countB].getMasteryLevel()) {
            while(j < 4 && sama == false) {
                if (A->engiSkill[i].getNamaSkill() == C->engiSkill[j].getNamaSkill()) {
                    sama = true;
                } j++;
            }
            if (sama == false) {
                C->engiSkill.at(i) = A->engiSkill[countA];
                // C->engiSkill[i].setNamaSkill(A->engiSkill[countA].getNamaSkill());
                // C->engiSkill[i].setElemen(A->engiSkill[countA].getElemen());
                // C->engiSkill[i].setBasePower(A->engiSkill[countA].getBasePower());
                // C->engiSkill[i].setMasteryLevel(A->engiSkill[countA].getMasteryLevel());
            }
            countA++;
        } else if (A->engiSkill[countA].getMasteryLevel() == B->engiSkill[countB].getMasteryLevel()) {
            while(j < 4 && sama == false) {
                if (A->engiSkill[i].getNamaSkill() == C->engiSkill[j].getNamaSkill()) {
                    sama = true;
                } j++;
            }
            if (sama == false) {
                C->engiSkill.at(i) = A->engiSkill[countA];
                // C->engiSkill[i].setNamaSkill(A->engiSkill[countA].getNamaSkill());
                // C->engiSkill[i].setElemen(A->engiSkill[countA].getElemen());
                // C->engiSkill[i].setBasePower(A->engiSkill[countA].getBasePower());
                if (A->engiSkill[countA].getNamaSkill() == B->engiSkill[countB].getNamaSkill()) {
                    C->engiSkill[i].setMasteryLevel(A->engiSkill[countA].getMasteryLevel()+1);
                }
            }
            countA++;
        } else {
            while(j < 4 && sama == false) {
                if (B->engiSkill[i].getNamaSkill() == C->engiSkill[j].getNamaSkill()) {
                    sama = true;
                } j++;
            }
            if (sama == false) {
                C->engiSkill.at(i) = B->engiSkill[countB];
                // C->engiSkill[i].setNamaSkill(B->engiSkill[countB].getNamaSkill());
                // C->engiSkill[i].setElemen(B->engiSkill[countB].getElemen());
                // C->engiSkill[i].setBasePower(B->engiSkill[countB].getBasePower());
                // C->engiSkill[i].setMasteryLevel(B->engiSkill[countB].getMasteryLevel());
            }
            countB++;
        }
        i++;
    }
}