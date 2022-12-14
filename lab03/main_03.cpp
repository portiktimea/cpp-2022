#include <iostream>
#include "list.h"
#include "stack.h"

int main() {

    List lista1 = List();
    lista1.insertFirst(10);
    lista1.insertFirst(20);
    lista1.insertFirst(5);

    lista1.print();

    std::cout << std::endl << std::endl;
    if(lista1.exists(10)){
        std::cout << "10-es benne van!" << std::endl;
    }
    else{
        std::cout << "10-es nincs benne!" << std::endl;
    }

    if(!lista1.exists(25)){
        std::cout << "25-os nincs benne!" << std::endl;
    }
    else{
        std::cout << "25-os benne van!" << std::endl;
    }

    try{
        int deletedValue = lista1.removeFirst();
        std::cout << deletedValue << " has been removed\n";
    }catch(std::invalid_argument& e){
        std::cout << e.what();
    }


    Stack stack;
    for (int i = 0; i < 50; i++) {
        stack.push(i);
    }
    for (int i = 0; i < 51; i++) {
        std::cout << stack.pop() << " " << i << std::endl;
    }
    stack.isEmpty();


    return 0;
}
