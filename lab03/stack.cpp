//
// Created by timea on 10/12/2022.
//

#include "stack.h"
#include "list.h"
#include "iostream"


void Stack::push(int number) {
    if (top == SIZE-1) {
        cout << "Stack is full!" << endl;
    }
    else{
        top++;
        stackArray[top] = number;
    }
}


int Stack::pop() {
    if (top == -1) {
        cout << "Stack is empty!" << endl;
        return 0;
    }
    else {
        int topx = top;
        top--;
        return stackArray[topx];
    }
}

bool Stack::isEmpty() const
{
    return top == -1;
}