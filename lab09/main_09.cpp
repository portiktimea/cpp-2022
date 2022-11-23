#include <iostream>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"
#include "Ceg.h"

int main() {

    ///Proba
//    Szemely sz1("Bonta", "Timea", 2002);
//    cout<<sz1<<endl;
//
//    cout<<endl;
//    Alkalmazott a1("Nagy","Laszlo",1980,"Music");
//    a1.print(cout);
//    Alkalmazott a2("Kiss","Reka",1988,"Music");
//    a2.print(cout);
//    Alkalmazott a3("Portik","Kinga",1991,"Automobiles");
//    a3.print(cout);
//
//    cout<<endl;
//    Manager m1("Szasz","Adam",1990,"Music");
//    m1.addAlkalmazott(&a1);
//    m1.addAlkalmazott(&a2);
//    m1.addAlkalmazott(&a3);
//
//    m1.print(cout);
//
//    cout<<endl;
//    m1.deleteAlkalmazott(a3.getId());
//    m1.print(cout);

    Ceg ceg;
    Alkalmazott a1("Nagy", "Laszlo",1990,"info");
    Alkalmazott a2("Kiss", "Reka",1991,"info");
    Alkalmazott a3("Portik", "Aniko",1992,"info");
    Alkalmazott a4("Veress", "Csaba",1993,"info");
    Alkalmazott a5("Fekete", "Zoltan",1994,"info");
    Alkalmazott a6("Feher", "Hunor",1995,"info");
    Alkalmazott a7("Laszlo", "Kinga",1996,"info");
    Manager a8("Bonta", "Mark",1997,"info");
    Manager a9("Kedves", "Szilard",1998,"info");
    Manager a10("Ferencz", "Katalin",1999,"info");

    ceg.addAlkalmazott(&a1);
    ceg.addAlkalmazott(&a2);
    ceg.addAlkalmazott(&a3);
    ceg.addAlkalmazott(&a4);
    ceg.addAlkalmazott(&a5);
    ceg.addAlkalmazott(&a6);
    ceg.addAlkalmazott(&a7);
    ceg.addAlkalmazott(&a8);
    ceg.addAlkalmazott(&a9);
    ceg.addAlkalmazott(&a10);

    ceg.printAll();

    ceg.addToManager(&a1, &a8);
    ceg.addToManager(&a2, &a8);
    ceg.addToManager(&a3, &a9);
    ceg.addToManager(&a4, &a9);
    ceg.addToManager(&a5, &a10);
    ceg.addToManager(&a6, &a10);
    ceg.addToManager(&a7, &a10);

    ceg.printManagers(cout);

    ceg.deleteFromManager(&a1, &a8);
    ceg.addToManager(&a1, &a10);

    cout << "\nAthelyezes utan:";
    ceg.printManagers(cout);

    return 0;
}