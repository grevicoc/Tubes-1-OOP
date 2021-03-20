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
        ~Skill();

        string getNamaSkill() const;
        string getElemen() const;
        int getBasePower() const;

};

class EngimonSkill: public Skill{

    protected:
        int masteryLevel;

    public:
        EngimonSkill(const Skill& baseSkill);
        ~EngimonSkill();

};

#endif