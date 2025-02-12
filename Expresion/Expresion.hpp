#ifndef EXPRESION_HPP_INCLUDED
#define EXPRESION_HPP_INCLUDED

#ifndef PILA_HPP_INCLUDED
#define PILA_HPP_INCLUDED

#define MAX_TAM 100

/**Clase de tipo lifo, contenedor de vaolres de tipo double
    \param Tipo de dato
 */
class Expresion{
public:
    Expresion();
    Expresion(char * cadena);

    bool Validar(char * cadena);

private:
    char * expresionNormal;

};

#endif // PILA_HPP_INCLUDED


#endif // EXPRESION_HPP_INCLUDED
