#ifndef SRC_PRINCIPAL_H_
#define SRC_PRINCIPAL_H_


#include "tablero.h"
#include "EasyBMP.h"

enum AccionTurno{
	continuar,
	reiniciar,
	terminar,
};

/**
 * pre: -
 * pos: un printeo que saluda al usuario antes de iniciar el juego.
 */
void saludarUsuario();

/**
 * pre: -
 * pos: otorga al usuario la capacidad de configurar el juego o elegir una configuracion predeterminada otorgada por el creador.
 */
ModoDeJuego configurarElJuego();

/**
 * pre: la partida debe estar en curso.
 * pos: otorga al usuario decidir si desea: continuar,reiniciar o terminar el juego.
 */
AccionTurno continuarJuego(Tablero *partida);

/*
 * pre:recibe el tablero con la configuracion del juego y datos de la misma.
 * pos:coloca en la imagen ya creada, las celulas muertas representadas en color blanco , y en verde las celulas vivas.
 */
void colocarCelulasMuertasEnBMP(Tablero *partida);

/**
 * pre: recibe la partida con clase tablero, con ya el juego inicializado en la misma.
 * pos: crea imagenes BMP, con la representaicon de las celulas con los genes.
 * y las almacena en la carpeta del contenido del programa.
 */
void generarImagenBMP(Tablero *partida);


/**
 * pre: debe existir el archivo BMP.
 * pos: borra las imagenes BMP .
 */
void eliminarImagenBMP(Tablero* partida);


#endif /* SRC_PRINCIPAL_H_ */
