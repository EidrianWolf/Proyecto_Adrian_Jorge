//
// Created by adr20 on 17/1/2022.
//

#include "Nodo.h"

template <class T>
Nodo<T>::Nodo(T* data, Nodo<T> *left, Nodo<T> *right) : data(data), left(left), right(right) {}

template <class T>
Nodo<T>::~Nodo() {

}

template <class T>
T* Nodo<T>::getData() const {
    return data;
}

template <class T>
void Nodo<T>::setData(T* data) {
    Nodo::data = data;
}

template <class T>
Nodo<T> *Nodo<T>::getLeft() const {
    return left;
}

template <class T>
void Nodo<T>::setLeft(Nodo<T> *left) {
    Nodo::left = left;
}

template <class T>
Nodo<T> *Nodo<T>::getRight() const {
    return right;
}

template <class T>
void Nodo<T>::setRight(Nodo<T> *right) {
    Nodo::right = right;
}