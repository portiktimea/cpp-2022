#include "Matrix.h"

Matrix::Matrix(int mRows, int mCols) {
    this->mRows = mRows;
    this->mCols = mCols;
    this->mElements = new double *[mRows];
    for(int i=0; i<mRows; i++){
        this->mElements[i] = new double [mCols];
    }
}

Matrix::Matrix(const Matrix &what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = new double *[this->mRows];
    for(int i=0; i<this->mRows; i++){
        this->mElements[i] = new double [this->mCols];
        for(int j=0; j< this->mCols; j++){
            this->mElements[i][j] = what.mElements[i][j];
        }
    }
}

Matrix::Matrix(Matrix &&what) {
    this->mRows = what.mRows;
    this->mCols = what.mCols;
    this->mElements = what.mElements;

    what.mRows = 0;
    what.mCols = 0;
    what.mElements = nullptr;
}

Matrix::~Matrix() {
    for(int i=0; i<mRows; i++){
        delete[]this->mElements[i];
    }
    delete []this->mElements;
    this->mRows = 0;
    this->mCols = 0;
}

void Matrix::fillMatrix(double value) {
    for(int i=0; i<this->mRows; i++){
        for(int j=0; j< this->mCols; j++){
            this->mElements[i][j] = value;
        }
    }
}

void Matrix::printMatrix(ostream &os) const {
    for(int i=0; i<this->mRows; i++){
        for(int j=0; j< this->mCols; j++){
            os << this->mElements[i][j];
        }
        os << endl;
    }
}

Matrix operator+(const Matrix& x, const Matrix& y){
    if(x.mRows == y.mRows && x.mCols == y.mCols){
        Matrix temp(x.mRows, x.mCols);
        for(int i=0; i<x.mRows; i++){
            for(int j=0; j< x.mCols; j++){
                temp[i][j] = x[i][j] + y[i][j];
            }
        }
        return temp;
    }
    throw out_of_range("Dimensions error\n");
}

Matrix operator*(const Matrix& x, const Matrix& y){
    if(x.mRows == y.mCols){
        Matrix temp (x.mRows, y.mCols);
        temp.fillMatrix(0);

        for(int i=0; i<x.mRows; i++){
            for(int j=0; j<x.mCols; j++){
                for(int k=0; j<y.mRows; k++){
                    temp.mElements[i][j] += x.mElements[i][k] * y.mElements[k][j];
                }
            }
        }
        return temp;
    }
    throw out_of_range("Dimensions error\n");
}

Matrix &Matrix::operator=(const Matrix &mat) {
    if(this->mRows == mat.mRows && this->mCols == mat.mCols){
        for(int i=0; i<this->mRows; i++){
            for(int j=0; j<this->mCols; j++){
                this->mElements[i][j] = mat.mElements[i][j];
            }
        }
        return *this;
    }
    throw out_of_range("Dimensions error\n");
}

Matrix &Matrix::operator=(Matrix &&mat) {
    for(int i=0; i<this->mRows; i++){
        delete []this->mElements[i];
    }
    delete []this->mElements;

    this->mRows = mat.mRows;
    this->mCols = mat.mCols;
    this->mElements = mat.mElements;

    mat.mRows = 0;
    mat.mCols = 0;
    mat.mElements = nullptr;

    return *this;
}

double *Matrix::operator[](int index) {
    return this->mElements[index];
}

double *Matrix::operator[](int index) const {
    return this->mElements[index];
}

ostream & operator<<(ostream& os, const Matrix& mat){
    mat.printMatrix(os);
    return os;
}

istream & operator>>(istream& is, Matrix& mat){
    for(int i=0; i<mat.mRows; i++){
        for(int j=0; j<mat.mCols; j++){
            is >> mat.mElements[i][j];
        }
    }
    return is;
}