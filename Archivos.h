//
// Created by adr20 on 17/1/2022.
//

#ifndef PROYECTO_ADRIAN_JORGE_ARCHIVOS_H
#define PROYECTO_ADRIAN_JORGE_ARCHIVOS_H


#include <fstream>
#include "BST.cpp"

template <class T>
class Archivos {
private:
    T *t;
    string archivo;
    fstream f;
public:
    Archivos(const string &archivo);
   void guardar(string info);
    void cargar(BST<T>* tree);


};


#endif //PROYECTO_ADRIAN_JORGE_ARCHIVOS_H
