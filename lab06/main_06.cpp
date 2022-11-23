#include <iostream>
#include "Polynomial.h"

int main() {


    Polynomial a(3, new double [4]{1, 2,6,9});
    cout << a;

    Polynomial b(2, new double [3]{2,3,6});
    cout << b;

    cout << "-a = " << -a;
    cout << "a+b = " << a+b;
    cout << "a-b = " << a-b;
    cout << "b-a = " << b-a << endl;


    Polynomial c(move(b));
    cout << c;
    cout << b;

    return 0;
}