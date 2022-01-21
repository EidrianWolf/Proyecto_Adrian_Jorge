//
// Created by jartu on 1/15/2022.
//

#include "Vista.h"

int Vista::menuPrincipal() {
    int opc;
    cout << "Menu principal" << endl;
    cout << "1- Encolar todos los clientes" << endl;
    cout << "2- Encolar un cliente" << endl;
    cout << "3- Atender los siguientes 5 clientes" << endl;
    cout << "4- Mostrar el siguiente cliente a ser atendido" << endl;
    cout << "5- Simulacion de atencion de clientes" << endl;
    cout << "6- Agregar un cliente nuevo" << endl;
    cout << "7- Salir" << endl;
    cout << "Ingrese una opcion:";
    cin >> opc;
    return opc;
}

void Vista::encolarClientes() { //Recibe el arbol y la cola por parametro
    /*
     * Deberia recorrer el arbol y guardar todos los clientes en la cola
     *  el criterio de influencia se calcula con Cliente::getPorcentajeInfluencia()
     *  utilizar cola->enconlar() en ciclo mientras se recorre el arbol
     */
}

void Vista::encolarCliente() {  //Recibe arbol por parametro
    string ced;
    cout<<"Ingrese el numero de cedula del cliente que desea encolar: ";
    cin>>ced;
    //cola->encolar(arbol->search(ced))
}

void Vista::salida() {
    cout<<"Hasta luego"<<endl;
}

void Vista::opcionIncorrecta() {
    cout<<"Esta opcion no es valida, vuelva a intentarlo..."<<endl;
}

void Vista::atenderClientes(PriorityQueue<Cliente>* cola) {
    for(int i=0;i<5;i++) {
        infoCliente(cola->min());
        cola->removeMin();
    }
}

void Vista::atenderTodosLosClientes(PriorityQueue<Cliente>* cola) {
    while (!cola->empty()){
        infoCliente(cola->min());
        cola->removeMin();
    }

}

void Vista::siguienteCliente(PriorityQueue<Cliente>*cola) {
    cout<<"Siguiente cliente en cola: "<<endl;
    infoCliente(cola->min());
}

Cliente *Vista::agregarCliente() {
    string nom, id, nin, emb, adM;
    int cat, confirmacion;
    bool nino = false, embar = false, adultM = false;
    cout << "Ingrese el nombre del cliente: ";
    cin >> nom;
    cout << "Ingrese el numero de identificacion: ";
    cin >> id;
    cout << "Ingresa con un nino? y/n: ";
    cin >> nin;
    cout << "Es una persona embarazada? y/n: ";
    cin >> emb;
    cout << "Es adulto mayor? y/n: ";
    cin >> adM;
    cout << "Tipos de categoria:\n1. Premium\n2. Oro\n3. Normal\nIngrese una opcion: ";
    cin >> cat;
    if (nin == "y" || nin == "Y")
        nino = true;
    if (emb == "y" || emb == "Y")
        embar = true;
    if (adM == "y" || adM == "Y")
        adultM = true;
    cout << "¿Esta seguro de querer guardar el cliente creado?" << endl;
    cout << "1)Si" << endl
         << "2)No" << endl
         << "Opcion: ";
    cin >> confirmacion;
    if (confirmacion == 1) {
        cout << "Cliente agregado" << endl;
        return new Cliente(nom, id, nino, embar, adultM, cat);
    }else{
        cout<<"Cliente no agregado"<<endl;
        return nullptr;
    }
}

void Vista::infoCliente(Cliente c) {
    cout<<"Informacion del cliente"<<endl;
    cout<<c.toString()<<endl;
}

void Vista::excepcion(RuntimeException *e) {
    cout<<e->getMessage()<<endl;
}



