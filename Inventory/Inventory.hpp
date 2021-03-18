#ifndef INVENTORY_HPP
#define INVENTORY_HPP

#include <unordered_map>
#include <iterator>
#include <iostream>

using namespace std;

template<class T>
class Inventory{
    protected:
        unordered_map<T*,int> things;         //dengan T* adalah pointer yang mengarah ke objek 
        static int currentCapacity;
        static int maxCapacity;

        //kayaknya skill dibikin abstract class trs subclassnya skillEngimon

    public:
        //ctor
        Inventory();

        //dtor, kepikirannya sih karena masing-masing objek di instatiate sebagai pointer makanya perlu  diapus di akhir program
        ~Inventory();

        //getter things, kasarnya sih ngereturn list objek yang kita punya
        unordered_map<T*,int> getThings();
        
        //getter currentCapacity
        static int getCurrentCapacity();

        //getter maxCapacity
        static int getMaxCapacity();

        //Method menambahkan 1 objek ke inventory, jika operasi berhasil kembalian true (mungkin nanti bisa pake try and catch).
        bool addThing(T* object);

        //Method mengurangi 1 objek dari inventory, jika operasi berhasil kembalian true (mungkin nanti bisa pake try and catch).
        bool deleteThing(T* object);
};

#endif