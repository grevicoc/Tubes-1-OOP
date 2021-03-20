#include "../Peta/cell.hpp"
#include "../Peta/peta.hpp"
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

Point::Point(Point& P) {
    this->x = P.x;
    this->y = P.y;
}

Point& Point::operator=(const Point& other) {
    this->x = other.x;
    this->y = other.y;
}

bool Point::isValidPosisi(int _x, int _y) {
    return (_x >= 0 && _x < 10 && _y >= 0 && _y < 12);
}

bool Point::isAdjacent(int _x1, int _y1, int _x2, int _y2) {
    return ((_x1 == _x2 + 1 && _y1 == _y2) || (_x1 = _x2 - 1 && _y1 == _y2) || (_x1 == _x2 && _y1 == _y2 + 1) || (_x1 = _x2 && _y1 == _y2 - 1));
}

bool Point::isNextWater(int _x, int _y) {
    return (Peta::getTypePeta(_x,_y) == 'o');
}

bool Point::isNextGrass(int _x, int _y) {
    return (Peta::getTypePeta(_x,_y) == '-');
}