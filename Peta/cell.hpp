#ifndef CELL_HPP
#define CELL_HPP

class Cell{
public :
    Cell();
    Cell(int x,int y,char cellType);
    Cell& operator=(const Cell&);
    int getX();
    int getY();
    char getCellType();
    friend class Peta;
    
protected :
    int x;
    int y;
    char cellType;
};

#endif