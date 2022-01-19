//
// Created by jartu on 1/15/2022.
//

#ifndef PROYECTO_ADRIAN_JORGE_CONTROL_H
#define PROYECTO_ADRIAN_JORGE_CONTROL_H
#include "Vista.h"

class Control {
private:
    BST<Cliente>* bst;
    PriorityQueue<Cliente>* cp;
    //Aqui deberian estar los arboles, las colas y los heaps
public:
    Control();
    void principal();
    //Cada uno de estos metodos es un caso del case en Control::principal()
    void control1();    //Encolar todos los clientes
    void control2();    //Encolar un cliente
    void control3();    //Atender 5 clientes
    void control4();    //Mostrar el siguiente cliente
    void control5();    //Simulacion atencion
    void control6();    //Agregar cliente
    void control7();    //Salir
    void opcionIncorrecta();
};


#endif //PROYECTO_ADRIAN_JORGE_CONTROL_H
