#ifndef __CELULA_H__
#define __CELULA_H__
#include <string>
#include "lista.h"
template <class T> class Genes{
    private:
        string nombre;
        int carga;
    public:
        Genes(string nombre, int carga);
        string getNombre();
        int getCarga();
};

template <class T> class Celula {
    private:
        string nombre;
        string estado;
        Genes<T> genes[3];

    public:
        Celula();
        void setData(Celula<T> datos);
        setNombre(string nombre);
        setGenes(Genes<T> genes[3]);
        setEstado(string estado);
        string getNombre();
        string getEstado();
        getCelula();

};

template <class T> Celula<T>::Celula() {
    this->nombre = NULL;
    this->estado = NULL;
    this->genes[0] = Genes<T>(NULL, NULL);
    this->genes[1] = Genes<T>(NULL, NULL);
    this->genes[2] = Genes<T>(NULL, NULL);
}

template <class T> void Celula<T>::setData(Celula<T> datos) {
    this->nombre = datos.nombre;
    this->estado = datos.estado;
    this->genes[0] = datos.genes[0];
    this->genes[1] = datos.genes[1];
    this->genes[2] = datos.genes[2];
}


#endif