#include "cell.hpp"

Cell::Cell(){
    point.first = 0;
    point.second = 0;
    this -> cellType = 'X';
}

Cell::Cell(int x, int y, char cellType){
    point.first = x;
    point.second = y;
    this -> cellType = cellType;
}

Cell& Cell::operator=(const Cell& other) {
    point = other.point;
    this->cellType = other.cellType;
    return *this;
}

int Cell::getX(){ return point.first; }

int Cell::getY(){ return point.second; }

char Cell::getCellType(){ return cellType; }