#include "Inventory.hpp"
#include "../Engimon/engimon.hpp"
#include "../Engimon/engimonPlayer.hpp"
#include "../Skill/Skill.hpp"

template<class T>
int Inventory<T>::maxCapacity = 50;

template<class T>
int Inventory<T>::currentCapacity = 0;

template<class T>
Inventory<T>::Inventory(){}

template<class T>   //destructornya bermasalah sepertinya
Inventory<T>::~Inventory(){
    for(auto itr=things.begin();itr!=things.end();itr++){
        T* tempPtr = itr->first;
        delete tempPtr;
    }
    things.erase(things.begin(),things.end());
}

template<class T>
unordered_map<T*,int> Inventory<T>::getThings(){
    return things;
}

template<class T>
int Inventory<T>::getCurrentCapacity(){
    return currentCapacity;
}

template<class T>
int Inventory<T>::getMaxCapacity(){
    return maxCapacity;
}

template<class T>
bool Inventory<T>::addThing(T* object){
    //Cek apakah inventory penuh atau tidak
    if (getMaxCapacity()-getCurrentCapacity()==0){
        return false;
    }else{
        //Cek apakah barang tersebut sudah ada
        if (things.find(object) != things.end()){   //barang sudah ada
            things[object]++;
            currentCapacity++;
        }else{                                      //barang blm ada
            things[object] = 1;
            currentCapacity++;
        }
        return true;
    }
}

template<class T>
bool Inventory<T>::deleteThing(T* object){
    typename unordered_map<T*,int>::iterator itr;
    itr = things.find(object);

    //Cek apakah barang tersebut sudah ada
    if (itr != things.end()){       //barang ada
        things[object]--;
        if (itr->second==0){            //bendanya habis
            T* tempPtr = itr->first;
            things.erase(itr);
            delete tempPtr;
        }
        return true;
    }else{
        return false;
    }
}

//Initial instantiate biar compiler tau gimana seluk beluk Inventory<Engimon>
template class Inventory<EngimonPlayer>;
template class Inventory<Skill>;
template class Inventory<Engimon>;