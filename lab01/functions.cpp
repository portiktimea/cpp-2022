//
// Created by timea on 10/9/2022.
//

#include <sstream>
#include "functions.h"

int countBits(int number) {
    int count = 0;
    while(number){
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool setBit(int &number, int order) {
    if( order < 0 || order >31){
        return false;
    }
    if(order == 0){
        return true;
    }
    int bit = number | (1 << (order - 1));
    if(bit==1){return true;}
    return false;
}


double mean(const double array[], int numElements) {
    if(numElements <= 0){
        return NAN;
    }
    double sum=0;
    for(int i=0; i<numElements; i++){
        sum += array[i];
    }
    return sum/numElements;
}

double stddev(double *array, int numElements) {
    if(!numElements || mean(array, numElements) == NAN){
        return NAN;
    }
    double sum = 0, mean, dev = 0;
    for(int i=0; i<numElements; i++){
        sum += array[i];
    }
    mean = sum / numElements;
    for(int i=0; i<numElements; i++){
        dev += pow(array[i] - mean, 2);
    }
    return sqrt(dev/10);
}

pair<double, double> max2(double array[], int numElements){
    pair<double,double> max(NAN,NAN);
    if(numElements < 1){
        return max;
    }
    if(numElements == 1){
        max = make_pair(array[0],array[0]);
        return max;
    }
    if(array[0] < array[1]){
        max.first = array[0];
        max.second = array[1];
    } else{
        max.first = array[1];
        max.second = array[0];
    }
    for (int i = 2; i < numElements; ++i) {
        if(max.first < array[i]){
            max.first = max.second;
            max.second = array[i];
        } else if(max.second < array[i]){
            max.second = array[i];
        }
    }
    return max;
}

double sum(){
    string words;
    double sum=0;
    getline(cin, words);
    int n = words.length();
    istringstream iss(words);
    double number;
    while(n){
        if(iss >> number){
            sum += number;
        }
        n--;
    }
    return sum;
}

int countWords(const string& text){
    istringstream newr(text);
    int n = 0;
    string words;
    while(newr >> words){
        n++;
    }
    return n;
}

string code(string text){
    int j=0;
    for(char i: text){
        if(i <= 122 && i >= 97){
            if(i == 'z'){
                text[j] = 'a';
            }
            else{
                text[j]++;
            }
        }
        if(i <= 90 && i >= 65){
            if(i == 'Z'){
                text[j] = 'A';
            }
            else{
                text[j]++;
            }
        }
        j++;
    }
    return text;
}

string decode(string text){
    int j=0;
    for(char i: text){
        if(i <= 122 && i >= 97){
            if(i == 'a'){
                text[j] = 'z';
            }
            else{
                text[j]--;
            }
        }
        if(i <= 90 && i >= 65){
            if(i == 'A'){
                text[j] = 'Z';
            }
            else{
                text[j]--;
            }
        }
        j++;
    }
    return text;
}

string capitalizeWords(string text){
    if(text[0] >= 'a' && text[0] <= 'z'){
        text[0] -=32;
    }
    for (int i = 1;i < text.length(); ++i) {
        if(text[i - 1] == ' ' && text[i] >= 'a' && text[i] <='z'){
            text[i] -= 32;
        } else{
            if(text[i] >= 'A' && text[i] <= 'Z'){
                text[i] += 32;
            }
        }
    }
    cout << endl;
    return text;
}


