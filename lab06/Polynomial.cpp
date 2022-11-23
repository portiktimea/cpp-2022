//
// Created by timea on 10/26/2022.
//

#include "Polynomial.h"

Polynomial::Polynomial(int degree, const double *coefficients) {
    this->capacity = degree + 1;
    this->coefficients = new double [capacity];
    for(int i=0; i < this->capacity; i++){
        this->coefficients[i] = coefficients[i];
    }
}

Polynomial::Polynomial(const Polynomial &that) {
    this->capacity = that.capacity;
    this->coefficients = new double[this->capacity];
    for(int i=0; i<this->capacity; i++){
        this->coefficients[i] = that.coefficients[i];
    }
}

Polynomial::Polynomial(Polynomial &&that) noexcept {
    if(this != &that){
        this->capacity = that.capacity;
        this->coefficients = that.coefficients;
        that.capacity = 0;
        that.coefficients = nullptr;
    }
}

Polynomial::~Polynomial() {
    if(this->coefficients){
        this->capacity = 0;
        delete []this->coefficients;
    }
}

int Polynomial::degree() const {
    return this->capacity-1;
}

Polynomial Polynomial::derivative() const {
    Polynomial derivPoly(this->capacity-1, this->coefficients);
    int szorzando = this->capacity - 1;
    for(int i=0; i< this->capacity; i++){
        derivPoly.coefficients[i] *= (szorzando--);
    }
    return derivPoly;
}

double Polynomial::operator[](int index) const {
    return this->coefficients[index];
}

Polynomial operator-(const Polynomial &a) {
    Polynomial negaltPoly(a);
    for(int i=0; i<negaltPoly.capacity; i++){
        negaltPoly.coefficients[i] *= -1;
    }
    return negaltPoly;
}

Polynomial operator+(const Polynomial &a, const Polynomial &b) {
    if(a.capacity > b.capacity){
        Polynomial osszegPoly(a);
        for(int i=0; i < b.capacity; i++){
            osszegPoly.coefficients[i + a.capacity - b.capacity] += b.coefficients[i];
        }
        return osszegPoly;
    }

    Polynomial osszegPoly(b);
    for(int i=0; i < a.capacity; i++){
        osszegPoly.coefficients[i + b.capacity - a.capacity] += a.coefficients[i];
    }
    return osszegPoly;
}


ostream &operator<<(ostream &out, const Polynomial &what) {
    if(what.capacity != 0){
        int i;
        for(i=0; i<what.capacity-1; i++){
            out << what.coefficients[i] << "x^" << what.capacity - i - 1 << " + ";
        }
        out << what.coefficients[i] << endl;
    }
    return out;
}

Polynomial operator-(const Polynomial &a, const Polynomial &b) {
    Polynomial negaltB(-b);
    return a + negaltB;
}

Polynomial operator*(const Polynomial &a, const Polynomial &b) {
    
}


