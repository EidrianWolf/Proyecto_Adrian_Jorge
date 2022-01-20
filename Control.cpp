
//
// Created by jartu on 1/15/2022.

#include "Control.h"

Control::Control() {
    //Iniciar las estructuras de datos
    file = new Archivos<Cliente>("DatosBancoUno.txt");
    bst = new BST<Cliente>;
    cp = new PriorityQueue<Cliente>(100);
    principal();
}

void Control::principal() {
    file->cargar(bst);

    cout<<bst->getCant()<<endl;

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
void Control::control1() {  //Encolar todos los clientes

}

void Control::control2() {  //Encolar un cliente

}

void Control::control3() {  //Atender 5 clientes
    try{
        Vista::atenderClientes(cp);
    }catch (RuntimeException* e){Vista::excepcion(e);}
}
void Control::control4() {
    try{
        Vista::siguienteCliente(cp);
    }catch (RuntimeException* e){Vista::excepcion(e);}
}
void Control::control5() {
    try{
        Vista::atenderTodosLosClientes(cp);
    }catch (RuntimeException* e){Vista::excepcion(e);}
}
void Control::control6() {
    Cliente* cl = Vista::agregarCliente();
    if(cl != nullptr) {
        bst->insert(cl);
        file->guardar(cl->toSave());
    }
}
void Control::control7() {
    Vista::salida();
}

void Control::opcionIncorrecta() {
    Vista::opcionIncorrecta();
}








