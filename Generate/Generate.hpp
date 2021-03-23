#ifndef GENERATE_HPP
#define GENERATE_HPP

#include <iostream>
#include <vector>

using namespace std;

class Generate{
    public:
        //method yang mereturn array 2d string dari file
        static vector<vector<string>> readFromFile(string pathToFile);
};


#endif