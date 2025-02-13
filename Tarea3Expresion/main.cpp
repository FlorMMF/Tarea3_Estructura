#include <iostream>
#include <cstring>
#include "LaExpresion.hpp"
#include "LaPila.hpp"

using namespace std;

int main()
{
    try{

        string elemento;
        elemento = "2*4444";
        Expresion ejemplo(elemento);


        cout << endl << endl;


    }catch(const char *mensaje){
        cerr << mensaje;
    }




    return 0;
}

