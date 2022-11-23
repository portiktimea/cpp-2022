#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    ///1. exercise
    cout<<"1.feladat"<<endl;
    vector<string> fruits {
            "melon", "strawberry", "raspberry","apple",
            "banana", "walnut", "lemon" };

    string what_to_find="berry";
    auto result1=find_if(fruits.begin(), fruits.end(),[&what_to_find](const string& res){
        return res.find(what_to_find);
    });

    (result1 != end(fruits))
    ? cout << "fruits contains " << what_to_find << '\n'
    : cout << "fruits does not contain " << what_to_find << '\n';
    cout<<endl;

    ///2.exercise
    cout << "2.feladat" << endl;
    vector<int> v = {1,2,3,4,5};
    for_each(v.begin(), v.end(),[](const int& e){
        cout << e << " ";
    });
    cout << endl;
    std::generate(v.begin(), v.end(), [n = 0] () mutable { return n+=2; });
    for_each(v.begin(), v.end(),[](const int& e){
        cout << e << " ";
    });
    cout << endl;
    auto result2 = all_of(v.begin(),v.end(),[](const int& e){
        return e%2 == 0;
    });
    cout << (result2 ? "Mind paros" : "Nem mind paros") << endl;
    cout<<endl;

    ///3.exercise
    cout << "3.feladat" << endl;
    for_each(v.begin(),v.end(),[](int& e){
        e+=e;
    });
    for_each(v.begin(),v.end(),[](const int& e){
        cout<<e<<" ";
    });
    cout<<endl;
    cout<<endl;

    ///4.exercise
    cout << "4.feladat" << endl;
    vector<string> months {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };


    return 0;
}