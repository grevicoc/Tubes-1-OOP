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

void Cell::setX(int x){
    point.first = x;
}

int Cell::getY(){ return point.second; }

void Cell::setY(int y){
    point.second = y;
}

char Cell::getCellType(){ return cellType; }

void Cell::setCellType(char c){
    cellType = c;
}