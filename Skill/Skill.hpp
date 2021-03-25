#ifndef SKILL_HPP
#define SKILL_HPP

#include <iostream>

using namespace std;

class Skill{

    protected:
        string namaSkill;
        string unique;              //berisi elemen jika sebuah skill khusus untuk sebuah elemen
        int basePower;

    public:
        Skill();
        Skill(string _namaSkill, string elemen, int basePower);
        Skill(const Skill&);
        Skill& operator=(const Skill&);
        ~Skill();

        string getNamaSkill();
        string getElemen();
        int getBasePower();

        void setNamaSkill(string);
        void setElemen(string);
        void setBasePower(int);

};


#endif