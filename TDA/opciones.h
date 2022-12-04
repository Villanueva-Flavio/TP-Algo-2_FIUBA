#ifndef __OPCIONES_H__
#define __OPCIONES_H__

#include <iostream>

class Opciones{
    private:
        int parameters[3];
        int dimension[3];
        int celulasIniciales;
        bool automatico;

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
};

Opciones::Opciones(){
    for(int i = 0; i < 3; i ++){
        parameters[i] = 0;
        dimension[i] = 0;
    }
    celulasIniciales = 0;
    automatico = false;
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
    while (this->celulasIniciales < 0 || this->celulasIniciales > max){
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
        while(respuesta < 0 || respuesta > max){
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

void Opciones::solicitarMetadata(string param){
    bool limited = (param == "nolimit")? false : true;
    this->setDimension(limited);
    this->setParameters();
    this->setCelulasIniciales();
    this->setAutomatico();
}

#endif