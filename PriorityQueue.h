//
// Created by jartu on 1/17/2022.
//

#ifndef HEAP_TEMPLATE_PRIORITYQUEUE_H
#define HEAP_TEMPLATE_PRIORITYQUEUE_H
#include "Heap.h"
#include "Heap.cpp"
#include "RuntimeException.h"
template <typename E>
class PriorityQueue {
private:
    Heap<E>* T;
public:
    int size()const;
    bool empty()const;
    void insert( E& e);
    const E& min();
    void removeMin();

    PriorityQueue(int capacity);
};



#endif //HEAP_TEMPLATE_PRIORITYQUEUE_H
