//
// Created by timea on 11/16/2022.
//

#include "Szemely.h"

#include <utility>

Szemely::Szemely(string vNev, string kNev, int szEv) {
    this->keresztNev = std::move(kNev);
    this->vezetekNev = std::move(vNev);
    this->szuletesiEv = szEv;
}

void Szemely::print(ostream& os) const{
    os<<this->vezetekNev;
    os<<" "<<this->keresztNev;
}

ostream & operator<<(ostream &out, const Szemely& szemely){
    szemely.print(out);
    return out;
}

