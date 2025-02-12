   #include <iostream>




//******************************************
template <typename Tipo>
Pila<Tipo>::Pila(): numElem(0), tope(nullptr){


}
template <typename Tipo>
Pila<Tipo>::Pila(const Pila<Tipo> &p): numElem(0), tope(nullptr){
    *this = p;
}
 template <typename Tipo>
Pila<Tipo>::~Pila(){
    Vaciar();
}

template <typename Tipo>
Pila<Tipo> & Pila<Tipo>::operator=(const Pila<Tipo> &v){
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

template <typename Tipo>
void Pila<Tipo>::Vaciar(){
    while(!EstaVacia()) Desapilar();
}

template <typename Tipo>
void Pila<Tipo>::Apilar(Tipo valor){
    Elemento *nuevo = new Elemento;
    nuevo -> valor = valor;
    nuevo ->  siguiente = tope;
    tope = nuevo;
    ++numElem;

}

template <typename Tipo>
void Pila<Tipo>::Desapilar(){
    if(EstaVacia())throw "La Pila esta vac\241a";
    Elemento *porBorrar =tope;
    tope = tope -> siguiente;
    delete porBorrar;
    --numElem;
}

template <typename Tipo>
Tipo Pila<Tipo>::ObtenerTOPE() const {
    if(EstaVacia()) throw "Esta pila esta vacia...";
    return tope -> valor;

}

template <typename Tipo>
bool Pila<Tipo>::EstaVacia() const{
    return numElem == 0;
}




template <typename Tipo>
void Pila<Tipo>::imprimir() const{
    Elemento *aux = tope;

    while(aux != nullptr){
        std::cout << aux -> valor <<  ",";
        aux = aux -> siguiente;
    }



}
