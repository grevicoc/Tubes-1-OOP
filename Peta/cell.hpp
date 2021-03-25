#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <utility>

using namespace std;

class Cell{
public :
    Cell();
    Cell(int x,int y,char cellType);
    Cell& operator=(const Cell&);
    int getX();
    int getY();
    char getCellType();
    
protected :
    pair<int,int> point;
    char cellType;
};

#endif