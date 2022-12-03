#include "ordenarGen.h"
#include "gen.h"
//  Constructores y destructores

controlGen::controlGen(unsigned int maximoDeCargaGenetica)
{
    this->maximoDeCargaGenetica = maximoDeCargaGenetica;
    this->indice = 1;
}

controlGen::~controlGen()
{

}

//  Getters

unsigned int controlGen::getIndice()
{
    return this->indice;
};

//  Setters

void controlGen::setMasUnoIndice()
{
    if (getIndice() == 4)
    {
        this->indice = 1;
    }
    else
    {
        this->indice = getIndice() + 1;
    }
}

//  Funciones

Gen  controlGen::generar(unsigned int gen1, unsigned int gen2, unsigned int gen3)
{
    // validaciones
    Gen* resultado = new Gen(this->maximoDeCargaGenetica);
    switch (getIndice())
    {
    case 1:
        resultado->setCargaGenetica((gen1 + gen2 + gen3) / 3);
        break;
    case 2:
        resultado->setCargaGenetica((gen1 / 2 + (gen2 % gen3)));
        break;
    case 3:
        resultado->setCargaGenetica((gen1 * 2 - gen2 / 2 + gen3));
        break;
    case 4:
        resultado->setCargaGenetica((gen1 % gen2 / 2 + gen3));
        break;
    };
    setMasUnoIndice();

    return *resultado;
}
