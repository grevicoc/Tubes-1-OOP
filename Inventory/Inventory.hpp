#include <map>
#include <iterator>

template<class T>
class Inventory{
    protected:
        std::map<T*,int> things;         //dengan T* adalah pointer yang mengarah ke objek 
        int currentCapacity;
        static int maxCapacity=50;

        //kayaknya skill dibikin abstract class trs subclassnya skillEngimon

    public:
        Inventory(){
            currentCapacity=0;
        }

        ~Inventory(){
            std::map<T*,int>::iterator itr;
            for (itr = things.begin(); itr != things.end(); ++itr) { 
                delete itr->first;
                things.erase(itr);
            } 
        }

        void addThing(T*);
        void deleteThing(T*);
        void printAll();
        friend void Player::learn(T*);        //Class player perlu tambahin method learn

};