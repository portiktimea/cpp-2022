//
// Created by timea on 10/12/2022.
//

#ifndef CPP_2022_POINT_H
#define CPP_2022_POINT_H

#include <math.h>
#define M 2000

class Point{
private:
    int x, y;
public:
    Point( int x=0, int y=0);
    int getX() const;
    int getY() const;
    double distanceTo(const Point& point)const ;

    void print() const;
};

#endif //CPP_2022_POINT_H
