#ifndef __TABLERO_H__
#define __TABLERO_H__

#include "lista.h"
#include "celula.h"

template <class T> class Tablero {
    private:
        Lista<T> filas;
    
        setCoordenada(int n, int m, int l);
        irANodo(int x);
        
    public:

        // Constructor de tablero vacio de nxmxl celdas
        Tablero(int n, int m, int l);

        // Destructor que elimina todo el tablero
        ~Tablero();

        // Recibe un dato y lo carga en la celda especificada
        setData(int n, int m, int l, T data);

        // Obtiene el dato de la celda especificada
        getData(int n, int m, int l);

}

template <class T> Tablero<T>::Tablero(int n, int m, int l){

    Lista<T> columnas = Lista<T>();
    Lista<T> capas = Lista<T>();
    Celula<T> celula = Celula<T>();

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
    
    sector = *this->filas;
    sector->irANodo(n);
    sector = *this->columnas;
    sector->irANodo(m);
    sector = *this->capas;
    sector->irANodo(l);

}

template <class T> void Tablero<T>::irANodo(int x){
    if(x > this->getIter()){
        this->resetIter();
    }

    for(int i = this->getIter(); i <= x; i++){
        this->iterar(NEXT);
    }
}

#endif