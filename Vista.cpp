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

void Vista::salida() {
    cout<<"Hasta luego"<<endl;
}

void Vista::opcionIncorrecta() {
    cout<<"Esta opcion no es valida, vuelva a intentarlo..."<<endl;
}
