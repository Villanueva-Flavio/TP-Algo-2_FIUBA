#include "columnasFilas.h"
#include "EasyBMP.h"
#include <sstream>
using namespace std;
void columnasFilasImagen(int columnas,int filas, BMP imagen,int numroCapa){
	int fila = 1;
	while (fila < filas){
		for (int columna = 0;columna < columnas ; columna ++){
			imagen(columna,fila)->Red = 50;
		}
		fila += 2;
	}
	fila = 0;
	while (fila < filas){
		for (int columna = 0;columna < columnas ; columna ++){
			imagen(columna,fila)->Red = 50;
			columna += 1;
		}
		fila += 1;
	}
	int nombreImagen = numroCapa;
	stringstream stringTemporal;
	stringTemporal<<(nombreImagen);
	std::string str = stringTemporal.str();
	const char* capa = str.c_str();
	imagen.WriteToFile(capa);
}




