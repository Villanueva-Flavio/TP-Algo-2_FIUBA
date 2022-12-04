#ifndef __CELULA_H__
#define __CELULA_H__
#include <string>
#include "lista.h"

using namespace std;

//ENUM MUTADORES
enum Mutageno{
    NINGUNA,
    PORTAL,
    RADIOACTIVA,
    ENVENENADA,
    PROCREADORA,
    CONTAMINADA
};

enum Estado{
    VIVA,
    MUERTA,
    NACIDA,
};

class Gen{
    private:
        Estado nombre;
        int carga;
    public:

        // Constructor de Gen
        Gen();

        // Recibe el nombre y la carga de un gen, los carga en el objeto
        void setData(string nombre, int carga);

        // Obtiene el nombre del gen
        Estado getNombre();

        // Obtiene la carga del gen
        int getCarga();

        void setMutadorRandom();
};

class Celula {
    private:
        string estado;
        Mutageno mutador;
        Gen genes[3];

    public:

        // Constructor de celula
        Celula();

        // Recibe una celula y la carga en el objeto
        void setData(Celula datos);

        // Recibe el id del gen, el nombre y su carga, y lo carga en el objeto
        void setGen(int gen, string nombre, int carga);

        // Recibe el estado de la celula y lo carga en el objeto
        void setEstado(Estado estado);

        // Obtiene el nombre del mutador de la celula
        Mutador getMutador();

        // Obtiene el nombre del estado de la celula
        Estado getEstado();

};

Celula::Celula(){
    Gen gen = Gen();
    this->estado = MUERTA;
    this->mutador = NINGUNA;
    for(int i = 0; i < 3; i ++){
        this->genes[i] = gen;
    }
}

void Celula::setData(Celula datos){
    this->estado = datos.estado;
    this->mutador = datos.mutador;
    for(int i = 0; i < 3; i ++){
        this->genes[i] = datos.genes[i];
    }
}

void Celula::setGen(int gen, string nombre, int carga){
    this->genes[gen].setData(nombre, carga);
}

void Celula::setEstado(Estado estado){
    this->estado = estado;
}

Mutador Celula::getMutador(){
    return this->mutador;
}

Estado Celula::getEstado(){
    return this->estado;
}

void setRandCell(){
    this->setEstado(VIVA);
    this->setGen(0, "GEN1", rand() % 255);
    this->setGen(1, "GEN2", rand() % 255);
    this->setGen(2, "GEN3", rand() % 255);
    this->setMutadorRandom();
}

void setMutadorRandom(){
    int mutador = rand() % 24;
    switch(mutador){
        case 0:
            this->mutador = PORTAL;
            break;
        case 1:
            this->mutador = RADIOACTIVA;
            break;
        case 2:
            this->mutador = ENVENENADA;
            break;
        case 3:
            this->mutador = PROCREADORA;
            break;
        case 4:
            this->mutador = CONTAMINADA;
            break;
        default:
            this->mutador = NINGUNA;
            break;
    }
}


/////////////////////////////////////   GEN METHODS   ///////////////////////////////////////

Gen::Gen(){
    this->nombre = "";
    this->carga = 0;
}

void Gen::setData(string nombre, int carga){
    this->nombre = nombre;
    this->carga = carga;
}

string Gen::getNombre(){
    return this->nombre;
}

int Gen::getCarga(){
    return this->carga;
}

#endif