#ifndef __JUEGO_H__
#define __JUEGO_H__
#include "tablero.h"
class JuegoDeLaVida{
    private:
    // Los parametros para las reglas
        int x;
        int y;
        int z;
        Tablero<Celula*>* tab;
        //estadisticas
        int nacidas;
        int muertas;
        float promedioNacidas;
        float promedioMuertas;
        int celulasVivas;
        int turno;

    public:

        JuegoDeLaVida(int n, int m, int l);
        ~JuegoDeLaVida();
        void setParametros(int x, int y, int z);
        //void agregarCelula();
        //void agregarGen();
        void actualizarDatos();
        void llenarTablero(Tablero<Celula>* tablero);
        void iniciarJuego();
        void setCargaManual();
        void setDimensionTablero();
        void setCelulasIniciales();
        void setCoordenadas();
        std::string pedirDecisionTurno();
        void cargaAutomatica();
        void ejecutarTurnos();
        void reiniciarJuego();
        void terminarJuego();
        void getPromedioNacidas();
        void getPromedioMuertas();
        void getNacidas();
        void getMuertas();
        void getTurno();
        bool getJuegoCongelado();
};

JuegoDeLaVida::JuegoDeLaVida(int n, int m, int l){
    this->tab = new Tablero<Celula*>(n, m, l);
    this->nacidas = 0;
    this->muertas = 0;
    this->promedioNacidas = 0.0;
    this->promedioMuertas = 0.0;
    this->celulasVivas = 0;
    this->turno = 0;
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

JuegoDeLaVida::~JuegoDeLaVida(){

}

void JuegoDeLaVida::setParametros(int x, int y, int z){
    this->x = x;
    this->y = y;
    this->z = z;
}

void JuegoDeLaVida::llenarTablero(Tablero<Celula>* tablero){
    Celula celula = aux.getData;

    setEstado("VIVA");
}

#endif
