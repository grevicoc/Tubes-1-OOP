#include "../Peta/cell.hpp"
// #include "../Peta/peta.hpp"
#include "Point.hpp"

Point::Point () {
    this->x = 0;
    this->y = 0;
}

Point::Point (int _x, int _y) {
    this->x = _x;
    this->y = _y;
}

int Point::getX () {
    return this->x;
}

int Point::getY () {
    return this->y;
}

void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

void Point::set(int _x, int _y) {
    this->x = _x;
    this->y = _y;
}

Point::Point(const Point& P) {
    this->x = P.x;
    this->y = P.y;
}

Point& Point::operator=(const Point& other) {
    this->x = other.x;
    this->y = other.y;
    return *this;
}

bool Point::operator==(const Point& other){
    if (this->getX()==other.x && this->getY()==other.y){
        return true;
    }else{
        return false;
    }
}

bool Point::operator!=(const Point& other){
    if (this->getX()!=other.x || this->getY()!=other.y){
        return true;
    }
    return false;
}

bool Point::isValidPosisi(int _x, int _y) {
    return (_x >= 0 && _x < 10 && _y >= 0 && _y < 12);
}

bool Point::isAdjacent(int _x1, int _y1, int _x2, int _y2) {
    return (_x1 == _x2 + 1 && _y1 == _y2) || (_x1 = _x2 - 1 && _y1 == _y2) || (_x1 == _x2 && _y1 == _y2 + 1) || (_x1 = _x2 && _y1 == _y2 - 1);
}

// bool Point::isPosisiNotEngimonRelatif(int _x, int _y){
//     return getTypePetaRelatif(_x,_y) == 'o' || getTypePetaRelatif(_x,_y) == '-';
// }

// char Point::getTypePeta(int _x, int _y) {
//     return (Peta::peta[_x][_y].getCellType());
// }

// char Point::getTypePetaRelatif(int _x, int _y) {
//     int xRel = x + _x;
//     int yRel = y + _y;
//     return Peta::peta[xRel][yRel].getCellType();
// }
