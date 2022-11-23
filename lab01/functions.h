//
// Created by timea on 10/9/2022.
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H

using namespace std;

#include <cmath>
#include <utility>
#include <iostream>

int countBits(int number);
bool setBit(int& number, int order);
double mean(const double array[], int numElements);
double stddev(double array[], int numElements);
pair<double, double> max2(double array[], int numElements);
double sum();
int countWords(const string& text);
string code(string text);
string decode(string text);
string capitalizeWords(string text);


#endif //CPP_2022_FUNCTIONS_H
