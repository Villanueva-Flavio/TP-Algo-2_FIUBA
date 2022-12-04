#include <iostream>
#include "tablero.h"

using namespace std;

//  Constructores y destructores

Tablero::Tablero(ModoDeJuego configuracion){
    setConfiguracion(configuracion);
    this->matriz = new Lista<Lista<Lista<Celda *> *> *>();

    for (unsigned int k = 0; k < getAlto(); k++){
        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>();
        for (unsigned int j = 0; j < getLargo(); j++){
            Lista<Celda *> *columna = new Lista<Celda *>();
            for (unsigned int i = 0; i < getAncho(); i++){
                Celda *fila = new Celda(i+1, j+1, k+1, estandar);
                columna->agregar(fila);
            }
            pagina->agregar(columna);
        }
        this->matriz->agregar(pagina);
    }
    this->turno = new Turno();
}

//Copiar datos de un tablero a otro
void Tablero::copyTablero(Tablero original){
    this->alto = tableroOriginal->getAlto();
    this->ancho = tableroOriginal->getAncho();
    this->largo = tableroOriginal->getLargo();
    this->X1 = tableroOriginal->getX1();
    this->X2 = tableroOriginal->getX2();
    this->X3 = tableroOriginal->getX3();
    this->turno = tableroOriginal->getTurno();
}

Tablero::Tablero(Tablero* tableroOriginal){
    if (tableroOriginal->matrizVacia()){
        throw "el tablero a copiar no puede estar vacio";
    }

    this->matriz = new Lista<Lista<Lista<Celda *> *> *>();
    copyTablero(*tableroOriginal);

    for (unsigned int i = 0; i < getAlto(); i++){
        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>();
        for (unsigned int j = 0; j < getAncho(); j++){
            Lista<Celda *> *columna = new Lista<Celda *>();
            for (unsigned int k = 0; k < getLargo(); k++){
                Celda *fila = new Celda(i+1, j+1, k+1, estandar);
                fila->setTipo(tableroOriginal->getTablero()->obtener(i + 1)->obtener(j + 1)->obtener(k + 1)->getTipo());
                fila->getCelula()->setEstado(tableroOriginal->getTablero()->obtener(i + 1)->obtener(j + 1)->obtener(k + 1)->getCelula()->getEstado());
                fila->getCelula()->setGen1(tableroOriginal->getTablero()->obtener(i + 1)->obtener(j + 1)->obtener(k + 1)->getCelula()->getGen1());
                fila->getCelula()->setGen2(tableroOriginal->getTablero()->obtener(i + 1)->obtener(j + 1)->obtener(k + 1)->getCelula()->getGen2());
                fila->getCelula()->setGen3(tableroOriginal->getTablero()->obtener(i + 1)->obtener(j + 1)->obtener(k + 1)->getCelula()->getGen3());
                columna->agregar(fila);
            }
            pagina->agregar(columna); // agregar la columna a la página
        }
        this->matriz->agregar(pagina); // agrega la página al tablero
    }
}

Tablero::~Tablero(){
    this->matriz->iniciarCursor();
    while (this->matriz->avanzarCursor()){
        Lista<Lista<Celda *> *> *temp = this->matriz->obtenerCursor();
        temp->iniciarCursor();
        while (temp->avanzarCursor()){
            delete temp->obtenerCursor();
        }
        delete temp;
    }
    delete this->matriz;
}

Lista<Lista<Lista<Celda *> *> *> *Tablero::getTablero(){
    return this->matriz;
}

unsigned int Tablero::getX1(){
    return X1;
}

unsigned int Tablero::getX2(){
    return X2;
}

unsigned int Tablero::getX3(){
    return X3;
}

unsigned int Tablero::getAlto(){
    return this->alto;
}

unsigned int Tablero::getAncho(){
    return this->ancho;
}

unsigned int Tablero::getLargo(){
    return this->largo;
}

Turno* Tablero::getTurno(){
    return turno;
}

//  Setters

void preguntarEntero(int* numero, int max){
    do{
        cin >> *numero;
    } while (*numero < 0 || *numero > max);
}                                           // DEFINIR!!!!!!!!!!!!!!!!!!!!!!

