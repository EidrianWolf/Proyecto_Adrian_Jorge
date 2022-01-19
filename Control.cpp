
//
// Created by jartu on 1/15/2022.

#include "Control.h"

Control::Control() {
    //Iniciar las estructuras de datos
    bst = new BST<Cliente>;
    cp = new PriorityQueue<Cliente>(100);
    principal();
}

void Control::principal() {
    Archivos<Cliente> file("DatosBancoUno.txt");
    file.cargar(bst);

    int opc;
    do {
        opc = Vista::menuPrincipal();
        switch (opc) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                control6();
                break;
            case 7:
                control7();
                break;
            default:
                opcionIncorrecta();
                break;
        }
    }while(opc!=7);
}
void Control::control6() {
    Cliente* cl = Vista::agregarCliente();
    bst->insert(cl);
    //Este cliente se debe agregar al arbol
}
void Control::control7() {
    Vista::salida();
}

void Control::opcionIncorrecta() {
    Vista::opcionIncorrecta();
}


