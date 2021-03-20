  
#include "Point.hpp"

Point::Point () {
    x = 0;
    y = 0;
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