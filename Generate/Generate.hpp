#ifndef GENERATE_HPP
#define GENERATE_HPP

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

/* 
IMPORTANT NOTE USING THIS CLASS

Pastiin file txt yang kalian mau baca DIAKHIRI \0, untuk contoh liat Skill.txt atau Engimon.txt. Selanjutnya kalo mau make class ini pastiin ada file txt di folder yang sama dengan program yang memakai class ini. Kenapa? karena untuk baca filenya menggunakan metode hard code.
*/

class Generate{
    public:
        //method yang mereturn array 2d string dari file
        static vector<vector<string>> readFromFile(string pathToFile);
};


#endif