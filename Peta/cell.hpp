#ifndef CELL_HPP
#define CELL_HPP

class Cell{
public :
    Cell();
    Cell(int x,int y,char cellType);
    int getX();
    int getY();
    char getCellType();
    friend class Peta;
    
private :
    int x;
    int y;
    char cellType;
};

#endif