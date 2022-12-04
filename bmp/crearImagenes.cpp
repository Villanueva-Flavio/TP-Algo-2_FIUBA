#include "EasyBMP.h"
#include <sstream>
#include "crearImagenes.h"
#include "columnasFilas.h"
void crearImagen(int columnas , int filas, int capas){
	BMP imagen;
	columnas = columnas *2+1;
	filas = filas * 2 ;
	for (int i = 0; i < capas ; i ++){
		imagen.SetSize(columnas,filas);
		imagen.SetBitDepth(24);
		for( int j=0 ; j < imagen.TellHeight() ; j++)
		{
			for( int i=0 ; i < imagen.TellWidth() ; i++)
			{
				imagen(i,j)->Red = 192;
				imagen(i,j)->Green = 50;
				imagen(i,j)->Blue = 50;
				imagen(i,j)->Alpha = 0;
			}
		}

		columnasFilasImagen(columnas,filas,imagen,i);
	}

}




