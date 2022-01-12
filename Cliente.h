//
// Created by jartu on 1/11/2022.
//

#ifndef PROYECTO_ADRIAN_JORGE_CLIENTE_H
#define PROYECTO_ADRIAN_JORGE_CLIENTE_H
#include <iostream>
#include <sstream>
using namespace std;

class Cliente {
private:
    string nombre;
    string id;
    bool nino;
    bool embarazada;
    bool adultoM;
    int categoria;
public:
    Cliente(string nombre = "",string id = "",bool nino = 0,
            bool embarazada = 0, bool adultoM = 0, int cat = 0);
    string getNombre()const;
    void setNombre(string nombre);
    string getID()const;
    void setID(string id);
    bool entraConNino()const;
    bool estaEmbarazada()const;
    bool esAdultoMayor()const;
    int getCategoria()const;
    void setCategoria(int cat);
    string toString();
    int getPorcentajeInfluencia();
};


#endif //PROYECTO_ADRIAN_JORGE_CLIENTE_H