void Tablero::preguntarDimensiones(){
    system("clear");
    cout << "Ingrese las dimensiones del tablero: " << endl;
    cout << "Alto: ";
    preguntarEntero(this->alto, 100);
    cout << "Ancho: ";
    preguntarEntero(this->ancho, 100);
    cout << "Largo: ";
    preguntarEntero(this->largo, 100); // DEFINIR
}

void Tablero::preguntarParametros(){ // DEFINIR
    system("clear");
    cout << "Ingrese los parametros del juego: " << endl;
    cout << "X1: ";
    preguntarEntero(this->X1, 100);
    cout << "X2: ";
    preguntarEntero(this->X2, 100);
    cout << "X3: ";
    preguntarEntero(this->X3, 100);
}

void Tablero::definirDimensiones(int dimension){ // DEFINIR
    this->alto = dimension;
    this->ancho = dimension;
    this->largo = dimension;
}

void Tablero::setConfiguracion(ModoDeJuego configuracion){
    this->X1 = 3, this->X2 = 2, this->X3 = 4;
	switch (configuracion){
        case manual:
            preguntaresDimensiones();
            preguntarParametros();
            break;

        case configuracion1:
            definirDimensiones(5);
            break;

        case configuracion2:
            definirDimensiones(10);
            break;

        case configuracion3:
            definirDimensiones(15);
            break;
    }
}

//  Funciones

void solicitarDecision(char* respuesta){
    do{
        cout << "Desea continuar? (s/n): ";
        cin >> *respuesta;
    } while (*respuesta != 's' && *respuesta != 'n');
}

void Tablero::definirCelulasVivas(){
    char respuesta;
    unsigned int coorrdenadaX, coordenadaY, coordenadaZ;

    do{
        system("clear");
        cout << "Ingresando Celula . . ." << endl << "Ingrese la fila: " << endl;
        preguntarEntero(&coordenadaX, getLargo());
        cout << "Ingrese la columna: " << endl;
        preguntarEntero(&coordenadaY, getAncho());
        cout << "Ingrese la cara: " << endl;
        preguntarEntero(&coordenadaZ, getAlto());

        getTablero()->obtener(coordenadaX)->obtener(coordenadaY)->obtener(coordenadaZ)->getCelula()->setEstado(viva);
        getTurno()->sumarViva();

        cout << endl << endl << "Se ha ingresado con exito la celula (" << coordenadaX << ", " << coordenadaY << ", " << coordenadaZ << ")." << endl;

        solicitarDecision(&respuesta);
    } while((respuesta == 's') || (respuesta == 'S'));
}

void Tablero::contadorCelulasVecinas(unsigned int pagina, unsigned int columna, unsigned int fila, Tablero *temp){
    int vecinasVivas = 0;
    unsigned int vecinaX, vecinaY, vecinaZ;
    Lista<Celda *> *listaVecinasVivas = new Lista<Celda *>;
    Celda *celdaCentro = getTablero()->obtener(pagina)->obtener(columna)->obtener(fila);

    for(int i = -1; i <= 1; i++){
        for(int j = -1; j <= 1; j++){
            for(int k = -1; k <= 1; k++){
                if((int(celdaCentro->getPosicionZ()) + i) == 0){
                    vecinaZ = getAlto();
                } else if ((int(celdaCentro->getPosicionZ()) + i) == (int(getAlto()) + 1)) {
                    vecinaZ = 1;
                } else {
                    vecinaZ = celdaCentro->getPosicionZ() + i;
                }

                //--------------------------------------------------//

                if((int(celdaCentro->getPosicionY()) + j) == 0){
                    vecinaY = getAncho() ;
                } else if ((int(celdaCentro->getPosicionY()) + j) == (int(getAncho()) + 1)) {
                    vecinaY = 1;
                } else {
                    vecinaY = celdaCentro->getPosicionY() + j;
                }

                //--------------------------------------------------//

                if((int(celdaCentro->getPosicionX()) + k) == 0) {
                    vecinaX = getLargo() ;
                } else if ((int(celdaCentro->getPosicionX()) + k) == (int(getLargo()) + 1)) {
                    vecinaX = 1;
                } else {
                    vecinaX = celdaCentro->getPosicionX() + k;
                }

                if(!(i == 0 && j == 0 && k == 0)) {
                    if(getTablero()->obtener(vecinaZ)->obtener(vecinaY)->obtener(vecinaX)->getCelula()->getEstado() == vivo){
                        vecinasVivas++;
                        if(listaVecinasVivas->contarElementos() < getX1()) {
                            listaVecinasVivas->agregar(getTablero()->obtener(vecinaZ)->obtener(vecinaY)->obtener(vecinaX));
                        }
                    }
                }
            }
        }
    }
    temp->getTablero()->obtener(pagina)->obtener(columna)->obtener(fila)->actualizarEstadoCelula(vecinasVivas, getX1(), getX2(), getX3(), listaVecinasVivas);
    Estado aux = temp->getTablero()->obtener(pagina)->obtener(columna)->obtener(fila)->getCelula()->getEstado();
    temp->contabilizarCasos(aux, celdaCentro);
    listaVecinasVivas->iniciarCursor();
}

