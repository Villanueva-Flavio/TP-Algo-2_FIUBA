#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_


#include "parcela.h"
#include "turnos.h"
#include "lista.h"
#include <cstdlib>
#include <ctime>

enum ModoDeJuego
{
    manual,
    configuracion1,
    configuracion2,
    configuracion3
};

class Tablero
{
private:
    Lista<Lista<Lista<Celda *> *> *> *matriz;
    Turno *turno;
    unsigned int alto;
    unsigned int largo;
    unsigned int ancho;
    unsigned int X1;
    unsigned int X2;
    unsigned int X3;

public:

    //  Constructores y destructores

    /**
     * pre: configuracion debe estar definido.
     * pos: inicializa el tablero con su respectiva configuracion.
     */
    Tablero(ModoDeJuego configuracion);

    /**
     * pre: tableroOriginal debe estar definido y debe ser no vacio.
     * pos: se crea una copia del tablero original.
     */
    Tablero(Tablero* taberoOriginal);

    /**
     * pre: el tablero debe estar definido y no debe ser vacio.
     * pos: destruye el tablero creado.
     */
    ~Tablero();


    //  Getters

    /**
     * pre: -
     * pos: devuelve un puntero a la matriz.
     */
    Lista<Lista<Lista<Celda *> *> *> *getTablero();

    /**
     * pre: -
     * pos: devuelve el numero de celulas vecinas necesarias para que una celula nazca.
     */
    unsigned int getX1();

    /**
     * pre: -
     * pos: devuelve el numero de celulas vecinas vivas necesarias para que muera por soledad.
     */
    unsigned int getX2();

    /**
     * pre: -
     * pos: devuelve el numero de celulas vecinas vivas necesarias para que muera por sobrepoblacion.
     */
    unsigned int getX3();

    /**
     * pre: -
     * pos: devuelve el numero de paginas del tablero.
     */
    unsigned int getAlto();

    /**
     * pre: -
     * pos: devuelve el numero de columnas del tablero.
     */
    unsigned int getAncho();

    /**
     * pre: -
     * pos: devuelve el numero de filas del tablero.
     */
    unsigned int getLargo();

    /**
     * pre: -
     * pos: devuelve un puntero a turno.
     */
    Turno* getTurno();

    //  Setters

    /**
     * pre: -
     * pos: configura los distintos modos de juego
     */
    void setConfiguracion(ModoDeJuego configuracion);


    //  Funciones

    /**
     * pre: la matriz debe estar definida y no debe estar vacia.
     * pos: por medio de consola se ingresan las celulas que empezaran el juego como vivas.
     */
    void definirCelulasVivas();

    /**
     * pre: -
     * pos: -
     */
    void contabilizarCasos(Estado aux, Celda *celdaCentro);

    /**
     * pre: el juego debe haberce iniciado, y se le debe pasar la cara,la columna y la fila, junto a un tablero temporal.
     * pos: Cuenta las celulas vivas vecinas una vez iniciado el juego.
     */
    void contadorCelulasVecinas(unsigned int fila, unsigned int columna, unsigned int pagina, Tablero *Aux);

    /**
     * pre: -
     * pos: -
     */
    unsigned int numeroAleatorio(unsigned int maximo);

    /**
     * pre: -
     * pos: -
     */
    void resolverTurno();

    /**
     * pre: -
     * pos: -
     */
    void imprimirTablero();

    /**
    * pre: -
    * pos: -
    */
    void devolverTablero(unsigned int i, unsigned int j, unsigned int k);


    //  Condiciones

    /**
    * pre: -
    * pos: -
    */
    bool matrizVacia();
};



#endif /* SRC_TABLERO_H_ */
