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
//
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
    Pila<char> PilaSimbolos;
    int j = 0;
    for(unsigned i = 0; i < expresionNormal.size() ; ++i){

       if(isdigit(expresionNormal[i])){
            expresionPolaca += expresionNormal[i];
       }else if(PilaSimbolos.EstaVacia() || (expresionNormal[i] == '(') || (expresionNormal[i] == '{') || (expresionNormal[i] == '[')){
            PilaSimbolos.Apilar(expresionNormal[i]);
      }else if (expresionNormal[i] == ')'){
            j = i - 1;
            while (expresionNormal[j] != '(' ){
                expresionPolaca += PilaSimbolos.ObtenerTOPE();
                PilaSimbolos.Desapilar();
                --j;
            }
       }else if (expresionNormal[i] == '}'){
             j = i - 1;
            while (expresionNormal[j] != '{' ){
                expresionPolaca += PilaSimbolos.ObtenerTOPE();
                PilaSimbolos.Desapilar();
                --j;
            }
       }else if (expresionNormal[i] == ']'){
             j = i - 1;
            while (expresionNormal[j] != '[' ){
                expresionPolaca += PilaSimbolos.ObtenerTOPE();
                PilaSimbolos.Desapilar();
                --j;
            }
       }else if(Prioridad(expresionNormal[i]) < Prioridad(PilaSimbolos.ObtenerTOPE())){
            expresionPolaca += PilaSimbolos.ObtenerTOPE();
            PilaSimbolos.Desapilar();
       }else{
            PilaSimbolos.Apilar(expresionNormal[i]);
       }

    }
    std::cout << expresionPolaca;
    return expresionPolaca;

}

int Expresion::Prioridad(char simbolo){
    switch(simbolo){
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    }
    return 0;
}
