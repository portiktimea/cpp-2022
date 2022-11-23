//
// Created by timea on 11/16/2022.
//

#ifndef CPP_2022_ALKALMAZOTT_H
#define CPP_2022_ALKALMAZOTT_H

#include "Szemely.h"

class Alkalmazott: public Szemely{
    static int counter;
protected:
    string munkakor;
    int id;

public:
    Alkalmazott(string vezetekNev, string keresztNev,int szuletesiEv, string munkakor);
    virtual int getId() const;
    void print(ostream& os) const;
};

#endif //CPP_2022_ALKALMAZOTT_H
