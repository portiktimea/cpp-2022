//
// Created by timea on 10/9/2022.
//

#ifndef CPP_2022_UTIL_H
#define CPP_2022_UTIL_H

#include "Point.h"
#include <cmath>
#include <iostream>
#include <fstream>
using namespace std;

double distance(const Point& a, const Point& b);
bool isSquare(const Point& a, const Point& b, const Point& c, const Point& d);
void testIsSquare(const char * filename);
Point* createArray(int numPoints);
void printArray(Point* points, int numPoints);
pair<Point, Point> closestPoints(Point* points, int numPoints);
pair<Point, Point> farthestPoints(Point* points, int numPoints);
void sortPoints(Point* points, int numPoints);
Point* farthestPointsFromOrigin(Point* points, int numPoints);
void deletePoints(Point* points);


#endif //CPP_2022_UTIL_H
