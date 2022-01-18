//
// Created by jartu on 1/15/2022.
//

#ifndef PROYECTO_ADRIAN_JORGE_CONTROL_H
#define PROYECTO_ADRIAN_JORGE_CONTROL_H
#include "Vista.h"

class Control {
private:
    BST<Cliente>* bst;
    //Aqui deberian estar los arboles, las colas y los heaps
public:
    Control();
    void principal();
    //Cada uno de estos metodos es un caso del case en Control::principal()
    void control1();
    void control2();
    void control3();
    void control4();
    void control5();
    void control6();
    void control7();
    void opcionIncorrecta();
};


#endif //PROYECTO_ADRIAN_JORGE_CONTROL_H
