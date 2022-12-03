#ifndef SRC_ORDENARGEN_H_
#define SRC_ORDENARGEN_H_

#include "gen.h"
class controlGen
{

private:
    unsigned int maximoDeCargaGenetica;
    unsigned int indice;

public:
    //  Constructores y destructor
        /**
         * pre: maximoDeCargaGenetica tiene que ser mayor a 0.
         * pos: setea el indice en 1 y el maximo de la carga genetica
         */
        controlGen(unsigned int maximoDeCargaGenetica);

        /**
         * pre: -
         * pos: elimina la memoria dinamica del administrador de gen.
         */
        virtual ~controlGen();

    //  Getters

        /**
         * pre: -
         * pos: devuelve el indice del aministrador de gen
         */
        unsigned int getIndice();

    //  Setters
        /**
         * pre: -
         * pos: le suma 1 a el indice del administrador de gen
         */
        void setMasUnoIndice();

    //  Funciones
    /**
     * pre: que los genes no sean nulos
     * pos: devuelve un gen con maximoDeCargaGenetica en "maximoDeCargaGenetica" y cargaGenetica como el promedio
     */
    Gen generar(unsigned int gen1, unsigned int gen2, unsigned int gen3);


};


#endif /* SRC_ORDENARGEN_H_ */
