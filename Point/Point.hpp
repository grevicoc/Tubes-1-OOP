//File Point.hpp
#ifndef POINT_HPP
#define POINT_HPP

#include "../Peta/cell.hpp"
#include "../Peta/peta.hpp"

class Point {
    public:
        Point();    // inisialisasi koordinat awal player di (0, 0)
        Point(int _x, int _y);  // inisialisasi koordinat awal player di (_x, _y)
        int getX();     // mendapatkan koordinat absis (x)
        int getY();     // mendapatkan koordinat ordinat (y)
        Point(Point& P);    // cctor
        Point& operator=(const Point& other); // operator
        static bool isValidPosisi(int _x, int _y); // menentukan apakah titik valid/tidak di luar map
        static bool isAdjacent(int _x1, int _y1, int _x2, int _y2);    // menentukan apa dua posisi bertetanggaan
        static bool isNextWater(int _x, int _y);   // menentukan apakah posisi tujuan adalah air
        static bool isNextGrass(int _x, int _y);   // menentukan apakah posisi tujuan adalah grassland

    protected:
        int x;
        int y;
};
#endif