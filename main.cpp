#include "./TDA/tablero.h"
#include "./TDA/celula.h"
#include <iostream>
// TDA Nodo ✓ . Flavio
// TDA Lista ✓ - Flavio
// TDA Tablero ✓ - Flavio
// TDA Celula ✓ - Flavio
// Carga del juego - Feli
// Procesamiento del juego
// Bitmaps - Sote
// Opcionales (Archivos)

int main(){
    //crear tablero de celula con new
    Tablero<Celula>* tablero = new Tablero<Celula>(200,200,200);
    delete tablero;
    return 0;
}