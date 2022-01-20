//
// Created by jartu on 1/15/2022.
//

#ifndef PROYECTO_ADRIAN_JORGE_VISTA_H
#define PROYECTO_ADRIAN_JORGE_VISTA_H
#include <iostream>
#include "Archivos.cpp"
#include "PriorityQueue.h"
#include "PriorityQueue.cpp"
using namespace std;

class Vista {
public:
    static int menuPrincipal();
    static void encolarClientes();  //Deberia recibir un arbol y una cola por parametro
    static void encolarCliente();   //Deberia recibir un arbol por parametro
    static void atenderClientes(PriorityQueue<Cliente>* cola);  //Cola
    static void atenderTodosLosClientes(PriorityQueue<Cliente>* cola);//Cola
    static void siguienteCliente(PriorityQueue<Cliente>* cola); //Recibe la cola
    static Cliente* agregarCliente();
    static void salida();
    static void opcionIncorrecta();
    static void infoCliente(Cliente c);
    static void excepcion(RuntimeException* e);
};


#endif //PROYECTO_ADRIAN_JORGE_VISTA_H
