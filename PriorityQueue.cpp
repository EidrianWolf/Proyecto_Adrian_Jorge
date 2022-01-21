//
// Created by jartu on 1/17/2022.
//

#include "PriorityQueue.h"
template<typename E>
int PriorityQueue<E>::size() const {
    return T->getSize();
}

template<typename E>
bool PriorityQueue<E>::empty() const {
    return size()==0;
}

template<typename E>
void PriorityQueue<E>::push(E& e) {
    if (T->getSize() < T->getCapacity())
        T->insertKey(&e);
    else {
        throw new QueueException(" Overflow: Maximum capacity reached");
        return;
    }
}

template<typename E>
const E &PriorityQueue<E>::max() {
    return *(T->getMax());
}

template<typename E>
void PriorityQueue<E>::pop() {
    if(!empty())
       T->deleteKey(0);
    else{
        throw new QueueException("Error: Empty stack");
        return;
    }
}

template<typename E>
PriorityQueue<E>::PriorityQueue(int capacity) {
    T = new Heap<E>(capacity);
}

template<typename E>
int PriorityQueue<E>::getCapacity() const {
    return T->getCapacity();
}

template<typename E>
string PriorityQueue<E>::toString() {
    stringstream s;
    s<<"Clientes en cola: "<<endl;
    for(int i=0;i< T->getSize(); i++)
        s <<i<<": "<< T->get(i)->toString() << endl;
    return s.str();
}




