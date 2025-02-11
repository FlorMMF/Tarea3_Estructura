   #include <iostream>

#include "Expresion.hpp"


//******************************************

Pila::Pila(): numElem(0), tope(nullptr){


}

Pila::Pila(const Pila &p): numElem(0), tope(nullptr){
    *this = p;
}

Pila::~Pila(){
    Vaciar();
}


Pila & Pila::operator=(const Pila &v){
     if (this == &v) return *this;
    this ->Vaciar();
    Elemento *aux = v.tope;
    Elemento *pilaAux[v.numElem];

    for(int i =v.numElem -1; i >= 0 ; --i){
        pilaAux[i] = aux;
        aux = aux -> siguiente;
    }

    for(int i =0; i < v.numElem ; ++i){
        Apilar(pilaAux[i] -> valor);
    }


    return *this;

 }


void Pila::Vaciar(){
    while(!EstaVacia()) Desapilar();
}


void Pila::Apilar(char valor){
    Elemento *nuevo = new Elemento;
    nuevo -> valor = valor;
    nuevo ->  siguiente = tope;
    tope = nuevo;
    ++numElem;

}


void Pila::Desapilar(){
    if(EstaVacia())throw "La Pila esta vac\241a";
    Elemento *porBorrar =tope;
    tope = tope -> siguiente;
    delete porBorrar;
    --numElem;
}


char Pila::ObtenerTOPE() const {
    if(EstaVacia()) throw "Esta pila esta vacia...";
    return tope -> valor;

}


bool Pila::EstaVacia() const{
    return numElem == 0;
}





void Pila::imprimir() const{
    Elemento *aux = tope;

    while(aux != nullptr){
        std::cout << aux -> valor <<  ",";
        aux = aux -> siguiente;
    }



}

