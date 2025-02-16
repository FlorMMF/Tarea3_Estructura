#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

//******************************************
/**

 * \file LaExpresion.cpp

 * Este archivo contiene funciones y constructores de la clase Expresion
 * Se desarrollan los métodos declarados en el archivo LaExpresion.hpp

 * \author Flor Machado y Elias Peregrina

 * \date 15/02/2025

 */

Expresion::Expresion(): expresionNormal(""), expresionPolaca(""), Valida(false){
}

Expresion::Expresion(std::string cadena){
    if(Validar(cadena)){
        expresionNormal = cadena;
        expresionPolaca = conversionPolaca();
        Valida=true;
    }else Valida = false;

}

bool Expresion::Validar(std::string cadena){
    Pila<char> PilaApertura;

    for(unsigned i = 0; i < cadena.size(); ++i) {

        if((cadena[i] == '(') || (cadena[i] == '[') || (cadena[i] == '{')) {
            PilaApertura.Apilar(cadena[i]);
        }

        if( (cadena [i+1] == '0') &&  (cadena[i] == '/') ){
            return false;
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


    Pila<char> PilaSimbolos;
    int j = 0;
    int expPolacaLongitud;
    for(unsigned i = 0; i < expresionNormal.size() ; ++i){
        if((i > 0) && (isdigit(expresionNormal[i]) || (expresionNormal[i] == '.' )) &&
           (isdigit(expresionNormal[i-1]) || (expresionNormal[i-1] == '.') ) ){
           expresionPolaca += expresionNormal[i];
        }else if(isdigit(expresionNormal[i])){
            if(i > 0 && !isdigit(expresionNormal[i-1]) && expresionNormal[i-1] != '.') {
                expresionPolaca += ',';  // Add comma before starting new number
            }
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
       }else if(Prioridad(expresionNormal[i]) <= Prioridad(PilaSimbolos.ObtenerTOPE())){
            while(!PilaSimbolos.EstaVacia() &&
                  Prioridad(expresionNormal[i]) <= Prioridad(PilaSimbolos.ObtenerTOPE())) {
                expresionPolaca += PilaSimbolos.ObtenerTOPE();
                expresionPolaca += ',';
                PilaSimbolos.Desapilar();
            }
            PilaSimbolos.Apilar(expresionNormal[i]);
        }else{
            PilaSimbolos.Apilar(expresionNormal[i]);
       }
        while(expresionPolaca.back() == ','){
             expPolacaLongitud = expresionPolaca.size();
            if(!isdigit(expresionPolaca[expPolacaLongitud-2])){
                expresionPolaca.pop_back();
            }
        }

    }

    while (!PilaSimbolos.EstaVacia()){
        expresionPolaca += PilaSimbolos.ObtenerTOPE();
        PilaSimbolos.Desapilar();
    }

    for(unsigned i = 0; i < expresionPolaca.size() ; ++i){
        if(expresionPolaca[i] == ',' || expresionPolaca[i] == '(' || expresionPolaca[i] == '{' || expresionPolaca[i] == '[' ){
            if(!isdigit(expresionPolaca[i-1])){

                expresionPolaca.erase(i,1);
            }
        }
    }

     //
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
