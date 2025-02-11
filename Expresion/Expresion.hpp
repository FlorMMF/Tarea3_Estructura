#ifndef EXPRESION_HPP_INCLUDED
#define EXPRESION_HPP_INCLUDED

#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#define MAX_TAM 100

/**Clase de tipo lifo, contenedor de vaolres de tipo double
    \param Tipo de dato
 */
class Pila{
public:
    Pila();
    Pila(const Pila &p);
    ~Pila();
    Pila & operator=(const Pila &v);
    void Apilar(char valor);
    void Desapilar();
    char ObtenerTOPE() const;
    bool EstaVacia() const;
    void Vaciar();
    //para pruebas
    void imprimir() const;
private:
    int numElem;
    struct Elemento{
        char valor;
        Elemento *siguiente;
    }*tope;

};

#endif // PILA_HPP_INCLUDED


#endif // EXPRESION_HPP_INCLUDED
