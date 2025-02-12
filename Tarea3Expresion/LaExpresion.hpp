#ifndef LAEXPRESION_HPP_INCLUDED
#define LAEXPRESION_HPP_INCLUDED

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

#endif // LAEXPRESION_HPP_INCLUDED
