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
    
    Tablero<Celula>* tablero = new Tablero<Celula>(10, 10, 10);
    cout << "CREADO" << endl;
    delete tablero;
    cout << "ELIMINADO" << endl;

    return 0;
}