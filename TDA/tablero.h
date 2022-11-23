#ifndef __TABLERO_H__
#define __TABLERO_H__
#include <string>
#include "lista.h"
#include "celula.h"

template <class T> class Tablero {
    private:
        Lista<T>* filas;
        Lista<T>* columnas;
        Lista<T>* capas;   
        Celula<T>* celula; 
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

    this->filas->add(this->columnas);
    this->filas->columnas->add(this->capas);
    this->filas->columnas->capas->add(this->celula);

    for(int i = 0; i < n; i++){
        this->filas.add(columnas);
        for(int j = 0; j < m; j++){
            this->filas->columnas->add(capas);
            for(int k = 0; k < l; k++){
                this->filas->columnas->capas->add(celula);
            }
        }
    }
}

template <class T> Tablero<T>::~Tablero(){
    for(unsigned int n = 0; n < this->filas->getSize(); n++){
        for(unsigned int m = 0; m < this->filas->columnas->getSize(); m++){
            for(unsigned int l = 0; l < this->filas->columnas->capas->getSize(); l++){
                this->filas->columnas->capas->~Celula();
            }
            this->filas->columnas->~Lista();
        }
        this->filas->~Lista();
    }
}
template <class T> void Tablero<T>::setData(int n, int m, int l, T data){
    setCoordenada(n, m, l);
    this->filas->columnas->capas->celula->setData(data);
}

template <class T> T Tablero<T>::getData(int n, int m, int l){
    setCoordenada(n, m, l);
    return this->filas->columnas->capas->celula->getData();
}

template <class T> void Tablero<T>::setCoordenada(int n, int m, int l){
    
    Lista<T>* celda = *this->filas;
    celda->irANodo(n);
    celda = *this->columnas;
    celda->irANodo(m);
    celda = *this->capas;
    celda->irANodo(l);

}

#endif