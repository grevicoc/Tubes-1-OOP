#include "cell.hpp"

Cell::Cell(){
    this -> x = 0;
    this -> y = 0;
    this -> cellType = 'X';
}

Cell::Cell(int x, int y, char cellType){
    this -> x = x;
    this -> y = y;
    this -> cellType = cellType;
}

int Cell::getX(){ return x; }

int Cell::getY(){ return y; }

char Cell::getCellType(){ return cellType; }