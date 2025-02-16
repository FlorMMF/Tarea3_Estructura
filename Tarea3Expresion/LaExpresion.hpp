#ifndef LAEXPRESION_HPP_INCLUDED
#define LAEXPRESION_HPP_INCLUDED
/**

 * \file LaExpresion.hpp

 * Este archivo contiene la declaración de la clase Expresion

 * \author Flor Machado y Elias Peregrina

 * \date 15/02/2025

 */
/**Clase Expresion, define una expresion matematica

 */
class Expresion{
public:
    Expresion();
    /** \brief Constructor de la clase Expresion, cuando el usuario ha ingresado una expresión
     *
     * \param cadena std::string, La expresión dada por el usuario
     *
     */
    Expresion(std::string cadena);

    /** \brief Método que valída si el usuario ha ingresado la expresión matemática correctamente
     *
     * \param cadena std::string, La expresión dada por el usuario
     * \return bool, Devuelve si es valída o no
     *
     */
    bool Validar(std::string cadena);

    /** \brief Convierte la expresión matemática a notación polaca inversa
     *
     * \return std::string, Devuelve la expresión ya convertida a notación polaca inversa
     *
     */
    std::string conversionPolaca();

    /** \brief Función que determina que operador se acumula o se desacumula dentro de la pila
            dependiendo de su prioridad dentro de los operadores
     *
     * \param simbolo char, se ingresa el operador que se esta leyendo en la cadena
     * \return int, devuelve el número asignado del operador por su prioridad
     *
     */
    int Prioridad(char simbolo);
    void imprimir() const;
    double Evaluar();

private:
    std::string expresionNormal;
    std::string expresionPolaca;
    bool Valida;

};

#endif // LAEXPRESION_HPP_INCLUDED
