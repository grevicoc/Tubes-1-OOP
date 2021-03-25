#include "Generate.hpp"
#include "GenerateSkill.hpp"

int main(){

    // vector<vector<string>> temp = Generate::readFromFile("Skill.txt");
    // for (int i = 0; i < temp.size(); i++) {
    //     for (int j = 0; j < temp[i].size(); j++)
    //         cout << temp[i][j] << " ";
    //     cout << endl;
    // }
    Skill* testSkill = GenerateSkill::generateSkill();
    cout<<testSkill->getBasePower()<<endl;
    delete testSkill;

    return 0;
}