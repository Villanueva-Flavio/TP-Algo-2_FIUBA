#ifndef __STATS_H__
#define __STATS_H__

#include <iostream>
#include "tablero.h"

class Stats{
    private:
        int nacidas;
        int muertas;
        int promedioNacidas;
        int promedioMuertas;
        int nacidasGenerales;
        int muertasGenerales;
        int vivas;

    public:
        Stats();
        void setNacidas(int nacidas);
        void setMuertas(int muertas);
        void setPromedioNacidas(int turno);
        void setPromedioMuertas(int turno);
        void setVivas(int vivas);
        int getNacidas();
        int getMuertas();
        int getPromedioNacidas();
        int getPromedioMuertas();
        int getVivas();
        void setNacidasGenerales();
        void setMuertasGenerales();
        int getNacidasGenerales();
        int getMuertasGenerales();
        void actualizarStats(Tablero<Celula*>* tablero, int turno);
        void imprimirStats(int turno);
        bool estaCongelado();
        void reset();
};

Stats::Stats(){
    this->nacidas = 0;
    this->muertas = 0;
    this->promedioNacidas = 0;
    this->promedioMuertas = 0;
    this->vivas = 0;
}

void Stats::reset(){
    this->nacidas = 0;
    this->muertas = 0;
    this->promedioNacidas = 0;
    this->promedioMuertas = 0;
    this->vivas = 0;
}

void Stats::setNacidas(int nacidas){
    this->nacidas = nacidas;
}

void Stats::setMuertas(int muertas){
    this->muertas = muertas;
}

void Stats::setPromedioNacidas(int turno){
    this->promedioNacidas = (turno != 0)? nacidasGenerales/turno : 0;
}

void Stats::setPromedioMuertas(int turno){
    this->promedioMuertas = (turno != 0)? muertasGenerales/turno : 0;
}

void Stats::setVivas(int vivas){
    this->vivas = vivas;
}

int Stats::getNacidas(){
    return this->nacidas;
}

int Stats::getMuertas(){
    return this->muertas;
}

int Stats::getPromedioNacidas(){
    return this->promedioNacidas;
}

int Stats::getPromedioMuertas(){
    return this->promedioMuertas;
}

int Stats::getVivas(){
    return this->vivas;
}

void Stats::setNacidasGenerales(){
    this->nacidasGenerales = nacidasGenerales + nacidas;
}

void Stats::setMuertasGenerales(){
    this->muertasGenerales = muertasGenerales + muertas;
}

int Stats::getNacidasGenerales(){
    return this->nacidasGenerales;
}

int Stats::getMuertasGenerales(){
    return this->muertasGenerales;
}

void Stats::aplicarStats(int nacidas, int muertas, int vivas){
    this->setNacidas(nacidas);
    this->setMuertas(muertas);
    this->setVivas(vivas);
    this->setNacidasGenerales();
    this->setMuertasGenerales();
    this->setPromedioNacidas();
    this->setPromedioMuertas();
}

void Stats::imprimirStats(int turno){
    cout << "Turno: " << turno << endl;
    cout << "Nacidas: " << this->getNacidas() << endl;
    cout << "Muertas: " << this->getMuertas() << endl;
    cout << "Vivas: " << this->getVivas() << endl;
    cout << "Promedio Nacidas: " << this->getPromedioNacidas() << endl;
    cout << "Promedio Muertas: " << this->getPromedioMuertas() << endl << endl;
}

void Stats::actualizarStats(Tablero<Celula*>* tablero, int turno){
    int nacidas = 0, muertas = 0, vivas = 0;
    for(int i = 0; i < tablero->getSize()[0]; i++){
        for(int j = 0; j < tablero->getSize()[1]; j++){
            for(int k = 0; k < tablero->getSize()[2]; k++){
                switch(tablero->getTData(i, j, k)->getEstado()){
                    case NACIDA:
                        nacidas++;
                        break;
                    case MUERTA:
                        muertas++;
                        break;
                    case VIVA:
                        vivas++;
                        break;
                }
            }
        }
    }
    if(turno > 1){
        this->aplicarStats(nacidas, muertas, vivas);
        this->imprimirStats(turno);
    }
}

bool Stats::estaCongelado(){
    return this->getNacidas() == 0 && this->getMuertas() == 0;
}

#endif