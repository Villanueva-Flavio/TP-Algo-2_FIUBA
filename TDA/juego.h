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
        void llenarJuego();
        Stats getStats(); // Useless?
        Opciones getOpciones();
        void setStats(Stats aux); // Useless?
        void addTurno();
        int getTurno();
        void cargarTablero(Opciones opciones);
        void setOpciones(Opciones aux);
        void jugar();
        Tablero<Celula*>* getTablero();
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

void Juego::llenarJuego(){
    this->getOpciones()->setLimited(this->getOpciones()->getLimited());
    this->setOpciones(this->opciones);
    this->cargarTablero(this->opciones);
    this->stats->reset();
}

void Juego::setOpciones(Opciones aux){
    this->opciones = aux;
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
        this->->cargarTableroAutomatico(opciones);
    } else {
        this->getTablero()->cargarTableroManual(opciones);
    }
}

void Juego::checkCongelado(string opcion){
    if(this->congelado){
        cout << "El juego se congeló, desea reiniciar? (Reiniciar / Salir)" << endl;
    }
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

void Juego::checkMultiple(string opcion, int* turnosRestantes){
    if(opcion == "MULTIPLE"){
        cout << "Ingrese la cantidad de turnos que desea jugar: " << endl;
        cin >> *turnosRestantes;
        while(*turnosRestantes <= 0 || *turnosRestantes > 100){
            cout << "Ingrese una cantidad válida menor a 100: " << endl;
            cin >> *turnosRestantes;
        }
    }
}

void Juego::solicitarDecision(string* opcion, int* turnosRestantes){
    cout << "¿Qué desea hacer? (NEXT / MULTIPLE / REINICIAR / SALIR)" << endl;
    cin >> *opcion;
    while(*opcion != "NEXT" && *opcion != "MULTIPLE" && *opcion != "REINICIAR" && *opcion != "SALIR"){
        cout << "Opción inválida, por favor ingrese una opción válida" << endl;
        cin >> *opcion;
    }
    *turnosRestantes = 1;
}

void imprimirImagen(){
    
}

void Juego::jugar(){
    string opcion;
    int turnosRestantes = 1;
    while(!this->congelado && opcion != "NEXT"){
        turnosRestantes --;
        juego->addTurno();
        this->tablero->actualizarTablero(this->opciones->params);
        this->stats->actualizarStats(this->tablero, this->getTurno);
        this->stats->imprimirStats(this->getTurno);
        this->congelado = this->stats->estaCongelado();
        checkCongelado(opcion);
        if(turnosRestantes <= 0){
            solicitarDecision(&opcion, &turnosRestantes);
            checkMultiple(opcion, &turnosRestantes);
        }
    }
    checkReiniciar(opcion);
    checkSalir(opcion);
}

#endif
