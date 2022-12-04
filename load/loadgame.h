#include <iostream>
#include "../TDA/juego.h"
using namespace std;

void solicitarDimensiones(int dimensiones[3]){
    for(int i = 0; i < 3; i ++){
        switch (i){
            case 0:
                cout << "Ingrese la cantidad de filas: ";
                break;
            case 1:
                cout << "Ingrese la cantidad de columnas: ";
                break;
            case 2:
                cout << "Ingrese la cantidad de planos: ";
                break;
        }
        cin >> dimensiones[i];
        while(dimensiones[i] < 1 || dimensiones[i] > 100){
            cout << "Por favor ingrese una dimension valida de 1 a 100" << endl;
            cin >> dimensiones[i];
        }
    }
}

void solicitarParametros(int parametros[3]){
    for(int i = 0; i < 3; i ++){
        switch (i){
            case 0:
                cout << "Ingrese el parametro x" << i << " que desea" << endl;
                break;
            case 1:
                cout << "Ingrese el parametro x" << i << " que desea" << endl;
                break;
            case 2:
                cout << "Ingrese el parametro x" << i << " que desea" << endl;
                break;
        }
        cin >> parametros[i];
        while((parametros[i] < 1) || (parametros[i] > 100) || (i == 1 && parametros[1] < parametros[0]) || (i == 2 && parametros[2] < parametros[1])){
            cout << "Por favor ingrese un parametro valido" << endl;
            cin >> parametros[i];
        }
    }
}

void solicitarCelulasIniciales(int &celulasIniciales, int dimensiones[3]){
    int max = dimensiones[0] * dimensiones[1] * dimensiones[2];
    cout << "Ingrese la cantidad de celulas iniciales" << endl;
    cin >> celulasIniciales;
    while (celulasIniciales < 0 || celulasIniciales > max){
        cout << "Por favor ingrese una cantidad valida" << endl;
        cin >> celulasIniciales;
    }
}

void solicitarAutomatico(bool* automatico){
    string respuesta;
    cout << "Desea que el juego sea automatico? (Si/No)" << endl;
    cin >> respuesta;
    while (respuesta != "No" && respuesta != "Si"){
        cout << "Por favor ingrese una opcion valida" << endl;
        cin >> respuesta;
    }
    *automatico = (respuesta == "Si")? true : false;
}

void cargarOpciones(Opciones *aux){
    aux->setDimension();
    aux->setParameters();
    aux->setCelulasIniciales();
    aux->setAutomatico();
}

void cargarMetadataJuego(Juego *gameOfLife){
    Opciones *aux = new Opciones();
    int dimensiones[3];
    cargarOpciones(aux);
    gameOfLife = new Juego(dimensiones, aux);
    delete aux;
}