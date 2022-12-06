#include "./TDA/tablero.h"
#include "./TDA/celula.h"
#include "./load/loadgame.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char** argv) {
    stringstream argument;
    if(argc > 1){
        argument << argv[1];
    }
    srand((unsigned)time(NULL));
    Opciones* opciones = new Opciones();
    opciones->solicitarMetadata(param);
    Juego* juego = new Juego(*opciones);
    delete opciones;
    juego->cargarTablero();
    juego->jugar();
    delete juego;
    return 0;
}