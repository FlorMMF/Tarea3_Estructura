#include <iostream>
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
#include <sstream>
#include <limits>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

using namespace std;

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
    std::string salida;
    std::string numero;

    for (unsigned i = 0; i < expresionNormal.size(); ++i){
        char c = expresionNormal[i];

        if (isdigit(c) || c == '.'){
            numero += c;
        } else{
            if (!numero.empty()) {
                salida += numero + ' ';
                numero.clear();
            }
            if (c == '(' || c == '{' || c == '['){
                PilaSimbolos.Apilar(c);
            } else if (c == ')'){
                while (!PilaSimbolos.EstaVacia() && PilaSimbolos.ObtenerTOPE() != '('){
                    salida += PilaSimbolos.ObtenerTOPE();
                    salida += ' ';
                    PilaSimbolos.Desapilar();
                }
                PilaSimbolos.Desapilar();
            } else if (c == '}'){
                while (!PilaSimbolos.EstaVacia() && PilaSimbolos.ObtenerTOPE() != '{'){
                    salida += PilaSimbolos.ObtenerTOPE();
                    salida += ' ';
                    PilaSimbolos.Desapilar();
                }
                PilaSimbolos.Desapilar();
            } else if (c == ']'){
                while (!PilaSimbolos.EstaVacia() && PilaSimbolos.ObtenerTOPE() != '['){
                    salida += PilaSimbolos.ObtenerTOPE();
                    salida += ' ';
                    PilaSimbolos.Desapilar();
                }
                PilaSimbolos.Desapilar();
            } else{
                while (!PilaSimbolos.EstaVacia() && Prioridad(c) <= Prioridad(PilaSimbolos.ObtenerTOPE())){
                    salida += PilaSimbolos.ObtenerTOPE();
                    salida += ' ';
                    PilaSimbolos.Desapilar();
                }
                PilaSimbolos.Apilar(c);
            }
        }
    }

    if (!numero.empty()){
        salida += numero + ' ';
    }
    while (!PilaSimbolos.EstaVacia()){
        salida += PilaSimbolos.ObtenerTOPE();
        salida += ' ';
        PilaSimbolos.Desapilar();
    }
    return salida;

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
    std::cout << "Expresi\242n no fija: " << expresionNormal << std::endl;
    std::cout << "Expresi\242n polaca: " << expresionPolaca << std::endl;
    std::cout << "Es v\240lida: " << (Valida ? "Ye" : "Nah") << std::endl;
}

double Expresion::Evaluar(){
    Pila<double> pila;
    std::string digito;
    std::istringstream iss(expresionPolaca);

    while (iss >> digito) {
        if (isdigit(digito[0]) || digito[0] == '.'){
            pila.Apilar(stod(digito));
        } else {
            double operando2 = pila.ObtenerTOPE();
            pila.Desapilar();
            double operando1 = pila.ObtenerTOPE();
            pila.Desapilar();

            switch (digito[0]) {
                case '+': pila.Apilar(operando1 + operando2); break;
                case '-': pila.Apilar(operando1 - operando2); break;
                case '*': pila.Apilar(operando1 * operando2); break;
                case '/': pila.Apilar(operando1 / operando2); break;
                case '^': pila.Apilar(pow(operando1, operando2)); break;
            }
        }
    }

    return pila.ObtenerTOPE();
}

std::string TextoPermitido(const char caracteres[], unsigned int longitudCaracteres)
{
    std::string inicial, text;
    getline(std::cin, inicial);

    for(char c : inicial) {
        if(c != ' ') {
            text += c;
        }
    }

    while (true)
    {
        bool textoValido = true;


        for (char c : text)
        {
            bool charValido = false;

            // Check if current character is in the allowed characters array
            for (unsigned int i = 0; i < longitudCaracteres; i++)
            {
                if (caracteres[i] == c)
                {
                    charValido = true;
                    break;
                }
            }


            if (!charValido)
            {
                textoValido = false;
                break;
            }
        }

        if (!textoValido)
        {
            std::cout << "\nIngresa de nuevo tu respuesta\n - ";
            getline(std::cin, text);
        }
        else
        {
            break;
        }
    }
    return text;
}

