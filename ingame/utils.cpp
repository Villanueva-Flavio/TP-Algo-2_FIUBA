#include "../TDA/juego.h"

unsigned int obtenerVecinas(Tablero<Celula> tablero, int x, int y, int z) {
    unsigned int vecinas = 0;
    for(int i = x-1; i <= x+1; i++) {
        for(int j = y-1; j <= y+1; j++) {
            for(int k = z-1; k <= z+1; k++) {
                if(tablero.inRange(i, j, k)){
                    vecinas = (tablero.getTData(i, j, k).getEstado() == "VIVA")? vecinas + 1 : vecinas;
                }
            }
        }
    }
    return vecinas;
}

Celula nuevoEstadoCelula(Tablero<Celula> aux, unsigned int i, unsigned int j, unsigned int k, unsigned int vecinas){
    Celula celula = aux.getTData(i, j, k);
    if(celula.getEstado() == "VIVA"){
        if(vecinas < 2 || vecinas > 3){
            celula.setEstado("MUERTA");
        }
    } else {
        if(vecinas == 3){
            celula.setEstado("VIVA");
        }
    }
    return celula;
}


void avanzarTurno(Tablero<Celula>* tablero){
    int vecinas;
    Celula aux;

    for(unsigned int i = 0; i < tablero->getTamanioX(); i++){
        for(unsigned int j = 0; j < tablero->getTamanioY(); j++){
            for(unsigned int k = 0; k < tablero->getTamanioZ(); k++){
                vecinas = obtenerVecinas(*tablero, i, j, k);
                aux = nuevoEstadoCelula(*tablero, i, j, k, vecinas);
                tablero->setTData(i, j, k, aux);
            }
        }
    }
}