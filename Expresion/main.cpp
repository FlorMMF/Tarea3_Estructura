#include <iostream>
#include <cstring>
#include "Expresion.hpp"

using namespace std;

int main()
{
    try{
        Pila PilaApertura;
        char *elemento = new char [100];
        elemento = "{2+1+2}";

        for(int i = 0; i < strlen(elemento) ; ++i){
            if((elemento[i] == '(') || (elemento[i] == '[') || (elemento[i] == '{')){
                PilaApertura.Apilar(elemento[i]);
            }

            if((elemento[i] == ')') || (elemento[i] == ']') || (elemento[i] == '}')){
                if(PilaApertura.EstaVacia() == true){
                    cout << "Se ha ingresado incorrectamente los operadores";
                       break;
                }
                if((elemento[i] == ')' && PilaApertura.ObtenerTOPE() == '(') || (elemento[i] == ']'&& PilaApertura.ObtenerTOPE() == '[') || (elemento[i] == '}' && PilaApertura.ObtenerTOPE() == '{')){

                    PilaApertura.Desapilar();

                }else {
                    cout << "Se ha ingresado incorrectamente los operadores";
                    break;
                }
            }

        }

        PilaApertura.imprimir();
        cout << endl;
        cout << endl << endl;


    }catch(const char *mensaje){
        cerr << mensaje;
    }




    return 0;
}

