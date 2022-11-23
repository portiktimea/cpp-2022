//
// Created by timea on 11/22/2022.
//

#ifndef CPP_2022_CEG_H
#define CPP_2022_CEG_H

#include <vector>
#include <algorithm>
#include "Szemely.h"
#include "Alkalmazott.h"
#include "Manager.h"

class Ceg {

private:
    vector<Alkalmazott*> alkalmazottak;
public:
    void deleteAlkalmazott(int id);
    void addAlkalmazott(Alkalmazott*);
    void addToManager(Alkalmazott* alkalmazott, Manager* manager);
    void printAll()const;
    void printManagers(ostream& os)const;
    void deleteFromManager(Alkalmazott* alkalmazott, Manager* manager);
};

#endif //CPP_2022_CEG_H
