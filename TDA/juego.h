#ifndef __JUEGO_H__
#define __JUEGO_H__
#include "tablero.h"
#include <iostream>
#include <string>

using namespace std;

class Opciones{
    private:
        int parameters[3];
        int dimension[3];
        int celulasIniciales;
        bool automatico;

    public:
        Opciones();
        void setParameters();
        void setDimension();
        void setCelulasIniciales();
        void setAutomatico();
        int getParameters(int i);
        int getDimension(int i);
        int getCelulasIniciales();
        bool getAutomatico();
};

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
};

class Juego{
    private:
        Opciones opciones;
        Tablero<Celula*>* tablero;
        int turno;
        Stats stats;

    public:
        Juego(int size[3], Opciones *aux);
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

};

Opciones::Opciones(){
    for(int i = 0; i < 3; i ++){
        parameters[i] = 0;
        dimension[i] = 0;
    }
    celulasIniciales = 0;
    automatico = false;
}

void Opciones::setAutomatico(){
    string respuesta;
    cout << "Desea que el juego sea automatico? (1 = Si, 0 = No)" << endl;
    cin >> respuesta;
    while (respuesta != "No" && respuesta != "Si"){
        cout << "Por favor ingrese una opcion valida" << endl;
        cin >> respuesta;
    }
    this->automatico = (respuesta == "Si")? true : false;
}

void Opciones::setCelulasIniciales(){
    int max = this->dimension[0] * this->dimension[1] * this->dimension[2];
    cout << "Ingrese la cantidad de celulas iniciales" << endl;
    cin >> this->celulasIniciales;
    while (this->celulasIniciales < 0 || this->celulasIniciales > max){
        cout << "Por favor ingrese una cantidad valida" << endl;
        cin >> this->celulasIniciales;
    }
}

void Opciones::setDimension(){
    int respuesta;
    cout << "Ingrese la dimension del tablero que desea hasta 100 por dimension" << endl;
    for(int i = 0; i < 3; i++){
        cin >> respuesta;
        while(respuesta < 0 || respuesta > 100){
            cout << "Por favor ingrese una dimension valida" << endl;
            cin >> respuesta;
        }
        this->dimension[i] = respuesta;
    }
}

void Opciones::setParameters(){
    int respuesta;
    for(int i = 0; i < 3; i ++){
        cout << "Ingrese el parametro x" << i << " que desea" << endl;
        cin >> respuesta;
        while((respuesta < 1) || (respuesta > 100) || (i == 1 && this->parameters[1] < this->parameters[0]) || (i == 2 && this->parameters[2] < this->parameters[1])){
            cout << "Por favor ingrese un parametro valido" << endl;
            cin >> respuesta;
        }
        this->parameters[i] = respuesta;
    }
}

int Opciones::getParameters(int i){
    return this->parameters[i];
}

int Opciones::getDimension(int i){
    return this->dimension[i];
}

int Opciones::getCelulasIniciales(){
    return this->celulasIniciales;
}

bool Opciones::getAutomatico(){
    return this->automatico;
}

Stats::Stats(){
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

Juego::Juego(int size[3], Opciones *aux){
    this->tablero = new Tablero<Celula*>(size[0], size[1], size[2]);
    this->turno = 0;
    this->opciones = *aux;
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

void Juego::solicitarMetaData(Opciones* aux){
    aux->setDimension();
    aux->setParameters();
    aux->setCelulasIniciales();
    aux->setAutomatico();
}

void Juego::cargarTablero(Opciones opciones){
    if (opciones.getAutomatico()){
        this->tablero->cargarTableroAutomatico(opciones);
    } else {
        this->tablero->cargarTableroManual(opciones);
    }
}

void Juego::llenarJuego(Opciones* aux){
    solicitarMetaData(aux);
    setOpciones(*aux);
    cargarTablero(*aux);
    
}

#endif
