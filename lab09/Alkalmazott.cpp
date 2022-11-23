//
// Created by timea on 11/16/2022.
//
#include "Alkalmazott.h"

Alkalmazott::Alkalmazott(string vezNev, string kNev, int szulEv, string munkakor):Szemely(vezNev,kNev,szulEv){
    this->munkakor=munkakor;
    this->id = ++counter;
}

void Alkalmazott::print(ostream &os) const{
    os<<"Alkalmazott "<<getId()<<" ";
    Szemely::print(os);
    os<<" "<<this->munkakor;
    os<<endl;
}

int Alkalmazott::counter{0};

int Alkalmazott::getId() const {
    return id;
}
