#include "Generate.hpp"
#include <fstream>

vector<vector<string>> Generate::readFromFile(string pathToFile){
    vector<vector<string>> retVal;
    string lineText;
    ifstream fileWantToBeRead(pathToFile);

    while(getline(fileWantToBeRead,lineText)){
        vector<string> tempVec;
        while (lineText!="\0"){
            tempVec.push_back(lineText);
            getline(fileWantToBeRead,lineText);
        }
        retVal.push_back(tempVec);
    }
    fileWantToBeRead.close();

    //return hasil
    return retVal;
}