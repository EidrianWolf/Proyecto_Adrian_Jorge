//
// Created by adr20 on 17/1/2022.
//

#ifndef PROYECTO_ADRIAN_JORGE_NODO_H
#define PROYECTO_ADRIAN_JORGE_NODO_H

#include "Cliente.h"

template <class T>
class Nodo {
private:
    T *data;
    Nodo* left;
    Nodo* right;
public:
    Nodo(T *data = nullptr, Nodo *left = nullptr, Nodo *right = nullptr);
    virtual ~Nodo();
    T* getData() const;
    void setData(T* data);
    Nodo *getLeft() const;
    void setLeft(Nodo *left);
    Nodo *getRight() const;
    void setRight(Nodo *right);
};


#endif //PROYECTO_ADRIAN_JORGE_NODO_H
