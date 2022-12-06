#ifndef __OPCIONES_H__
#define __OPCIONES_H__

#include <iostream>

class Opciones{
    private:
        int parameters[3];
        int dimension[3];
        int celulasIniciales;
        bool automatico;
        bool limited;

    public:
        Opciones();
        void setParameters();
        void setDimension();
        void setCelulasIniciales();
        void setAutomatico();
        int getParameters(int i);
        int getDimension(int i);
        int getCelulasIniciales();
        bool getAutomatico();
        void solicitarMetadata(string param);
        void setLimited(string data);
        bool getLimited();
        void solicitarOpcionConfig(int* respuesta);
        void setConfig(int opcion);
        void solicitarConfig();
        
};

Opciones::Opciones(){
    for(int i = 0; i < 3; i ++){
        parameters[i] = 0;
        dimension[i] = 0;
    }
    celulasIniciales = 0;
    automatico = false;
    limited = true;
}

string getLimited(){
    return this->limited;
}

void setLimited(string data){
    this->limited = (data == "nolimit")? false : true;
}

void Opciones::setAutomatico(){
    string respuesta;
    cout << "Desea que el juego sea automatico? (1 = Si, 0 = No)" << endl;
    cin >> respuesta;
    while (respuesta != "No" && respuesta != "Si"){
        cout << "Por favor ingrese una opcion valida" << endl;
        cin >> respuesta;
    }
    this->automatico = (respuesta == "Si")? true : false;
}

void Opciones::setCelulasIniciales(){
    int max = this->dimension[0] * this->dimension[1] * this->dimension[2];
    cout << "Ingrese la cantidad de celulas iniciales" << endl;
    cin >> this->celulasIniciales;
    while (this->celulasIniciales < 1 || this->celulasIniciales > max){
        cout << "Por favor ingrese una cantidad valida" << endl;
        cin >> this->celulasIniciales;
    }
}

void Opciones::setDimension(bool limited){
    int respuesta;
    int max = (limited)? 100 : 10000;
    cout << "Ingrese la dimension del tablero que desea hasta 100 por dimension" << endl;
    for(int i = 0; i < 3; i++){
        cin >> respuesta;
        while(respuesta < 1 || respuesta > max){
            cout << "Por favor ingrese una dimension valida" << endl;
            cin >> respuesta;
        }
        this->dimension[i] = respuesta;
    }
}

void Opciones::setParameters(){
    int respuesta;
    for(int i = 0; i < 3; i ++){
        cout << "Ingrese el parametro x" << i << " que desea" << endl;
        cin >> respuesta;
        while((respuesta < 1) || (respuesta > 100) || (i == 1 && this->parameters[1] < this->parameters[0]) || (i == 2 && this->parameters[2] < this->parameters[1])){
            cout << "Por favor ingrese un parametro valido" << endl;
            cin >> respuesta;
        }
        this->parameters[i] = respuesta;
    }
}

int Opciones::getParameters(int i){
    return this->parameters[i];
}

int Opciones::getDimension(int i){
    return this->dimension[i];
}

int Opciones::getCelulasIniciales(){
    return this->celulasIniciales;
}

bool Opciones::getAutomatico(){
    return this->automatico;
}


void Opciones::solicitarOpcionConfig(int* respuesta){
    cout << "Ingrese la opcion que desea" << endl;
    cout << "Opcion 1: Mapa 10x10x10 con 10 celulas iniciales" << endl;
    cout << "Opcion 2: Mapa 30x30x30 con 30 celulas iniciales" << endl;
    cout << "Opcion 3: Mapa 100x100x100 con 100 celulas iniciales" << endl;
}

void Opciones::setConfig(int opcion){
    int celulas = (opcion == 1)? 10 : (opcion == 2)? 30 : 100;
    int dimension = (opcion == 1)? 10 : (opcion == 2)? 30 : 100;
    this->dimension[0] = dimension;
    this->dimension[1] = dimension;
    this->dimension[2] = dimension;
    this->celulasIniciales = celulas;
}

void Opciones::solicitarConfig(){
    cout << "Desea configurar el juego? (1 = Si, 0 = No)" << endl;
    cin >> respuesta;
    while (respuesta != "No" && respuesta != "Si"){
        cout << "Por favor ingrese una opcion valida" << endl;
        cin >> respuesta;
    }
    if(respuesta == "Si"){
        int respuesta;
        solicitarOpcionConfig(&respuesta);
        setConfig(respuesta);
    }
}

void Opciones::solicitarMetadata(string param){

    this->setLimited(param);
    this->setDimension(limited);
    this->setParameters();
    this->setCelulasIniciales();
    this->setAutomatico();
}

#endif