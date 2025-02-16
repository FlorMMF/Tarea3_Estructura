#ifndef LAPILA_HPP_INCLUDED
#define LAPILA_HPP_INCLUDED

template <typename Tipo>
/**

 * \file LaPila.hpp

 * Este archivo contiene la declaraci�n de la clase Pila y sus m�todos

 * \author Flor Machado y Elias Peregrina

 * \date 15/02/2025

 */
/**Clase de tipo lifo,
    \param Tipo de dato
 */
class Pila{
public:
    Pila();
    Pila(const Pila &p);
    ~Pila();
    Pila & operator=(const Pila &v);
    void Apilar(Tipo valor);
    void Desapilar();
    Tipo ObtenerTOPE() const;

    bool EstaVacia() const;


    void Vaciar();
    //para pruebas
    void imprimir() const;
private:
    int numElem;
    struct Elemento{
        Tipo valor;
        Elemento *siguiente;
    }*tope;

};
#include "LaPila.tpp"

#endif // LAPILA_HPP_INCLUDED
