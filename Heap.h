//
// Created by jartu on 1/13/2022.
//

#ifndef HEAP_PRIORITY_QUEUE_HEAP_H
#define HEAP_PRIORITY_QUEUE_HEAP_H
#include <iostream>
using namespace std;

template <class tipo>
class Heap {
    tipo* *harr;
    int capacity;
    int heap_size;
public:
    Heap(int capacity);
    void MinHeapify(int i);
    int parent(int i);
    int left(int i);
    int right(int i);
    int getMin();
    int extractMin();
    void decreaseKey(int i, int new_val);
    void deleteKey(int i);
    void insertKey(int k);
};

void swap(int* x,int* y);

#endif //HEAP_PRIORITY_QUEUE_HEAP_H
