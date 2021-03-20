  
#include "Point.hpp"

Point::Point () {
    x = 0;
    y = 0;
}

int Point::getX () {
    return x;
}

int Point::getY () {
    return y;
}

void Point::set(int _x, int _y) {
    x = _x;
    y = _y;
}