//
// Created by timea on 10/12/2022.
//

#ifndef CPP_2022_STACK_H
#define CPP_2022_STACK_H

#include <iostream>
#include "list.h"
#define SIZE 100
using namespace std;


class Stack {
    int stackArray[SIZE], top;
private:
    List list;
public:
    Stack() {
        top=-1;
        if(top==-1){
            cout<<"Stack created and is empty.";
        }
        else{
            for (int i=top;i>=0;i--){
                cout<<"value "<<i+1<<": "<<stackArray[i]<<endl;
            }
        }
    }
    void push(int number);
    int pop();
    bool isEmpty() const;
    ~Stack()
    {
        cout<<"Stack Destructed successfully\n";
    }
};


#endif //CPP_2022_STACK_H
