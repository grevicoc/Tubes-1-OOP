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
    void setX(int);
    int getY();
    void setY(int);
    char getCellType();
    void setCellType(char);
    
protected :
    pair<int,int> point;
    char cellType;
};

#endif