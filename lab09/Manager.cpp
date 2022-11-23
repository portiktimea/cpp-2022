//
// Created by timea on 11/16/2022.
//

#include <algorithm>
#include "Manager.h"

//Constructor
const string Manager::MANAGER_MUNKAKOR="manager";

Manager::Manager(string vezNev, string kNev, int szuletesiEv, string munkakor) : Alkalmazott(vezNev, kNev, szuletesiEv,
                                                                                             munkakor){

}

void Manager::addAlkalmazott(Alkalmazott* alk){
    this->beosztottak.push_back(alk);
}

void Manager::deleteAlkalmazott(int id){
    auto result = find_if(this->beosztottak.begin(),this->beosztottak.end(),[&id] (const Alkalmazott* e) {
        return e->getId()==id;
    });
    this->beosztottak.erase(result);
}

void Manager::print(ostream& os) const{
    cout<<"Manager "<< Manager::id << " ";
    Szemely::print(os);
    cout<<" beosztottjai:"<<endl;
    for(auto& it: beosztottak){
        cout<<"\t";
        it->print(os);
    }
}
