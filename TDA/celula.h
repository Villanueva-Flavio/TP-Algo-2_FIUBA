#ifndef __CELULA_H__
#define __CELULA_H__
#include <string>
#include "lista.h"

using namespace std;

template <class T> class Gen{
    private:
        string nombre;
        int carga;
    public:

        // Constructor de Gen
        Gen();

        // Recibe el nombre y la carga de un gen, los carga en el objeto
        void setData(string nombre, int carga);

        // Obtiene el nombre del gen
        string getNombre();

        // Obtiene la carga del gen
        int getCarga();
};

template <class T> class Celula {
    private:
        string estado;
        string mutador;
        Gen genes[3];

    public:

        // Constructor de celula
        Celula();

        // Recibe una celula y la carga en el objeto
        void setData(Celula<T> datos);

        // Recibe el id del gen, el nombre y su carga, y lo carga en el objeto
        void setGen(int gen, string nombre, int carga);

        // Recibe el estado de la celula y lo carga en el objeto
        void setEstado(string estado);

        // Obtiene el nombre del mutador de la celula
        string getMutador();

        // Obtiene el nombre del estado de la celula
        string getEstado();

};

template <class T> Celula<T>::Celula(){
    Gen<T> gen = gen();
    this->estado = NULL;
    this->mutador = NULL;
    for(unsigned int i = 0; i < 3; i ++){this->genes->add(gen);}
}

template <class T> void Celula<T>::setData(Celula<T> datos){
    this->estado = datos.estado;
    this->mutador = datos.mutador;
    for(unsigned int i = 0; i < 3; i ++){
        this->genes->setData(datos->genes->getNombre(), datos->genes->getCarga());
        this->genes->iterar(NEXT);
        datos->genes->iterar(NEXT);
    }
}

template <class T> void Celula<T>::setGen(int gen, string nombre, int carga){
    this->genes->irANodo(gen);
    this->genes->setData(nombre, carga);
}

template <class T> void Celula<T>::setEstado(string estado){
    this->estado = estado;
}

template <class T> string Celula<T>::getMutador(){
    return this->mutador;
}

template <class T> string Celula<T>::getEstado(){
    return this->estado;
}


/////////////////////////////////////   GEN METHODS   ///////////////////////////////////////

template <class T> Gen<T>::Gen(){
    this->nombre = NULL;
    this->carga = NULL;
}

template <class T> void Gen<T>::setData(string nombre, int carga){
    this->nombre = nombre;
    this->carga = carga;
}

template <class T> string Gen<T>::getNombre(){
    return this->nombre;
}

template <class T> int Gen<T>::getCarga(){
    return this->carga;
}

#endif