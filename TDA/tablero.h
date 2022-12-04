#ifndef __TABLERO_H__
#define __TABLERO_H__
#include <string>
#include "lista.h"
#include "celula.h"
#include "juego.h"

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

        int getTamanioX();

        int getTamanioY();

        int getTamanioZ();
        
        bool inRange(int n, int m, int l);

        void cargarTableroAutomatico(Opciones opciones);

        void cargarTableroManual(Opciones opciones);

        void actualizarTablero();
};

template <class T> Tablero<T>::cargarTableroAutomatico(Opciones opciones){
    int x, y, z;
    Celula* aux = new Celula();
    for(int i = 0; i < opciones->getCelulasIniciales(); i++){
        x = rand() % opciones->getDimension(0);
        y = rand() % opciones->getDimension(1);
        z = rand() % opciones->getDimension(2);
        aux->setRandCell();
        this->getTData(x, y, z)->setData(*aux);
    }
    delete aux;
}

void solicitarEntero(int* resp, int max){
    do{
        cin >> *resp;
        if(*resp < 0 || *resp > max){
            cout << endl << "Ingrese un numero valido: ";
        }
    } while (*resp < 0 || *resp > max);
}

template <class T> Tablero<T>::cargarTableroManual(Opciones opciones){
    int x, y, z;
    Celula* aux = new Celula();
    for(int i = 0; i < opciones->getCelulasIniciales(); i++){
        aux->setRandCell();
        cout << "Ingrese la coordenada x de la celula " << i << ": ";
        solicitarEntero(&x, opciones->getDimension(0));
        cout << "Ingrese la coordenada y de la celula " << i << ": ";
        solicitarEntero(&y, opciones->getDimension(1));
        cout << "Ingrese la coordenada z de la celula " << i << ": ";
        solicitarEntero(&z, opciones->getDimension(2));
        this->getTData(x, y, z)->setData(*aux);
    }
    delete aux;
}

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
    cubo->resetIter();
    int a = this->y, b = this->z;
    for (int i = 0; i < a; i++) {
        cubo->getLData(i)->resetIter();
        for (int j = 0; j < b; j++) {
            cubo->getLData(i)->getLData(j)->resetIter();
            delete cubo->getLData(i)->getLData(j);
        }
        delete cubo->getLData(i);
    }
    this->x = 0, this->y = 0, this->z = 0;
    delete cubo;
}

template <class T> int Tablero<T>::getTamanioX() {
    return this->x;
}

template <class T> int Tablero<T>::getTamanioY() {
    return this->y;
}

template <class T> int Tablero<T>::getTamanioZ() {
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

template <class T> void Tablero<T>::cargarTableroAutomatico(Opciones opciones) {
    int size[3];
    int cantidad = opciones->getCantidadCelulas();
    
    for(int i = 0; i < 3; i ++){
        size[i] = opciones->getDimension(i);
    }
    for(int i = 0; i < opciones->getCantidadCelulas(); i++){
        do{
            int x = rand() % size[0];
            int y = rand() % size[1];
            int z = rand() % size[2];
            if(this->getTData(x, y, z)->getEstado() != "VIVA"){
                this->setTData(x, y, z, aux);
            }
        }
    }
}

template <class T> int Tablero<T>::obtenerVecinas(int x, int y, int z) {
    int vecinas = 0;
    for(int i = x-1; i <= x+1; i++) {
        for(int j = y-1; j <= y+1; j++) {
            for(int k = z-1; k <= z+1; k++) {
                if(this->inRange(i, j, k)){
                    vecinas = (this->getTData(i, j, k)->getEstado() == "VIVA")? vecinas + 1 : vecinas;
                }
            }
        }
    }
    return vecinas;
}

template <class T> Celula Tablero<T>::nuevoEstadoCelula(int i, int j, int k, int vecinas){
    Celula celula = this->getTData(i, j, k);
    if(celula->getEstado() == "VIVA"){
        if(vecinas < 2 || vecinas > 3){
            celula->setEstado("MUERTA");
        }
    } else {
        if(vecinas == 3){
            celula->setEstado("VIVA");
        }
    }
    return celula;
}

template <class T> void Tablero<T>::avanzarTurno(Tablero<Celula>* tablero){
    int vecinas;
    Celula aux;
    for(int i = 0; i < tablero->getTamanioX(); i++){
        for(int j = 0; j < tablero->getTamanioY(); j++){
            for(int k = 0; k < tablero->getTamanioZ(); k++){
                vecinas = obtenerVecinas(*tablero, i, j, k);
                aux = nuevoEstadoCelula(*tablero, i, j, k, vecinas);
                tablero->setTData(i, j, k, aux);
            }
        }
    }
}

#endif