void Tablero::contabilizarCasos(Estado aux, Celda *celdaCentro){
    if ((celdaCentro->getCelula()->getEstado() != aux)){
        if (aux == muerto){
            getTurno()->setMuertasEnTurno(getTurno()->getMuertasEnTurno() + 1);
        } else {
            getTurno()->setRenacidasEnTurno(getTurno()->getRenacidasEnTurno() + 1);
        }
    }
}

unsigned int Tablero::numeroAleatorio(unsigned int maximo){
    srand(time(NULL));
    return rand() % maximo + 1;
};

void Tablero::devolverTablero(unsigned int x, unsigned int y, unsigned int z){
    if (getTablero()->obtener(z + 1)->obtener(y + 1)->obtener(x + 1)->getCelula()->getEstado() == vivo){
        cout << 1 << " ";
    } else if (getTablero()->obtener(z + 1)->obtener(y + 1)->obtener(x + 1)->getCelula()->getEstado() == muerto){
        cout << 0 << " ";
    }
}

void Tablero::resolverTurno(){
	Tablero *temp = new Tablero(this);
    for (unsigned int i = 0; i < temp->getAlto(); i++){
        for (unsigned int j = 0; j < temp->getAncho(); j++){
            for (unsigned int k = 0; k < temp->getLargo(); k++){
                this->contadorCelulasVecinas(i + 1, j + 1, k + 1, temp);
                getTurno()->setPromedioNacidas(getTurno()->getRenacidasEnTurno());
                getTurno()->setPromedioMuertas(getTurno()->getMuertasEnTurno());
            }
        }
    }
    getTurno()->comparacionDeTurnos(temp->getTurno());
    Lista<Lista<Lista<Celda *> *> *> *aux = getTablero();
    this->matriz = temp->getTablero();
    aux->iniciarCursor();
    while (aux->avanzarCursor()){
        Lista<Lista<Celda *> *> *temp2 = aux->obtenerCursor();
        temp2->iniciarCursor();
        while (temp2->avanzarCursor()){
            delete temp2->obtenerCursor();
        }
        delete temp2;
    }
    delete aux;
}


void Tablero::imprimirTablero(){
    for (unsigned int z = 0; z < getAlto(); z++){
        cout << "Cara numero " << z + 1 << ":" << endl
             << endl;
        for (unsigned int y = 0; y < getAncho(); y++){
            cout << "     ";
            for (unsigned int x = 0; x < getLargo(); x++){
                devolverTablero(x, y, z);
            };
            cout << endl;
        }
        cout << endl;
    }
}

bool Tablero::matrizVacia(){
    bool resultado = false;
    if (!getTablero()->estaVacia()){
        if (!getTablero()->obtener(1)->estaVacia()){
            if (getTablero()->obtener(1)->obtener(1)->estaVacia()){
                resultado = true;
            }
        }else{
            resultado = true;
        }
    }else{
        resultado = true;
    }
    return resultado;
}