#include <iostream>
#include <cstring>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

using namespace std;

int main()
{
    try{

        char *elemento = new char [100];
        elemento = "2*{3/1+2}/6";
        Expresion ejemplo(elemento);

        cout << endl;
        cout << endl << endl;


    }catch(const char *mensaje){
        cerr << mensaje;
    }




    return 0;
}

