#include <iostream>
#include <cctype>
#include <cstring>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

//******************************************



Expresion::Expresion(char * cadena){
    if(Validar(cadena)){
        expresionNormal = cadena;
    }else throw "No se ha ingresado la cadena correctamente";

}

bool Expresion::Validar(char * cadena){
        Pila<char> PilaApertura;

        for(int i = 0; i < strlen(cadena) ; ++i){
            if((cadena[i] == '(') || (cadena[i] == '[') || (cadena[i] == '{')){
                PilaApertura.Apilar(cadena[i]);
            }

            if((cadena[i] == ')') || (cadena[i] == ']') || (cadena[i] == '}')){
                if(PilaApertura.EstaVacia() == true) return false;

                if((cadena[i] == ')' && PilaApertura.ObtenerTOPE() == '(') || (cadena[i] == ']'&& PilaApertura.ObtenerTOPE() == '[') || (cadena[i] == '}' && PilaApertura.ObtenerTOPE() == '{')){

                    PilaApertura.Desapilar();

                }else {
                    return false;
                }
            }

            if(((cadena[i] == '+')||(cadena[i] == '-')||(cadena[i] == '*')||(cadena[i] == '/')||(cadena[i] == '^'))&&
               (((cadena[i-1] == '(')||(cadena[i+1] == ')'))||(cadena[i-1] == '{')||(cadena[i+1] == '}') || (cadena[i-1] == '[')||(cadena[i+1] == ']')) ){
                return false;
            }

            if ((isdigit(cadena[i-1]) && cadena[i] == '(') || (isdigit(cadena[i-1]) && cadena[i] == '{') || (isdigit(cadena[i-1]) && cadena[i] == '[' ) ||
                 (isdigit(cadena[i+1]) && cadena[i] == ')') || (isdigit(cadena[i+1]) && cadena[i] == '}') || (isdigit(cadena[i+1]) && cadena[i] == ']') ) { // Verifica si el carácter es un dígito
                return false;
            }
        }



        PilaApertura.imprimir();
        return true;
}

char * Expresion::conversionPolaca(char * cadena){
    bool out = true;
    while(out){

    }
}
