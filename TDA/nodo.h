#ifndef __NODO_H__
#define __NODO_H__

template <class T> class Nodo{
private:
    T data;
    Nodo<T>* sig;

public:

    // Constructor de nodo:
    // Crea el nodo con el dato del parametro
    Nodo(T data);
    
    // Devuelve el dato guardado en el nodo
    T getData();
    
    // Cambia el dato guardado en el nodo por el del parametro
    void setData(T data);
    
    // Devuelve el nodo siguiente
    Nodo<T>* next();
};

template <class T> Nodo<T>::Nodo(T data){
    this->data = data;
    this->sig = NULL;
}

template <class T> T Nodo<T>::getData(){
    return this->data;
}

template <class T> void Nodo<T>::setData(T data){
    this->data = data;
}

template <class T> Nodo<T>* Nodo<T>::next(){
    return this->sig;
}

#endif