#include <iostream>
#include <cstring>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

using namespace std;

int main()
{
    try{

        string elemento;
        elemento = "2.5*4+4";
        Expresion ejemplo(elemento);

        ejemplo.imprimir();
        cout << "Resultado de la evaluación: " << ejemplo.Evaluar() << endl;

    }catch(const char *mensaje){
        cerr << mensaje;
    }




    return 0;
}

