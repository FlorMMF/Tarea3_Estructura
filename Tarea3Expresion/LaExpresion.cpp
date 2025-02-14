#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

//******************************************

Expresion::Expresion(): expresionNormal(""), expresionPolaca(""), Valida(false){
}

Expresion::Expresion(std::string cadena){
    if(Validar(cadena)){
        expresionNormal = cadena;
        expresionPolaca = conversionPolaca();
        Valida=true;
    }else throw "No se ha ingresado la cadena correctamente";

}

bool Expresion::Validar(std::string cadena){
    Pila<char> PilaApertura;

    for(unsigned i = 0; i < cadena.size(); ++i) {

        if((cadena[i] == '(') || (cadena[i] == '[') || (cadena[i] == '{')) {
            PilaApertura.Apilar(cadena[i]);
        }


        if((cadena[i] == ')') || (cadena[i] == ']') || (cadena[i] == '}')) {
            if(PilaApertura.EstaVacia()) return false;

            if((cadena[i] == ')' && PilaApertura.ObtenerTOPE() == '(') ||
               (cadena[i] == ']' && PilaApertura.ObtenerTOPE() == '[') ||
               (cadena[i] == '}' && PilaApertura.ObtenerTOPE() == '{')) {
                PilaApertura.Desapilar();
            } else {
                return false;
            }
        }


        if(((cadena[i] == '+')||(cadena[i] == '-')||(cadena[i] == '*')||(cadena[i] == '/')||(cadena[i] == '^'))) {
            if(i > 0 && ((cadena[i-1] == '(') || (cadena[i-1] == '{') || (cadena[i-1] == '['))) return false;
            if(i < cadena.size()-1 && ((cadena[i+1] == ')') || (cadena[i+1] == '}') || (cadena[i+1] == ']'))) return false;
        }


        if(i > 0 && isdigit(cadena[i-1])) {
            if(cadena[i] == '(' || cadena[i] == '{' || cadena[i] == '[') return false;
        }
        if(i < cadena.size()-1 && isdigit(cadena[i+1])) {
            if(cadena[i] == ')' || cadena[i] == '}' || cadena[i] == ']') return false;
        }
    }


    return PilaApertura.EstaVacia();
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

    while (!PilaSimbolos.EstaVacia()){
        expresionPolaca += PilaSimbolos.ObtenerTOPE();
        PilaSimbolos.Desapilar();
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

void Expresion::imprimir() const{
    std::cout << "Expresion no fija: " << expresionNormal << std::endl;
    std::cout << "Expresion polaca: " << expresionPolaca << std::endl;
    std::cout << "Es válida: " << (Valida ? "Ye" : "Nah") << std::endl;
}

double Expresion::Evaluar(){
    Pila<double> pila;
    for (char c : expresionPolaca){
        if (isdigit(c)){
            pila.Apilar(c - '0');
        } else {
            double operando2 = pila.ObtenerTOPE();
            pila.Desapilar();
            double operando1 = pila.ObtenerTOPE();
            pila.Desapilar();
            switch (c){
                case '+': pila.Apilar(operando1 + operando2); break;
                case '-': pila.Apilar(operando1 - operando2); break;
                case '*': pila.Apilar(operando1 * operando2); break;
                case '/': pila.Apilar(operando1 / operando2); break;
                case '^': pila.Apilar(pow(operando1,  operando2)); break;
            }
        }
    }
    return pila.ObtenerTOPE();
}
