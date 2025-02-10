/**< \file Vector.hpp
    Contiene la definicion de una clase que represente vector algebraico
    \author Flor Machado

*/


#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#define MAX_DIM 10

/**< Vector es la clase para el manejo de vectores algebraicos */
class Vector{

    /** \brief Operador de escalar por vector
     *
     * \param escalar Es el escalar por el que se multiplica un vector
     * \param v const El vector a multiplicar
     * \return Vector Resultante de la multiplicacion
     *
     */friend Vector operator* (double escalar, const Vector v);
    friend std::ostream & operator<< (std::ostream &salida, const Vector v);
    friend std::istream & operator >>  (std::istream &entrada, Vector &v);

public:
    /*
    Vector();
    //un constructor con un solo parametro es un operador de conversion, convierte el tipo de paramentro al tipo de la clase
    explicit Vector(int dimension); //nada mas funciona si creas el vector explicitamente, osea no jala si lo escribes de la forma determinada
    Vector(int dimension, double valor);*/
    explicit Vector(int dimension = 1, double valor = 0);
    Vector(const Vector &v);//constructor de copias
    ~Vector();

    /* los metodos estaticos pueden ser solamente accedidos por datos staticos
    los datos estaticos son atributos de clase y no objeto

    todo metodo no estatico de una clase tiene acceso a un puntero de autoreferencia del objeto que le llame */

    Vector & operator=(const Vector &v);

    void Imprimir();
    void Capturar();
    Vector operator+(const Vector v) const;//un metodo constante puede ser aplicado a instancias constantes, se añade const al final
    Vector operator-(const Vector v) const;
    double operator*(const Vector v)const;
    Vector operator*(double escalar)const;
    double Norma() const;

    double operator[](int i)const;
    double & operator [](int i);


private:
    int dim;
    double *componente;
    //metodos de utileria
    void EstablecerDim(int dimension);

};




#endif // VECTOR_HPP_INCLUDED
