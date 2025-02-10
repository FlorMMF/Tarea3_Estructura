#include <iostream>
#include "Vector.hpp"
#include <cmath>
using  namespace std;
//
//Vector::Vector(){
//    dim = 7;
//    for(int i = 0; i < 7 ; ++ i){
//        componente[i] = 0;
//    }
//
//}
//
//Vector::Vector(int dimension){
//    EstablecerDim(dimension);
//    for(int i = 0; i < dim ; ++ i){
//        componente[i] = 0;
//    }
//}

Vector::Vector(int dimension, double valor){
    EstablecerDim(dimension);
    try{
        componente = new double [dim];
        for(int i = 0; i < dim ; ++ i){
            componente[i] = valor;
        }
    }catch(bad_alloc &){
        throw "Problema de asignacion de memoria";
    }

}

Vector::Vector(const Vector &v) : componente(nullptr){
    componente = nullptr;
    *this = v;

}

Vector::~Vector(){
    delete[] componente;
 }

//***************************************************************************************

void Vector::Imprimir(){
    cout << "(";
    for(int i = 0 ; i < dim ; ++i){
        cout << componente[i] << ", ";
    }
    cout << "\b\b)";
}

void Vector::Capturar(){
    for(int i = 0; i  < dim ; ++i){
        cout << "Componente " << i+1 << ": ";
        cin >> componente[i];
    }
}

Vector Vector::operator+(const Vector v) const{

    if(dim != v.dim)throw "Vectores incompatibles para la suma";
    Vector s(dim);
    for(int i = 0; i < s.dim ; ++ i){
        s.componente[i] = componente[i] + v.componente[i];
    }
    return s;
}

Vector Vector::operator-(const Vector v)const{

    if(dim != v.dim)throw "Vectores incompatibles para la suma";
    Vector s(dim);
    for(int i = 0; i < s.dim ; ++ i){
        s.componente[i] = componente[i] - v.componente[i];
    }
    return s;
}

double Vector::operator*(const Vector v)const{
    if(dim != v.dim)throw "Vectores incompatibles para el producto punto";
    double resultado = 0;
    for(int i = 0; i < dim ; ++ i){
        resultado = resultado + componente[i]*v.componente[i];
    }
    return resultado;
}

Vector Vector::operator*(double  escalar)const{
    Vector v(dim);
    for(int i = 0; i < dim ; ++ i){
        v.componente[i] = componente[i]*escalar;
    }
    return v;
 }

 double Vector::Norma()const{
    double resultado = 0;
    for(int i = 0; i < dim ; ++ i){
        resultado = resultado + componente[i]*componente[i];
    }

    return sqrt(resultado);

 }
 //****************************
 Vector operator* (double escalar, const Vector v){
    Vector s(v.dim);
    for(int i = 0; i < v.dim ; ++ i){
        s.componente[i] = v.componente[i]*escalar;
    }
    return s;
 }
std::ostream & operator<< (std::ostream &salida, const Vector v){
    salida << "(";
    for(int i = 0 ; i < v.dim ; ++i){
        cout << v.componente[i] << ", ";
    }
    cout << "\b\b)";
    return salida;
 }

 std::istream & operator>> (std::istream &entrada, Vector &v){
    for(int i = 0; i  < v.dim ; ++i){
        cout << "Componente " << i+1 << ": ";
        entrada >> v.componente[i];
    }
    return entrada;

 }

 double Vector :: operator[](int i)const {
    if(i  <  0 || i  >= dim ) throw "indice invalido";
    return componente[i];
 }

 double & Vector::operator [](int i){
    if(i  <  0 || i  >= dim ) throw "indice invalido";
    return componente[i];

 }

 Vector & Vector::operator=(const Vector &v){
     if (this == &v) return *this;
    delete [] componente;
    dim = v.dim;
    try{
        componente = new double [dim];
        for(int i = 0; i < dim ; ++ i){
            componente[i] = v.componente[i];
        }
    }catch(bad_alloc &){
        throw "Problema de asignacion de memoria";
    }
    return *this;

 }
 //metodo de utilieria
 void Vector::EstablecerDim(int dimension){
    if(dimension > 10 ||  dimension < 1){
        throw "La dimension es invalida";
    }
    dim = dimension;
 }



