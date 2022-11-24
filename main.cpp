#include "./TDA/tablero.h"
#include "./TDA/celula.h"
#include <iostream>
// TDA Nodo ✓
// TDA Lista ✓
// TDA Tablero ✓
// TDA Celula ✓
// Carga del juego
// Procesamiento del juego
// Bitmaps
// Opcionales (Archivos)

int main(){
    //crear tablero 10x10x10
    Tablero<Celula<int>*>* tablero = new Tablero<Celula<int>*>(10, 10, 10);
    cout << "CREADO" << endl;
    delete tablero;
    return 0;
}