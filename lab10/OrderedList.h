//
// Created by timea on 11/23/2022.
//

#ifndef CPP_2022_ORDEREDLIST_H
#define CPP_2022_ORDEREDLIST_H

#include <functional>
#include <iostream>

using namespace std;


template< class T, class LessComp=less<T>, class Equal=equal_to<T> >
class Iterator;

template <class T, class LessComp = less<T>, class Equal = equal_to<T> >
class OrderedList{
private:
    struct Node{
        T value;
        Node* next;

        Node(T value,Node* next= nullptr):value(value) , next(next){}
    };
    Node* first {nullptr};
    int numElements=0;

    friend class Iterator<T, LessComp, Equal>;



public:
    void listItems(ostream& os = cout);
    void insert(const T& what);
    ~OrderedList();
    bool isEmpty();
    void remove(const T& what);
    int size();
    bool find(const T& what);
};

template< class T, class LessComp, class Equal >
class Iterator{
    OrderedList<T, LessComp, Equal>& list;
    typename OrderedList<T, LessComp, Equal>::Node* act;
public:
    Iterator(OrderedList<T, LessComp, Equal> &orderedList):
    list(list), act(list.first) {}
    bool hasNext();
    T next();
};

template<class T, class LessComp, class Equal>
T Iterator<T, LessComp, Equal>::next() {
    auto aux=act->value;
    act=act->next;
    return aux;
}

template<class T, class LessComp, class Equal>
bool Iterator<T, LessComp, Equal>::hasNext() {
    if(act == nullptr){
        return false;
    }
    return true;
}


template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::listItems(ostream &os) {
    Node* aux = first;
    while(aux!= nullptr){
        os<<aux->value<<" ";
        aux=aux->next;
    }
    cout<<endl;

}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::insert(const T &what) {
    Node* newNode = new Node(what);
    Node* act = first;
    Node* prev = nullptr;
    while(act!= nullptr && LessComp()(act->value,what)){
        prev=act;
        act=act->next;
    }
    if(prev== nullptr){
        newNode->next=first;
        first=newNode;
        ++numElements;
        return;
    }
    prev->next=newNode;
    newNode ->next=act;
    ++numElements;

}

template<class T, class LessComp, class Equal>
OrderedList<T, LessComp, Equal>::~OrderedList() {
    while(first!= nullptr){
        Node*aux=first;
        first=first->next;
        delete aux;
    }
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::isEmpty() {
    if(first== nullptr){
        return true;
    }
    return false;
}

template<class T, class LessComp, class Equal>
int OrderedList<T, LessComp, Equal>::size() {
    return numElements;
}

template<class T, class LessComp, class Equal>
bool OrderedList<T, LessComp, Equal>::find(const T &what) {
    Node* act = first;
    while(act!= nullptr ){
        if(Equal()(act->value,what)){
            return true;
        }
        act=act->next;
    }
    return false;
}

template<class T, class LessComp, class Equal>
void OrderedList<T, LessComp, Equal>::remove(const T &what) {
    Node *before = first,
        *actual = first;
    while (actual != nullptr){
        if (actual->what == what && actual == first){
            first = actual->next;
            delete actual;
            actual=first;
            continue;
        }
        if (actual->what == what){
            before->next=actual->next;
            delete actual;
            actual = before->next;
            continue;
        }
        before=actual;
        actual=actual->next;
    }
    before= nullptr;
}







#endif //CPP_2022_ORDEREDLIST_H
