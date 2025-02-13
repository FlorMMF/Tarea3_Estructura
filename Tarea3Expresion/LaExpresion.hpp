#ifndef LAEXPRESION_HPP_INCLUDED
#define LAEXPRESION_HPP_INCLUDED

/**Clase de tipo lifo, contenedor de vaolres de tipo double
    \param Tipo de dato
 */
class Expresion{
public:
    Expresion();
    Expresion(std::string cadena);

    bool Validar(std::string cadena);
    std::string conversionPolaca();

private:
    std::string expresionNormal;
    std::string expresionPolaca;

};

#endif // LAEXPRESION_HPP_INCLUDED
