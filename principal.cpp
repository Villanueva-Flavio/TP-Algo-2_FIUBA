#include <iostream>
#include <sstream>
#include "principal.h"

using namespace std;

void saludarUsuario()
{
	cout<< "---------Bienvenido al Juego de la Vida V.20------------"<<endl;

	cout << "----Aclaraciones------"<<endl;
	cout << "El juego consiste en el cambio que sufre sobre un tablero en 3D el estado vivo de una celula, las dimensiones , la altura y el largo."<<endl;
	cout << "Al final del juego se crearan archivos, con el numero de la cara correspondiente como nombre, que mostraran todos los lados."<<endl;
	cout << "Por ultimo, cabe destacar, que en blanco se representaran las celulas muertas, y en verde las celulas vivas.Tambien a su vez, se encuentra la representacion de la terminal en otra circustancia."<<endl;
	cout << "-------Ahora dicho las reglas, comienza el juego-------"<<endl;
	}

ModoDeJuego configurarElJuego()
{
    ModoDeJuego configuracion;
    int opcion;
    cout << "A continuacion, eliga cual quiere que sea la cantidad de caras del tablero:" << endl;
    cout << "1) Tablero con dimensiones ingresadas manualmente." << endl;
    cout << "2) Tablero de 5x5x5 caras con baja generacion de celulas." << endl;
    cout << "3) Tablero de 10x10x10 caras con una generacion media de celulas." << endl;
    cout << "4) Tablero de 20x20x20 caras con una generacion alta de celulas." << endl
         << endl;
    cin >> opcion;
    cout << endl;

    switch (opcion)
    {
    case 1:
        configuracion = manual;
        break;
    case 2:
        configuracion = configuracion1;
        break;
    case 3:
        configuracion = configuracion2;
        break;
    case 4:
        configuracion = configuracion3;
        break;
    default:
        break;
    }
    return configuracion ;
}

AccionTurno continuarJuego(Tablero *partida)
{
    int respuesta;
    cout << "A continuacion, eliga como continuar el juego:" << endl;
    cout << "Eliga 1 si desea continuar el juego." << endl;
    cout << "Eliga 2 si desea reiniciar el juego." << endl;
    cout << "Eliga 3 si desea terminar el juego." << endl << endl;
    cin >> respuesta;
    cout << endl;
    switch (respuesta)
    {
    case 1:
        partida->getTurno()->siguienteTurno();
        return continuar;

        break;
    case 2:
        eliminarImagenBMP(partida);
        partida->~Tablero();
        return reiniciar;

        break;
    case 3:
        eliminarImagenBMP(partida);
        partida->~Tablero();
        return terminar;

        break;
    default:
        return continuarJuego(partida);

        break;
    }
}

void colocarCelulasMuertasEnBMP(Tablero *partida){

	BMP imagen;
	int columnas = partida->getAncho();
	int filas = partida->getLargo();
	for (unsigned int z = 0; z < partida->getAlto() ; z ++){
		int nombreImagen = z + 1;//Esta conversion sirve para conseguir el numero de la capa, sumandole uno porque el contador inicializa en 0, y representar en un nombre mas entendible.
	    stringstream stringTemporal;
	    stringTemporal<<(nombreImagen);
		std::string str = "capa"+stringTemporal.str()+".bmp";//aqui se crea con la extension.bmp
		const char* capa = str.c_str();
		imagen.ReadFromFile(capa);
		imagen.SetBitDepth(8);
	    imagen.SetSize(filas,columnas);
	    for( int y=0 ; y < imagen.TellHeight() ; y++)
	    {
	    	for(  int x=0 ; x < imagen.TellWidth() ; x++)
	    	{
	    		if (partida->getTablero()->obtener(z + 1)->obtener(y + 1)->obtener(x + 1)->getCelula()->getEstado() == muerto){
	    			RGBApixel colorCelMuerta = imagen.GetPixel(y,x);// Esto sirve para especificar que solo quiero cambiar un determinado tipo de pixel, y no alterar el flujo del resto de colores.
	    			colorCelMuerta.Red = 50; colorCelMuerta.Green = 192; colorCelMuerta.Blue = 50; colorCelMuerta.Alpha = 0;
	    			imagen.SetPixel(x,y,colorCelMuerta);
	    		}

	    	}

	    }
	    imagen.WriteToFile(capa);
	}
}

void generarImagenBMP(Tablero *partida)
{
	BMP imagen;
    int columnas = partida->getAncho();
    int filas = partida->getLargo();
    for (unsigned int z = 0; z < partida->getAlto() ; z ++){
    	imagen.SetBitDepth(8);
    	imagen.SetSize(filas,columnas);
    	for( int y=0 ; y < imagen.TellHeight() ; y++)
    	{
    		for(  int x=0 ; x < imagen.TellWidth() ; x++)
    		{
    			imagen(y, x)->Red =192;
    			imagen(y, x)->Green = 50;
    			imagen(y, x)->Blue = 50;
    			imagen(y,x)->Alpha = 0;
    		}
    	}
    	int nombreImagen = z + 1;//Esta conversion sirve para conseguir el numero de la capa, sumandole uno porque el contador inicializa en 0, y representar en un nombre mas entendible.
    	stringstream stringTemporal;
    	stringTemporal<<(nombreImagen);
    	std::string str = "capa"+stringTemporal.str()+".bmp";
    	const char* capa = str.c_str();
    	imagen.WriteToFile(capa);
    }
}

void eliminarImagenBMP(Tablero *partida)
{
    for (unsigned int i = 0; i < partida->getAlto(); i++)
    {
    	int nombreImagen = i;
    	stringstream stringTemporal;
    	stringTemporal<<(nombreImagen);
    	std::string str = "capa"+stringTemporal.str()+".bmp";
    	const char* capa = str.c_str();
    	remove(capa);
    }
}

int main()
{
    AccionTurno sigTurno;

    do
    {
        saludarUsuario();

        Tablero *partida = new Tablero(configurarElJuego());

        partida->definirCelulasVivas();

        generarImagenBMP(partida);
        colocarCelulasMuertasEnBMP(partida);
        partida->imprimirTablero();
        partida->getTurno()->imprimirTurno();

        partida->getTurno()->imprimirTurno();

        sigTurno = continuarJuego(partida);

        while (sigTurno == continuar)
        {


            partida->resolverTurno();
            eliminarImagenBMP(partida);
            generarImagenBMP(partida);
            colocarCelulasMuertasEnBMP(partida);
            partida->imprimirTablero();
            partida->getTurno()->imprimirTurno();
            sigTurno = continuarJuego(partida);
        }

    } while ((sigTurno == reiniciar) && (sigTurno != terminar));

    return 0;
}




