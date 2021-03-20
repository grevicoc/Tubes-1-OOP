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

Cell& Cell::operator=(const Cell& other) {
    this->x = other.x;
    this->y = other.y;
    this->cellType = other.cellType;
    return *this;
}

int Cell::getX(){ return x; }

int Cell::getY(){ return y; }

char Cell::getCellType(){ return cellType; }