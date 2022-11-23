//
// Created by timea on 11/22/2022.
//

#include "Ceg.h"
#include "Alkalmazott.h"
#include "Manager.h"


void Ceg::deleteAlkalmazott(int id){
    auto index = find_if(this->alkalmazottak.begin(),this->alkalmazottak.end(), [&id](Alkalmazott *szemely){
        return szemely->getId() == id;
    });
    this->alkalmazottak.erase(index);
}

void Ceg::printAll() const {
    cout<<"Ceg:"<<endl;
    for(auto& szemely: this->alkalmazottak){
        szemely->print(cout);
    }
}

void Ceg::addToManager(Alkalmazott* alkalmazott, Manager* manager) {
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [alkalmazott, manager](Alkalmazott *alkalmazott1) {
        if (alkalmazott1 == manager) {
            manager->addAlkalmazott(alkalmazott);
        }
    });

}

void Ceg::printManagers(ostream& os) const {
    os << "\nManagerek:" << endl;
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [&os](Alkalmazott *alkalmazott) {
        Manager *tempManager;
        tempManager = dynamic_cast<Manager *>(alkalmazott);
        if (tempManager != nullptr) {
            tempManager->print(os);
        }
    });
}

void Ceg::deleteFromManager(Alkalmazott* alkalmazott, Manager* manager) {
    for_each(alkalmazottak.begin(), alkalmazottak.end(), [alkalmazott, manager](Alkalmazott *alkalmazott1) {
        if (alkalmazott1 == manager) {
            manager->deleteAlkalmazott(alkalmazott->getId());
        }
    });
}

void Ceg::addAlkalmazott(Alkalmazott* alk) {
    this->alkalmazottak.emplace_back(alk);
}
