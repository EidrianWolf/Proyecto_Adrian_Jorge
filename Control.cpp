
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
    Cliente* c = new Cliente("a","1",1,1,1,1);
    Cliente* c1 = new Cliente("b","2",0,1,0,2);
    Cliente* c2 = new Cliente("c","3",1,0,0,3);

    cp->insert(*c);
    //cp->sort();
    cp->insert(*c1);
    //cp->sort();
    cp->insert(*c2);
   // cp->sort();
    cp->Heapify(0);
    cout<<"Porcentajes a="<<c->getPorcentajeInfluencia()<<"\nb="
    <<c1->getPorcentajeInfluencia()<<"\nc="<<c2->getPorcentajeInfluencia()<<endl;
    cout<<cp->min().getNombre()<<endl;
    cp->removeMin();
    cout<<cp->min().getNombre()<<endl;
    cp->removeMin();
    cout<<cp->min().getNombre()<<endl;
}

void Control::control2() {  //Encolar un cliente
    try{
        if(cp->size()!=cp->getCapacity()){
        string ced = Vista::cedulaCliente();
        cp->insert(*bst->search(ced));
        cout<<cp->min().getNombre()<<endl;
        }
        else throw new QueueException("Overflow: Maximum capacity reached");
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
    file->guardar("");
}

void Control::opcionIncorrecta() {
    Vista::opcionIncorrecta();
}








