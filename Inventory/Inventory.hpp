#include <unordered_map>
#include <iterator>
#include <iostream>

template<class T>
class Inventory{
    protected:
        std::unordered_map<T*,int> things;         //dengan T* adalah pointer yang mengarah ke objek 
        static int currentCapacity=0;
        static int maxCapacity=50;

        //kayaknya skill dibikin abstract class trs subclassnya skillEngimon

    public:
        //ctor
        Inventory(){}

        //dtor, kepikirannya sih karena masing-masing objek di instatiate sebagai pointer makanya perlu  diapus di akhir program
        ~Inventory(){
            std::unordered_map<T*,int>::iterator itr;
            for (itr = things.begin(); itr != things.end(); ++itr) { 
                T* tempPtr = itr->first;
                things.erase(itr);
                delete tempPtr;
            } 
        }

        std::unordered_map<T*,int> getThings(){
            return things;
        }

        static int getCurrentCapacity(){
            return currentCapacity;
        }

        static int getMaxCapacity(){
            return maxCapacity;
        }

        //Method menambahkan 1 objek ke inventory, jika operasi berhasil kembalian true.
        bool addThing(T* object){
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

        //Method mengurangi 1 objek dari inventory, jika operasi berhasil kembalian true.
        bool deleteThing(T* object){
            std::unordered_map<T*,int>::iterator itr;
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
};