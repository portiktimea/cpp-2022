#include <sstream>
#include "functions.h"

int main() {

//
//    for(int i=0; i<128; i++){
//        cout<<i<<": "<<countBits(i)<<"\n";
//    }


//    for (int i = 0; i < 35; ++i) {
//        int n = 0;
//        if(setBit(n, i)){
//            cout<<i<<" ---> " << n <<endl;
//        }else{
//            cout<<"Impossible operation!" << endl;
//        }
//    }
//

//    double array[5];
//    double array2[3];
//    int m=0;
//    int n;
//    cin >> n;
//    for(int i=0; i<n; i++){
//        cin>>array[i];
//    }
//
//    cout << mean(array, n) << "\n";
//    cout << mean(array2, m) << "\n";
//
//    cout << stddev(array, n) << "\n";
//    cout << stddev(array2, m) << "\n";
//
//    pair<double, double> max = max2(array, n);
//    cout << max.first << " " << max.second << "\n";
//
//    int k=1; double array3[1] = {4.5};
//    pair<double, double>maxi = max2(array3, k);
//    cout << maxi.first << " " << maxi.second;


//    istringstream iss("1 2 3 alma 4");
//    double number;
//    while(iss >> number){
//        cout<<number<<endl;
//    }

//    cout << sum() << "\n";

    string text;
    getline(cin, text);
    cout << countWords(text) <<"\n";

    string ctext = code(text);
    cout << ctext << "\n";
    cout << decode(ctext);

    cout << capitalizeWords(text);



    return 0;
}

