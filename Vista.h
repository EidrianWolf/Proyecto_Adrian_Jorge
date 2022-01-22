//
// Created by jartu on 1/15/2022.
//

#ifndef PROYECTO_ADRIAN_JORGE_VISTA_H
#define PROYECTO_ADRIAN_JORGE_VISTA_H
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "Archivos.cpp"
#include "PriorityQueue.h"
#include "PriorityQueue.cpp"
using namespace std;

class Vista {
public:
    static int menuPrincipal();
    static void encolarClientes();
    static string cedulaCliente();
    static void siguienteCliente();
    static Cliente* agregarCliente();
    static void salida();
    static void opcionIncorrecta();
    static void infoCliente(Cliente c);
    static void excepcion(RuntimeException* e);
    static void noClient();
    static void confirmacion();
};


#endif //PROYECTO_ADRIAN_JORGE_VISTA_H
