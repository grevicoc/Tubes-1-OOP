//File Point.hpp
#ifndef POINT_HPP
#define POINT_HPP

class Point {
    public:
        Point();    // inisialisasi koordinat awal player di (0, 0)
        int getX();     // mendapatkan koordinat absis (x)
        int getY();     // mendapatkan koordinat ordinat (y)
        void set(int _x, int _y);   // mengubah posisi (x,y) player menjadi _x dan _y

    protected:
        int x;
        int y;
};
#endif