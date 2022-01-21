
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
    try{
    file->cargar(bst);
    }catch (FileException* e){Vista::excepcion(e);}
    cout<<bst->getCant()<<endl;
    int opc;
    do {
        opc = Vista::menuPrincipal();
        switch (opc) {
            case 1:
                control1();
                break;
            case 2:
                control2();
                break;
            case 3:
                control3();
                break;
            case 4:
                control4();
                break;
            case 5:
                control5();
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
    try{
        string ced = Vista::cedulaCliente();
        //cp->insert(bst.)

    }catch (RuntimeException* e){Vista::excepcion(e);}
}

void Control::control3() {  //Atender 5 clientes
    try{
        if(!cp->empty())
            for(int i=0;i<5;i++){
                Vista::infoCliente(cp->min());
                cp->removeMin();
            }
        else throw new QueueException("Error: Empty queue");
    }catch (RuntimeException* e){Vista::excepcion(e);}
}
void Control::control4() {
    try{
        Vista::siguienteCliente();
        if(!cp->empty())
            Vista::infoCliente(cp->min());
        else throw new QueueException("Error: Empty queue");
    }catch (RuntimeException* e){Vista::excepcion(e);}
}
void Control::control5() {
    try{
        if(!cp->empty()){
            while (!cp->empty()){
                Vista::infoCliente(cp->min());
                cp->removeMin();
            }
        }
        else throw new QueueException("Error: Empty queue");
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
    //file->guardar("DatosBancoUno.txt");
}

void Control::opcionIncorrecta() {
    Vista::opcionIncorrecta();
}








