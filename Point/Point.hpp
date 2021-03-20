//File Point.hpp
#ifndef POINT_HPP
#define POINT_HPP

class Point {
    public:
        Point();    // inisialisasi koordinat awal player di (0, 0)
        Point(int _x, int _y);  // inisialisasi koordinat awal player di (_x, _y)
        int getX();     // mendapatkan koordinat absis (x)
        int getY();     // mendapatkan koordinat ordinat (y)

    protected:
        int x;
        int y;
};
#endif