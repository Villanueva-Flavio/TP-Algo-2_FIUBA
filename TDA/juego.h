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

void Juego::setOpciones(Opciones aux){
    this->opciones = aux;
}

void Juego::cargarTablero(Opciones opciones){
    if (opciones.getAutomatico()){
        this->tablero->cargarTableroAutomatico(opciones);
    } else {
        this->tablero->cargarTableroManual(opciones);
    }
}

void Juego::llenarJuego(){
    Opciones* aux = new Opciones();
    aux->solicitarMetaData();
    this->setOpciones(*aux);
    this->cargarTablero(*aux);
    delete aux;
}

void Juego::iniciarJuego(){
    this->llenarJuego();
}

void Juego::jugar(){
    string opcion;
    while(!this->congelado || opcion != "Next" || opcion != "next" || opcion != "N" || opcion != "n"){
        juego->addTurno();
        this->tablero->actualizarTablero();
        this->stats->actualizarStats(this->tablero, this->getTurno);
        this->stats->imprimirStats(this->getTurno);
        this->congelado = this->stats->estaCongelado();
        if(!this->congelado){
            cout << "El juego se congeló, desea reiniciar? (Reiniciar / Salir)" << endl;
        }
        solicitarDecision(&opcion);
    }
    if(opcion == "Reiniciar" || opcion == "R" || opcion == "r" || opcion = "reiniciar"){
        this->llenarJuego();
        this->jugar();
    } else if(opcion == "Salir" || opcion == "S" || opcion == "s" || opcion = "salir"){
        system("clear");
        cout << "Se cerró el juego en el turno " << this->getTurno() << endl;
        cout << "Gracias por jugar!" << endl;
        cout << "        github.com/Villanueva-Flavio" << endl;    

    }
}

#endif
