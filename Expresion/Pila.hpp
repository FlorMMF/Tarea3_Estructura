#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

template <typename Tipo>
/**Clase de tipo lifo, contenedor de vaolres de tipo double
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
#include "Pila.tpp"

#endif // PILA_HPP_INCLUDED
