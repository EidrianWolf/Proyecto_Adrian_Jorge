
//
// Created by jartu on 1/15/2022.

#include "Control.h"

Control::Control() {
    file = new Archivos<Cliente>("DatosBancoUno.txt");
    bst = new BST<Cliente>;
    cp = new PriorityQueue<Cliente>(100);
    principal();
}

void Control::principal() {
    try{
    file->cargar(bst);
    }catch (FileException* e){Vista::excepcion(e);}
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
    try {
        bst->encolarEnCola(cp);
        Vista::encolarClientes();
    }catch (RuntimeException* e){Vista::excepcion(e);}
}

void Control::control2() {  //Encolar un cliente
    try {
        if (cp->size() != cp->getCapacity()) {
            string ced = Vista::cedulaCliente();
            if(bst->search(ced) != nullptr) {
                cp->push(*bst->search(ced));
                Vista::confirmacion();
            }
            else{
                throw new ClientIDException("Error: Client ID not found");
            }
        }
        else throw new QueueException("Overflow: Maximum capacity reached");
    }catch (RuntimeException* e){Vista::excepcion(e);}
}

void Control::control3() {  //Atender 5 clientes
    cout<<cp->size()<<endl;
    try{
        if(!cp->empty())
            if(cp->size() >= 5) {
                for (int i = 0; i < 5; i++) {
                    Vista::infoCliente(cp->max());
                    cp->pop();
                }
            }else throw new QueueException("Error: There is no 5 clients in queue");
        else throw new QueueException("Error: Empty queue");
    }catch (RuntimeException* e){Vista::excepcion(e);}
}
void Control::control4() {
    try{
        Vista::siguienteCliente();
        if(!cp->empty()) {
            Vista::infoCliente(cp->max());
            cp->pop();
        }
        else throw new QueueException("Error: Empty queue");
    }catch (RuntimeException* e){Vista::excepcion(e);}
}
void Control::control5() {
    try{
        if(!cp->empty()){
            while (!cp->empty()){
                Vista::infoCliente(cp->max());
                cp->pop();
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
}

void Control::opcionIncorrecta() {
    Vista::opcionIncorrecta();
}








