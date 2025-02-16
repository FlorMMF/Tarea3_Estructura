#ifndef LAEXPRESION_HPP_INCLUDED
#define LAEXPRESION_HPP_INCLUDED
/**

 * \file LaExpresion.hpp

 * Este archivo contiene la declaraci�n de la clase Expresion

 * \author Flor Machado y Elias Peregrina

 * \date 15/02/2025

 */
/**Clase Expresion, define una expresion matematica

 */
class Expresion{
public:
    /** \brief Constructor por default de la clase Expresion, define la expresión normal, la conversión polaca y estado válido.
     *
     */
    Expresion();
    /** \brief Constructor de la clase Expresion, cuando el usuario ha ingresado una expresi�n
     *
     * \param cadena std::string, La expresi�n dada por el usuario
     *
     */
    Expresion(std::string cadena);

    /** \brief M�todo que val�da si el usuario ha ingresado la expresi�n matem�tica correctamente
     *
     * \param cadena std::string, La expresi�n dada por el usuario
     * \return bool, Devuelve si es val�da o no
     *
     */
    bool Validar(std::string cadena);

    /** \brief Convierte la expresi�n matem�tica a notaci�n polaca inversa
     *
     * \return std::string, Devuelve la expresi�n ya convertida a notaci�n polaca inversa
     *
     */
    std::string conversionPolaca();

    /** \brief Funci�n que determina que operador se acumula o se desacumula dentro de la pila
            dependiendo de su prioridad dentro de los operadores
     *
     * \param simbolo char, se ingresa el operador que se esta leyendo en la cadena
     * \return int, devuelve el n�mero asignado del operador por su prioridad
     *
     */
    int Prioridad(char simbolo);
    /** \brief Función para imprimir tanto la expresión infija como la conversión polaca y si es válida o no.
     *
     */
    void imprimir() const;
    /** \brief Función para evaluar la conversión polaca.
     *
     * \return pila, regresa el top de la pila donde se almacena el resultado de la evaluación.
     *
     */
    double Evaluar();

private:
    std::string expresionNormal;
    std::string expresionPolaca;
    bool Valida;

};

std::string TextoPermitido(const char caracteres[], unsigned int longitudCaracteres);


#endif // LAEXPRESION_HPP_INCLUDED
