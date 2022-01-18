//
// Created by adr20 on 17/1/2022.
//

#include "Archivos.h"

template <class T>
Archivos<T>::Archivos(const string &archivo) : archivo(archivo) {
}


template <class T>
void Archivos<T>::cargar(BST<T>* tree) {
    Cliente *nuevo;
    string linea, nombre, id;
    bool nino, embarazada, mayor;
    int cat;
    f.open("DatosBancoUno.txt");

    if (f.fail()) {
        cout << "Error" << endl;
        exit(1);
    }

    while (!f.eof()) {
        getline(f, linea, ',');
        nombre = linea;
        getline(f, linea, ',');
        id = linea;
        getline(f, linea, ',');
        linea == "Yes"?nino = 1 : nino = 0;
        getline(f, linea, ',');
        linea == "Yes"?embarazada = 1 : embarazada = 0;
        getline(f, linea, ',');
        linea == "Yes"?mayor = 1 : mayor = 0;
        getline(f, linea);
        cat = stoi(linea);

        nuevo = new Cliente(nombre, id, nino, embarazada, mayor, cat);
        tree->insert(nuevo);

    }
    f.close();

}