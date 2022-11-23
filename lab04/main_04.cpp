#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <random>

#define MAX 1000
using namespace std;
#include "PointSet.h"

using namespace std;

int main() {

//    //Definíció - üres dinamikus tömb
//    vector<int> v;
// //Feltöltés: új elem hozzáadása: push_back VAGY emplace_back
//    for( int i=0; i<10; ++i ){
//        v.push_back( i * 10 );
//    }
// //Kiíratás
//    for(int i=0; i<v.size(); ++i ){
//        cout<<v[ i ]<<" ";
//    }
//    cout<<endl;
//
//
//    vector<string> fruits {"apple","melon"};
//    fruits.push_back("pear"); fruits.push_back("nut");
//    // Iterate over the elements in the vector and print them
//    for (auto it = fruits.cbegin(); it != fruits.cend(); ++it) {
//        cout << *it << endl;
//    }
//    //Print the elements again using C++11 range-based for loop
//    for (auto& str : fruits) {
//        cout << str << endl;
//    }



    int x[100];
    int n = 10;
    cout<<"x = [";
    for( int i=0; i<n; ++i ){
        x[i] = rand() % MAX;
        cout<<x[i]<<" ";
    }
    cout << "]" <<endl;
    cout << "Legkisebb : " << *min_element(x, x+n) << endl;
    vector<int> v;
    v.reserve(100);
    cout<<"v = [";
    for( int i=0; i<n; ++i ){
        v.emplace_back( rand() % MAX );
        cout<<v[ i]<<" ";
    }
    cout << "]" <<endl;
    cout << "Legnagyobb: " << *max_element(v.begin(),v.end()) << endl;




//    random_device rd; // seed the random number generator named rd
//    mt19937 mt(rd());
//    uniform_int_distribution<int> dist(0, M); // return a number in the given range
//
//    int x = dist(mt);
//    int y = dist(mt);
//
//    cout << x << " " << y;



    int k = 2;
    cout << "Pontok\tMinTav\t MaxTav\t #tavolsagok\t#kulonbozotavolsagok" << endl;
    cout << fixed;
    for (int i = 0; i < 12; ++i) {
        PointSet pSet(k);
        cout << setw(6) << k << " ";
        cout << setw(8) << setprecision(2) << pSet.minDistance() << " ";
        cout << setw(8) << setprecision(2) << pSet.maxDistance() << " ";
        cout << setw(10) << pSet.numDistances() << " ";
        cout << setw(16) << pSet.numDistinctDistances() << endl;
        k = k << 1;
    }

    PointSet pset1(10);
    cout<<"#points: " <<Point::getCounter()<<endl;
    PointSet pset2(20);
    cout<<"#points: " <<Point::getCounter()<<endl;

    return 0;
}