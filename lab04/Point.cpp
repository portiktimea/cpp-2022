//
// Created by timea on 10/12/2022.
//

#include <iostream>
#include "Point.h"

Point::Point(int x, int y) {
    if((x>=0 && x<=M) && (y>=0 && y<=M)){

    }
    this->x = x;
    this->y = y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

double Point::distanceTo(const Point &point) const {
    return sqrt(pow(this->x-point.getX(),2) + pow(this->y-point.getY(),2));
}

void Point::print() const{
    std::cout << this->x << this->y << std::endl;
}