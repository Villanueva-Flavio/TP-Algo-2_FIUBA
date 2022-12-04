#include "EasyBMP.h"
#include <sstream>
#include "CelulasMuertasImagen.h"
using namespace std;
void colocarCelMuertasImg(int fila, int columna , int capa){
	BMP imagen;
	int nombreImagen = capa;
	stringstream stringTemporal;
	stringTemporal<<(nombreImagen);
	std::string str = stringTemporal.str();
	const char* nrocapa = str.c_str();
	imagen.ReadFromFile(nrocapa);
	imagen(columna,fila)->Red = 0;
	imagen(columna,fila)->Green = 0;
	imagen(columna,fila)->Blue = 0;
	imagen(columna,fila)->Alpha = 292;
	imagen.WriteToFile(nrocapa);
}




