#include <iostream>
#include <cstring>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

using namespace std;
/**

 * \file main.cpp

 * Este archivo contiene las pruebas de la clase Expresion
 * Se ingresa una expresion matem&aacute;tica y la clase la convierte a notacion polaca y la resuelve

 * \author Flor Machado y Elias Peregrina

 * \date 15/02/2025

 */
 char caracteres[23] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '(', ')', '[', ']', '{', '}','+', '-','*', '/','^'};
int main()
{
    try{

        string elemento;

            cout << "Programa que resuelve una expresi\242n por medio de la Polaca Inversa" << endl;
            cout << "Ingrese la expresi\242n matem\240tica que desea resolver" << endl;

            elemento = TextoPermitido(caracteres,23);
            //elemento = "2/1";
            Expresion ejemplo(elemento);
            cout << endl;
            ejemplo.imprimir();
            cout << "Resultado de la evaluaci\242n: " << ejemplo.Evaluar() << endl;

    }catch(const char *mensaje){
        cerr << mensaje;
    }




    return 0;
}

