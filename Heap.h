//
// Created by jartu on 1/16/2022.
//

#ifndef HEAP_TEMPLATE_HEAP_H
#define HEAP_TEMPLATE_HEAP_H
#include <iostream>
#include "RuntimeException.h"
using namespace std;

template<class tipo>
class Heap {
private:
    tipo* *arr;
    int capacity;
    int heap_size;
public:
    Heap(int capacity);
    void MaxHeapify(int i);
    int parent(int i);
    int left(int i);
    int right(int i);
    tipo* getMin();
    tipo* extractMax();
    void decreaseKey(int i, tipo* new_value);
    void deleteKey(int i);
    void insertKey(tipo* k);
    tipo* get(int index);
    int size()const;
    void swap(tipo** x,tipo** y);
    int getCapacity()const;
    void sort();
};


#endif //HEAP_TEMPLATE_HEAP_H
