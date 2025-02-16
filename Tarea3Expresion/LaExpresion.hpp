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
    /** \brief Constructor por default de la clase Expresion, define la expresi&oacute;n normal, la conversi&oacute;n polaca y estado v&aacute;lido.
     *
     */
    Expresion();
    /** \brief Constructor de la clase Expresion, cuando el usuario ha ingresado una expresi�n
     *
     * \param cadena std::string, La expresi&oacute;n dada por el usuario
     *
     */
    Expresion(std::string cadena);

    /** \brief M&eacute;todo que val&iacute;da si el usuario ha ingresado la expresi&oacute;n matem&aacute;tica correctamente
     *
     * \param cadena std::string, La expresi&oacute;n dada por el usuario
     * \return bool, Devuelve si es val&iacute;da o no
     *
     */
    bool Validar(std::string cadena);

    /** \brief Convierte la expresi&oacute;n matem&aacute;tica a notaci&oacute;n polaca inversa
     *
     * \return std::string, Devuelve la expresi&oacute;n ya convertida a notaci&oacute;n polaca inversa
     *
     */
    std::string conversionPolaca();

    /** \brief Funci&oacute;n que determina que operador se acumula o se desacumula dentro de la pila
            dependiendo de su prioridad dentro de los operadores
     *
     * \param simbolo char, se ingresa el operador que se esta leyendo en la cadena
     * \return int, devuelve el n�mero asignado del operador por su prioridad
     *
     */
    int Prioridad(char simbolo);
    /** \brief Funci&oacute;n para imprimir tanto la expresi&oacute;n infija como la conversi&oacute;n polaca y si es v&aacute;lida o no.
     *
     */
    void imprimir() const;
    /** \brief Funci&oacute;n para evaluar la conversi&oacute;n polaca.
     *
     * \return pila, regresa el top de la pila donde se almacena el resultado de la evaluaci&oacute;n.
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
