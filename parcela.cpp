#include "parcela.h"
#include "lista.h"

//  Constructores y destructores

Celda::Celda(unsigned int posicionX, unsigned int posicionY, unsigned int posicionZ, Tipo tipo)
{
    this->setPosicionX(posicionX);
    this->setPosicionY(posicionY);
    this->setPosicionZ(posicionZ);
    this->setTipo(tipo);

    this->celula = new Celula(muerto,0,0,0);
}

//  Getters

unsigned int Celda::getPosicionX()
{
    return this->posicionX;
}
unsigned int Celda::getPosicionY()
{
    return this->posicionY;
}
unsigned int Celda::getPosicionZ()
{
    return this->posicionZ;
}
Tipo Celda::getTipo()
{
    return this->tipo;
}
Celula *Celda::getCelula()
{
    return this->celula;
}

//  Setters

void Celda::setPosicionX(unsigned int nuevaPosicionX = 0)
{
    this->posicionX = nuevaPosicionX;
}
void Celda::setPosicionY(unsigned int nuevaPosicionY = 0)
{
    this->posicionY = nuevaPosicionY;
}
void Celda::setPosicionZ(unsigned int nuevaPosicionZ = 0)
{
    this->posicionZ = nuevaPosicionZ;
}
void Celda::setTipo(Tipo nuevoTipo = estandar)
{
    this->tipo = nuevoTipo;
}

void Celda::actualizarEstadoCelula(unsigned int celulasVecinas, unsigned int x1, unsigned int x2, unsigned int x3, Lista<Celda *> *listaVecinasVivas)
{
    if ((celulasVecinas == x1) && (getCelula()->getEstado() == muerto))
    {
        getCelula()->setEstado(vivo);
        actualizaGenesCelula(listaVecinasVivas);
    }
    else if ((celulasVecinas < x2 || celulasVecinas > x3) && (getCelula()->getEstado() == vivo))
    {
        getCelula()->setEstado(muerto);
    };
}

void Celda::actualizaGenesCelula(Lista<Celda *> *listaVecinasVivas)
{
    if (this->getCelula()->getEstado() == vivo)
    {
        controlGen *nuevoGen = new controlGen(255);
        for (unsigned int i = 0; i < listaVecinasVivas->contarElementos(); i++)
        {
            switch (i)
            {
            case 1:
                getCelula()->setGen1(nuevoGen->generar(listaVecinasVivas->obtener(i+1)->getCelula()->getGen1(), listaVecinasVivas->obtener(i)->getCelula()->getGen2(), listaVecinasVivas->obtener(i)->getCelula()->getGen3()).getCargaGenetica());
                break;
            case 2:
                getCelula()->setGen2(nuevoGen->generar(listaVecinasVivas->obtener(i+1)->getCelula()->getGen1(), listaVecinasVivas->obtener(i)->getCelula()->getGen2(), listaVecinasVivas->obtener(i)->getCelula()->getGen3()).getCargaGenetica());
                break;
            case 3:
                getCelula()->setGen3(nuevoGen->generar(listaVecinasVivas->obtener(i+1)->getCelula()->getGen1(), listaVecinasVivas->obtener(i)->getCelula()->getGen2(), listaVecinasVivas->obtener(i)->getCelula()->getGen3()).getCargaGenetica());
                break;
            default:
                break;
            }
        }
        delete nuevoGen;
    }
}




