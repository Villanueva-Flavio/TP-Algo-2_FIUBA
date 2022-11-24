#ifndef __TABLERO_H__
#define __TABLERO_H__
#include <string>
#include "lista.h"
#include "celula.h"

template <class T> class Tablero {
    private:
        Lista<Lista<Lista<Celula<T>*>*>*>* cubo;
        void setCoordenada(int n, int m, int l);
        
    public:

        // Constructor de tablero vacio de nxmxl celdas
        Tablero(int n, int m, int l);

        // Destructor que elimina todo el tablero
        ~Tablero();

        // Recibe un dato y lo carga en la celda especificada
        void setData(int n, int m, int l, T data);

        // Obtiene el dato de la celda especificada
        T getData(int n, int m, int l);

};

template <class T> Tablero<T>::Tablero(int n, int m, int l){
    this->cubo = new Lista<Lista<Lista<Celula<T>*>*>*>(n);
    for(int i = 0; i < n; i++){
        Lista<Lista<Celula<T>*>*>* cuadrado = new Lista<Lista<Celula<T>*>*>(m);
        this->cubo->add(cuadrado);
        for(int j = 0; j < m; j++){
            Lista<Celula<T>*>* linea = new Lista<Celula<T>*>(l);
            cuadrado->add(linea);
            for(int k = 0; k < l; k++){
                Celula<T>* celula = new Celula<T>();
                linea->add(celula);
            }
        }
    }
}

template <class T> Tablero<T>::~Tablero(){
    for(unsigned int n = 0; n < this->cubo->getSize(); n++){
        for(unsigned int m = 0; m < this->cubo->getData(m)->getSize ; m++){
            for(unsigned int l = 0; l < this->cubo->getData(m)->getData(l)->getSize; l++){
                delete this->cubo->getData(n)->getData(m)->getData(l);
            }
            delete this->cubo->getData(n)->getData(m);
        }
        delete this->cubo->getData(n);
    }
    delete this->cubo;
}

template <class T> void Tablero<T>::setData(int n, int m, int l, T data){
    setCoordenada(n, m, l);
    this->cubo->getData(n)->getData(m)->getData(l)->setData(data);
}

template <class T> T Tablero<T>::getData(int n, int m, int l){
    setCoordenada(n, m, l);
    return this->cubo->getData(n)->getData(m)->getData(l);
}

template <class T> void Tablero<T>::setCoordenada(int n, int m, int l){
    this->cubo->irANodo(n);
    this->cubo->Lista<T>::getData(m)->irANodo(m);
    this->cubo->Lista<T>::getData(m)->Lista<T>::getData(m)->irANodo(l);
}

#endif