//
// Created by timea on 11/16/2022.
//

#ifndef CPP_2022_MANAGER_H
#define CPP_2022_MANAGER_H

#include "Alkalmazott.h"
#include <vector>

using namespace std;

class Manager : public Alkalmazott {

private:

    vector<Alkalmazott*> beosztottak;

public:
    const static string MANAGER_MUNKAKOR;
    Manager(string vezNev, string kNev, int szuletesiEv, string munkakor);
    void addAlkalmazott(Alkalmazott*);
    void deleteAlkalmazott(int id);
    int beosztottakSzama() const{return this->beosztottak.size();}
    void print(ostream& os) const;
};

#endif //CPP_2022_MANAGER_H
