//
// Created by adr20 on 17/1/2022.
//

#include "BST.h"

template <class T>
BST<T>::BST() {
    root = nullptr;
}

template <class T>
BST<T>::~BST() {
    root = makeEmpty(root);
}

template <class T>
Nodo<T>* BST<T>::makeEmpty(Nodo<T> *t) {
    if(t == nullptr){
        return nullptr;
    }
    {
        makeEmpty(t->getLeft());
        makeEmpty(t->getRight());
        delete t;
    }
    return nullptr;
}

template <class T>
Nodo<T>* BST<T>::insert(T *x, Nodo<T> *t) {
    if (t == nullptr) {
        t = new Nodo<T>(x);
    } else if (x->getID() < t->getData()->getID())
        t->setLeft(insert(x, t->getLeft()));
    else if (x->getID() > t->getData()->getID())
        t->setRight(insert(x, t->getRight()));
    return t;
}

template <class T>
Nodo<T>* BST<T>::findMin(Nodo<T> *t) {
    if (t == nullptr)
        return nullptr;
    else if (t->getLeft() == nullptr)
        return t;
    else
        return findMin(t->getLeft());
}

template <class T>
Nodo<T>* BST<T>::findMax(Nodo<T> *t) {
    if(t == nullptr)
        return nullptr;
    else if(t->getRight() == nullptr)
        return t;
    else
        return findMax(t->getRight());
}

template <class T>
void BST<T>::inOrder(PriorityQueue<T>* cola, Nodo<T>* t) {
    if (t == nullptr)
        return;
    inOrder(cola,t->getLeft());
    cola->push(*t->getData());
    inOrder(cola,t->getRight());
}

template <class T>
Nodo<T>* BST<T>::remove(int x, Nodo<T> *t) {
    Nodo<T>* temp;
    if(t == nullptr){
        return nullptr;
    }else if(x < t->getData()){
        t->setLeft(remove(x, t->getLeft()));
    }
    else if(x > t->getData()){
        t->setRight(remove(x, t->getRight()));
    }
    else if(t->getLeft() && t->getRight()){
        temp = findMin(t->getRight());
        t->setData(temp->getData());
        t->setRight(remove(t->getData(), t->getRight()));
    }
    else{
        temp = t;
        if(t->getLeft() == nullptr)
            t = t->getRight();
        else if(t->getRight() == nullptr)
            t = t->getLeft();
        delete temp;
    }
    return t;
}

template <class T>
Nodo<T>* BST<T>::find(Nodo<T> *t, string x) {

    if (t == nullptr)
        return nullptr;
    else if (x < t->getData()->getID())
        return find(t->getLeft(), x);
    else if (x > t->getData()->getID())
        return find(t->getRight(), x);
    else if(x == t->getData()->getID())
        return t;
    else
        return nullptr;
}

template <class T>
void BST<T>::insert(T* t) {
    cant++;
    root = insert(t,root);
}

template <class T>
void BST<T>::remove(int x) {
    root = remove(x,root);
}

template <class T>
T* BST<T>::search(string t) {
    Nodo<T>* nodo = find(root, t);
    if(nodo != nullptr)
        return nodo->getData();
    else
        return nullptr;
}

template <class T>
int BST<T>::getCant() {
    return cant;
}

template<class T>
Nodo<T> *BST<T>::getRoot() const {
    return root;
}

template <class T>
string BST<T>::toString(Nodo<T> *t) {
    return t->getData()->toString();
}

template<class T>
string BST<T>::gArchivo(Nodo<T> *t) {
    return t->getData()->toSave();
}

template<class T>
void BST<T>::encolarEnCola(PriorityQueue<T> *cola) {
    inOrder(cola, root);
}

