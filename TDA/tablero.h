#ifndef __TABLERO_H__
#define __TABLERO_H__
#include <string>
#include "lista.h"
#include "celula.h"

template <class T> class Tablero {
    private:
        Lista<Lista<Lista<T>*>*>* cubo;
        int x, y, z;
        void setCoordenada(int n, int m, int l);
        
    public:

        // Constructor de tablero vacio de nxmxl celdas
        Tablero(int n, int m, int l);

        // Destructor que elimina todo el tablero
        ~Tablero();

        // Recibe un dato y lo carga en la celda especificada
        void setTData(int n, int m, int l, T data);

        // Obtiene el dato de la celda especificada
        T getTData(int n, int m, int l);

        unsigned int getTamanioX();

        unsigned int getTamanioY();

        unsigned int getTamanioZ();
        
        bool inRange(int n, int m, int l);
};



template <class T> Tablero<T>::Tablero(int n, int m, int l) {
    this->x = n, this->y = m, this->z = l;
    cubo = new Lista<Lista<Lista<T>*>*>();
    for (int i = 0; i < n; i++) {
        Lista<Lista<T>*>* plano = new Lista<Lista<T>*>();
        for (int j = 0; j < m; j++) {
            Lista<T>* fila = new Lista<T>();
            for (int k = 0; k < l; k++) {
                fila->add(T());
            }
            plano->add(fila);
        }
        cubo->add(plano);
    }
}

//DESTRUCTOR DE TABLERO

template <class T> Tablero<T>::~Tablero() {
    for (int i = 0; i < cubo->getSize(); i++) {
        Lista<Lista<T>*>* plano = cubo->getLData(i);
        for (int j = 0; j < plano->getSize(); j++) {
            Lista<T>* fila = plano->getLData(j);
            //delete fila;
            this->z --;
        }
        //delete plano;
        this->y --;
    }
    delete cubo;
    this->x --;
}

template <class T> unsigned int Tablero<T>::getTamanioX() {
    return this->x;
}

template <class T> unsigned int Tablero<T>::getTamanioY() {
    return this->y;
}

template <class T> unsigned int Tablero<T>::getTamanioZ() {
    return this->z;
}

template <class T> void Tablero<T>::setTData(int n, int m, int l, T data){
    setCoordenada(n, m, l);
    this->cubo->getLData(n)->getLData(m)->getLData(l)->setNData(data);
}

template <class T> T Tablero<T>::getTData(int n, int m, int l){
    setCoordenada(n, m, l);
    return this->cubo->getLData(n)->getLData(m)->getLData(l);
}

template <class T> void Tablero<T>::setCoordenada(int n, int m, int l){
    this->cubo->irANodo(n);
    this->cubo->Lista<T>::getLData(m)->irANodo(m);
    this->cubo->Lista<T>::getLData(m)->Lista<T>::getLData(m)->irANodo(l);
}

template <class T> bool Tablero<T>::inRange(int n, int m, int l) {
    return (n >= 0 && n < this->x && m >= 0 && m < this->y && l >= 0 && l < this->z);
}

#endif