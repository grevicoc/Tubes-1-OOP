//File DisplayEngimon.hpp
#ifndef DISPLAYENGIMON_HPP
#define DISPLAYENGIMON_HPP

#include "DisplaySomething.hpp"

class DisplayEngimon : public DisplaySomething {
    public:
        void Display();
    protected:
        int playerActiveEngimon;
};
#endif;