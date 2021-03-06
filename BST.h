//
// Created by adr20 on 17/1/2022.
//

#ifndef PROYECTO_ADRIAN_JORGE_BST_H
#define PROYECTO_ADRIAN_JORGE_BST_H

#include "Nodo.cpp"
#include "PriorityQueue.h"


template <class T>
class BST {
private:
    int cant = 0;
    Nodo<T> *root;
    Nodo<T> *makeEmpty(Nodo<T> *t);
    Nodo<T> *insert(T *x, Nodo<T> *t);
    Nodo<T> *findMin(Nodo<T> *t);
    Nodo<T> *findMax(Nodo<T> *t);
    Nodo<T> *remove(int x, Nodo<T> *t);
    void inOrder(PriorityQueue<T>* cola, Nodo<T>* t);
    Nodo<T> *find(Nodo<T> *t, string x);
public:
    BST();
    virtual ~BST();
    void insert(T *t);
    void remove(int x);
    void encolarEnCola(PriorityQueue<T>* cola);
    T* search(string t);
    int getCant();
    string toString(Nodo<T>* t);
    Nodo<T> *getRoot() const;
    string gArchivo(Nodo<T>* t);
};


#endif //PROYECTO_ADRIAN_JORGE_BST_H
