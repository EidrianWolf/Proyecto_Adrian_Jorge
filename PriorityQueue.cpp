//
// Created by jartu on 1/17/2022.
//

#include "PriorityQueue.h"
template<typename E>
int PriorityQueue<E>::size() const {
    return T->size();
}

template<typename E>
bool PriorityQueue<E>::empty() const {
    return size()==0;
}

template<typename E>
void PriorityQueue<E>::insert( E& e) {
    if (T->size() < T->getCapacity())
        T->insertKey(&e);
    else {
        throw new QueueException(" Overflow: Maximum capacity reached");
        return;
    }
}

template<typename E>
const E &PriorityQueue<E>::min() {
    return *(T->getMin());
}

template<typename E>
void PriorityQueue<E>::removeMin() {
    if(!empty())
        T->extractMin();
    else{
        throw new QueueException("Error: Empty stack");
        return;
    }
}

template<typename E>
PriorityQueue<E>::PriorityQueue(int capacity) {
    T = new Heap<E>(capacity);
}

