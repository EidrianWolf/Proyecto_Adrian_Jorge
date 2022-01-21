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
void PriorityQueue<E>::push(E& e) {
    if (T->size() < T->getCapacity())
        T->insertKey(&e);
    else {
        throw new QueueException(" Overflow: Maximum capacity reached");
        return;
    }
}

template<typename E>
const E &PriorityQueue<E>::max() {
    return *(T->getMin());
}

template<typename E>
void PriorityQueue<E>::pop() {
    if(!empty())
        T->extractMax();
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
void PriorityQueue<E>::sort() {
    T->sort();
    for(int i=0;i<3;i++)
         cout<<T->get(i)->getNombre();
}

template<typename E>
void PriorityQueue<E>::Heapify(int i) {
    T->MaxHeapify(i);
   // for(int i=0;i<3;i++)
   //     cout<<T->get(i)->getNombre();

}

