#include "Skill.hpp"

int main(){
    Skill skill1("fireball","api",50);
    EngimonSkill skillv1(skill1);
    cout<<skill1.getNamaSkill()<<endl;
    cout<<skill1.getBasePower()<<endl;
    cout<<skill1.getElemen()<<endl;
}