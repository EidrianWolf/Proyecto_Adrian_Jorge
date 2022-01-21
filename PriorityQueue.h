//
// Created by jartu on 1/17/2022.
//

#ifndef HEAP_TEMPLATE_PRIORITYQUEUE_H
#define HEAP_TEMPLATE_PRIORITYQUEUE_H
#include <iostream>
#include <sstream>
#include "Heap.h"
#include "Heap.cpp"
#include "RuntimeException.h"
using namespace std;
template <typename E>
class PriorityQueue {
private:
    Heap<E>* T;
public:
    int size()const;
    bool empty()const;
    void push(E& e);
    const E& max();
    void pop();
    PriorityQueue(int capacity);
    int getCapacity()const;
    string toString();

};



#endif //HEAP_TEMPLATE_PRIORITYQUEUE_H
