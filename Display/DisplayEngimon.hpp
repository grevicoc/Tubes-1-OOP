//File DisplayEngimon.hpp
#ifndef DISPLAYENGIMON_HPP
#define DISPLAYENGIMON_HPP

#include "DisplaySomething.hpp"
#include "../Engimon/engimon.hpp"

class DisplayEngimon : public DisplaySomething {
    public:
        void Display(const Engimon&);
    protected:
        int playerActiveEngimon;
};
#endif;