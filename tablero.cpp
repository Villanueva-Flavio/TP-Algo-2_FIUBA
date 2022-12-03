#include <iostream>
#include "tablero.h"

using namespace std;

//  Constructores y destructores

Tablero::Tablero(ModoDeJuego configuracion)
{
    setConfiguracion(configuracion);
    this->matriz = new Lista<Lista<Lista<Celda *> *> *>();

    for (unsigned int k = 0; k < getAlto(); k++) // Rellena tablero
    {
        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>(); // crea las caras

        for (unsigned int j = 0; j < getLargo(); j++) //rellna las caras
        {
            Lista<Celda *> *columna = new Lista<Celda *>(); // crea las columnas

            for (unsigned int i = 0; i < getAncho(); i++) //rellana columnas
            {
                Celda *fila = new Celda(i+1, j+1, k+1, estandar); // crea filas

                columna->agregar(fila); // agrega la filas a columnas
            }
            pagina->agregar(columna); // agrega columnas a las caras
        }
        this->matriz->agregar(pagina); // se agregan finalmente las caras al tablero
    }
    this->turno = new Turno();
}

Tablero::Tablero(Tablero* tableroOriginal)
{
    if (tableroOriginal->matrizVacia()){
        throw "el tablero a copiar no puede estar vacio";
    }

    this->matriz = new Lista<Lista<Lista<Celda *> *> *>();
    this->alto = tableroOriginal->getAlto();
    this->ancho = tableroOriginal->getAncho();
    this->largo = tableroOriginal->getLargo();
    this->X1 = tableroOriginal->getX1();
    this->X2 = tableroOriginal->getX2();
    this->X3 = tableroOriginal->getX3();
    this->turno = tableroOriginal->getTurno();

     for (unsigned int i = 0; i < getAlto(); i++)
    {
        Lista<Lista<Celda *> *> *pagina = new Lista<Lista<Celda *> *>();

        for (unsigned int j = 0; j < getAncho(); j++)
        {
            Lista<Celda *> *columna = new Lista<Celda *>(); // crea la columna

            for (unsigned int k = 0; k < getLargo(); k++)
            {
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

Tablero::~Tablero()
{
    this->matriz->iniciarCursor();

    while (this->matriz->avanzarCursor())
    {
        Lista<Lista<Celda *> *> *temp = this->matriz->obtenerCursor();

        temp->iniciarCursor();
        while (temp->avanzarCursor())
        {
            delete temp->obtenerCursor();
        }
        delete temp;
    }
    delete this->matriz;
}

Lista<Lista<Lista<Celda *> *> *> *Tablero::getTablero()
{
    return this->matriz;
}

unsigned int Tablero::getX1()
{
    return X1;
}

unsigned int Tablero::getX2()
{
    return X2;
}

unsigned int Tablero::getX3()
{
    return X3;
}

unsigned int Tablero::getAlto()
{
    return this->alto;
}

unsigned int Tablero::getAncho(){
    return this->ancho;
}

unsigned int Tablero::getLargo()
{
    return this->largo;
}

Turno* Tablero::getTurno()
{
    return turno;
}

//  Setters

void Tablero::setConfiguracion(ModoDeJuego configuracion)
{
	switch (configuracion)
    {
        case manual:

            cout << "Ingrese el ancho del tablero deseado: " << endl;
            cin >> this->ancho;
            cout << "Ingrese el largo del tablero deseado: " << endl;
            cin >> this->largo;
            cout << "Ingrese el alto del tablero deseado: " << endl;
            cin >> this->alto;
            cout << "Ingrese la cantidad de celulas vecinas vivas necesarias para que nazca una celula: " << endl;
            cin >> this->X1;
            cout << "Ingrese la cantidad de celulas vecinas vivas para que muera una celula por soledad: " << endl;
            cin >> this->X2;
            cout << "Ingrese la cantidad maxima de celulas vecinas vivas para que muera una celula por sobrepoblación: " << endl;
            cin >> this->X3;
            cout << endl;

            break;
        case configuracion1:

            this->alto = 5;
            this->ancho = 5;
            this->largo = 5;
            this->X1 = 3;
            this->X2 = 2;
            this->X3 = 4;

            break;
        case configuracion2:

            this->alto = 10;
            this->ancho = 10;
            this->largo = 10;
            this->X1 = 3;
            this->X2 = 2;
            this->X3 = 4;

            break;
        case configuracion3:

            this->alto = 20;
            this->ancho = 20;
            this->largo = 20;
            this->X1 = 3;
            this->X2 = 2;
            this->X3 = 4;

            break;
    }
}

//  Funciones

void Tablero::definirCelulasVivas()
{
    char respuesta;
    do
    {
    	cout << "A continuacion, ingrese las celulas." << endl;
    	char continuar;
    	do
    	{
    		unsigned int coordenadaX, coordenadaY, coordenadaZ;
    		do
    		{
    			cout << "Ingrese la fila: " << endl;
                cin >> coordenadaX;
    		} while ((coordenadaX <= 0) || (coordenadaX > getLargo()));
    		do
    		{
    			cout << "Ingrese la columna: " << endl;
                cin >> coordenadaY;
    		}while ((coordenadaY <= 0) || (coordenadaY > getAncho()));

             do
             {
            	 cout << "Ingrese la cara: " << endl;
                 cin >> coordenadaZ;

              }while ((coordenadaZ <= 0) || (coordenadaZ > getAlto()));

             getTablero()->obtener(coordenadaZ)->obtener(coordenadaY)->obtener(coordenadaX)->getCelula()->setEstado(vivo);
             getTurno()->sumarViva();
             cout << "Se ha ingresado con exito la celula (" << coordenadaX << ", " << coordenadaY << ", " << coordenadaZ << ")." << endl;
             cout << endl;
             do
             {
            	 cout << "Desea continuar con el ingreso de celulas? s/n." << endl << endl;
                 cin >> continuar;
                 cout << endl;

              }while ((continuar != 's') && (continuar != 'n') && (continuar != 'S') && (continuar != 'N'));

            } while ((continuar == 's') || (continuar == 'S'));

    } while ((respuesta == 's') || (respuesta == 'S'));

    cout << "-----Se a completado el ingreso de celulas------" << endl;
}

void Tablero::contadorCelulasVecinas(unsigned int pagina, unsigned int columna, unsigned int fila, Tablero *temp)
{
    int vecinasVivas = 0;
    unsigned int vecinaX;
    unsigned int vecinaY;
    unsigned int vecinaZ;
    Lista<Celda *> *listaVecinasVivas = new Lista<Celda *>;

    Celda *celdaCentro = getTablero()->obtener(pagina)->obtener(columna)->obtener(fila);

    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            for (int k = -1; k <= 1; k++)
            {

                if ((int(celdaCentro->getPosicionZ()) + i) == 0)
                {
                    vecinaZ = getAlto();
                }
                else if ((int(celdaCentro->getPosicionZ()) + i) == (int(getAlto()) + 1))
                {
                    vecinaZ = 1;
                }
                else
                {
                    vecinaZ = celdaCentro->getPosicionZ() + i;
                }

                //--------------------------------------------------//

                if ((int(celdaCentro->getPosicionY()) + j) == 0)
                {
                    vecinaY = getAncho() ;
                }
                else if ((int(celdaCentro->getPosicionY()) + j) == (int(getAncho()) + 1))
                {
                    vecinaY = 1;
                }
                else
                {
                    vecinaY = celdaCentro->getPosicionY() + j;
                }

                //--------------------------------------------------//

                if ((int(celdaCentro->getPosicionX()) + k) == 0)//3
                {
                    vecinaX = getLargo() ;
                }
                else if ((int(celdaCentro->getPosicionX()) + k) == (int(getLargo()) + 1))
                {
                    vecinaX = 1;
                }
                else
                {
                    vecinaX = celdaCentro->getPosicionX() + k;
                }

                if (!(i == 0 && j == 0 && k == 0))
                {


                    if (getTablero()->obtener(vecinaZ)->obtener(vecinaY)->obtener(vecinaX)->getCelula()->getEstado() == vivo)
                    {
                        vecinasVivas++;
                         if(listaVecinasVivas->contarElementos() < getX1())
                        {
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

void Tablero::contabilizarCasos(Estado aux, Celda *celdaCentro)
{
    if ((celdaCentro->getCelula()->getEstado() != aux))
    {
        if (aux == muerto)
        {
            getTurno()->setMuertasEnTurno(getTurno()->getMuertasEnTurno() + 1);
        }
        else
        {
            getTurno()->setRenacidasEnTurno(getTurno()->getRenacidasEnTurno() + 1);
        }
    }
}

unsigned int Tablero::numeroAleatorio(unsigned int maximo)
{
    srand(time(NULL));
    return rand() % maximo + 1;
};

void Tablero::devolverTablero(unsigned int x, unsigned int y, unsigned int z)
{
    if (getTablero()->obtener(z + 1)->obtener(y + 1)->obtener(x + 1)->getCelula()->getEstado() == vivo)
    {
        cout << 1 << " ";
    }
    else if (getTablero()->obtener(z + 1)->obtener(y + 1)->obtener(x + 1)->getCelula()->getEstado() == muerto)
    {
        cout << 0 << " ";
    }
}

void Tablero::resolverTurno()
{
	Tablero *temp = new Tablero(this);

    for (unsigned int i = 0; i < temp->getAlto(); i++)
    {
        for (unsigned int j = 0; j < temp->getAncho(); j++)
        {
            for (unsigned int k = 0; k < temp->getLargo(); k++)
            {
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
    while (aux->avanzarCursor())
    {
        Lista<Lista<Celda *> *> *temp2 = aux->obtenerCursor();
        temp2->iniciarCursor();
        while (temp2->avanzarCursor())
        {
            delete temp2->obtenerCursor();
        }
        delete temp2;
    }
    delete aux;
}


void Tablero::imprimirTablero()
{

    for (unsigned int z = 0; z < getAlto(); z++)
    {
        cout << "Cara numero " << z + 1 << ":" << endl
             << endl;
        for (unsigned int y = 0; y < getAncho(); y++)
        {
            cout << "     ";
            for (unsigned int x = 0; x < getLargo(); x++)
            {
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

