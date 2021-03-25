//File Point.hpp
#ifndef POINT_HPP
#define POINT_HPP

#include "../Peta/cell.hpp"


class Point{
    public:
        Point();    // inisialisasi koordinat awal player di (0, 0)
        Point(int _x, int _y);  // inisialisasi koordinat awal player di (_x, _y)
        int getX();     // mendapatkan koordinat absis (x)
        int getY();     // mendapatkan koordinat ordinat (y)
        void setX(int); // merubah koordinat absis (x)
        void setY(int); // merubah koordinat ordinat (y)
        void set(int _x, int _y);   // mengubah posisi (x,y) menjadi (_x, _y)
        Point(const Point& P);    // cctor
        Point& operator=(const Point& other); // operator
        // bool operator==(const Point& other);
        // bool operator!=(const Point& other);
        static bool isValidPosisi(int _x, int _y); // menentukan apakah titik valid/tidak di luar map
        static bool isAdjacent(int _x1, int _y1, int _x2, int _y2);    // menentukan apa dua posisi bertetanggaan
        bool isPosisiNotEngimonRelatif(int _x, int _y); // menentukan apakah posisi relatif terhadap objek Point bukanlah Engimon
        // char getTypePeta(int _x, int _y); // menentukan type peta dari suatu point
        // char getTypePetaRelatif(int _x, int _Y); // menetukan type peta relatif dari suatu objek Point

    protected:
        int x;
        int y;
};
#endif