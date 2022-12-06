#ifndef __JUEGO_H__
#define __JUEGO_H__
#include "tablero.h"
#include <iostream>
#include <string>
#include "opciones.h"
#include "stats.h"

using namespace std;

class Juego{
    private:
        Opciones opciones;
        Tablero<Celula*>* tablero;
        int turno;
        Stats stats;
        bool congelado;

    public:
        Juego(Opciones aux);
        ~Juego();
        void llenarJuego(Opciones* aux);
        Stats getStats();
        Opciones getOpciones();
        void setStats(Stats aux);
        void addTurno();
        int getTurno();
        void solicitarMetaData(Opciones* aux);
        void cargarTablero(Opciones opciones);
        void setOpciones(Opciones aux);
        void llenarJuego();
        void jugar();
        Tablero<Celula*>* getTablero();
        int getParam(int i);
};

Juego::Juego(int size[3], Opciones aux){
    this->tablero = new Tablero<Celula*>(size[0], size[1], size[2]);
    this->turno = 0;
    this->opciones = aux;
    this->congelado = false;
}

Juego::~Juego(){
    delete this->tablero;
}

void Juego::setStats(Stats aux){
    this->stats = aux;
}

Stats Juego::getStats(){
    return this->stats;
}

void Juego::addTurno(){
    this->turno++;
}

int Juego::getTurno(){
    return this->turno;
}
    
Opciones Juego::getOpciones(){
    return this->opciones;
}

Tablero<Celula*>* Juego::getTablero(){
    return this->tablero;
}

void Juego::cargarTablero(){
    if (this->getOpciones()->getAutomatico()){
        this->getTablero()->cargarTableroAutomatico(opciones);
    } else {
        this->getTablero()->cargarTableroManual(opciones);
    }
}

void Juego::checkCongelado(string* opcion){
    if(!this->congelado){
        cout << "El juego se congeló, desea reiniciar? (REINICIAR / SALIR)" << endl;
    }
    solicitarDecision(opcion);
}

void Juego::checkReiniciar(string opcion){
    if(opcion == "REINICIAR"){
        this->llenarJuego();
        this->jugar();
    }
}

void Juego::checkSalir(string opcion){
    if(opcion == "SALIR"){
        system("clear");
        cout << "Se cerró el juego en el turno " << this->getTurno() << endl;
        cout << "Gracias por jugar!" << endl;
        cout << "        github.com/Villanueva-Flavio" << endl;    
    }
}

int getParam(int i){
    return this->getOpciones->params[i];
}

void Juego::jugar(){
    string opcion;
    int aux[3] = {this->getParams(0), this->getParams(1), getParams(2)};
    while(!this->congelado || opcion != "NEXT"){
        juego->addTurno();
        this->tablero->actualizarTablero(aux);
        this->stats->actualizarStats(this->tablero, this->getTurno);
        this->stats->imprimirStats(this->getTurno);
        this->congelado = this->stats->estaCongelado();
        checkCongelado(&opcion);
    }
    checkReiniciar(opcion);
    checkSalir(opcion);
}

#endif
