//
// Created by adr20 on 17/1/2022.
//

#include "Archivos.h"

template <class T>
Archivos<T>::Archivos(const string &archivo) : archivo(archivo) {
    t = new T;
}


template<class T>
void Archivos<T>::guardar(string info) {
    f.open(archivo, ios::app);
    if (f.fail()) {
        throw new FileException("Error: File saving failed");
        exit(1);
    } else
        f << endl << info;

    f.close();
}

template <class T>
void Archivos<T>::cargar(BST<T>* tree) {
    Cliente *nuevo;
    string linea, nombre, id;
    bool nino, embarazada, mayor;
    int cat;
    f.open(archivo);

    if (f.fail()) {
        throw new FileException("Error: File opening failed");
        exit(1);
    }
try {
    while (!f.eof()) {
        getline(f, linea, ',');
        nombre = linea;
        getline(f, linea, ',');
        id = linea;
        getline(f, linea, ',');
        linea == "Yes" ? nino = 1 : nino = 0;
        getline(f, linea, ',');
        linea == "Yes" ? embarazada = 1 : embarazada = 0;
        getline(f, linea, ',');
        linea == "Yes" ? mayor = 1 : mayor = 0;
        getline(f, linea);
        cat = stoi(linea);
        nuevo = new Cliente(nombre, id, nino, embarazada, mayor, cat);
        tree->insert(nuevo);
    }
    f.close();
}catch(invalid_argument e){cout<<e.what()<<endl;}
}