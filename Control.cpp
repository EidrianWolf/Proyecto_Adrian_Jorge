
//
// Created by jartu on 1/15/2022.

#include "Control.h"

Control::Control() {
    //Iniciar las estructuras de datos
    principal();
}

void Control::principal() {
    int opc;
    do {
        opc = Vista::menuPrincipal();
        switch (opc) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                control7();
                break;
            default:
                opcionIncorrecta();
                break;
        }
    }while(opc!=7);
}

void Control::control7() {
    Vista::salida();
}

void Control::opcionIncorrecta() {
    Vista::opcionIncorrecta();
}
