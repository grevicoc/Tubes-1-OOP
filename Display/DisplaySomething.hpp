//File DisplaySomething.hpp
#ifndef DISPLAYSOMETHING_HPP
#define DISPLAYSOMETHING_HPP

/*
Kelas DisplaySomething, merupakan Abstract Base Class (ABC)
untuk kelas yang membutuhkan mencetak sesuatu ke layar 
(DisplayEngimon, DisplayItem dan DisplayItem)).
*/

class DisplaySomething {
    public:
        virtual void Display() = 0;
};
#endif