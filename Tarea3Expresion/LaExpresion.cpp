#include <iostream>
#include <cctype>
#include <cstring>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

//******************************************



Expresion::Expresion(std::string cadena){
    if(Validar(cadena)){
        expresionNormal = cadena;
        expresionPolaca = conversionPolaca();
    }else throw "No se ha ingresado la cadena correctamente";

}

bool Expresion::Validar(std::string cadena){
        Pila<char> PilaApertura;

        for(unsigned i = 0; i < cadena.size() ; ++i){
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

std::string Expresion::conversionPolaca(){
//    Pila<std::string> PilaSimbolos;
//    std::string cadenaNum;
//    std::string cadena = expresionNormal;
//    for(unsigned i = 0; i < cadena.size() ; ++i){
//        if( isdigit(cadena[i]) ){
//            cadenaNum += cadena[i];
//        }else{
//            PilaSimbolos.Apilar(cadenaNum);
//            std::cout << cadenaNum << ", ";
//            cadenaNum.clear();
//        }
//    }
//    PilaSimbolos.imprimir();

}
