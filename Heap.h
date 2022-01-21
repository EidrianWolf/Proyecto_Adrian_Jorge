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
    int parent(int i);
    int left(int i);
    int right(int i);
    tipo* get(int index);
    void deleteKey(int i);
    void insertKey(tipo* k);
    int getSize()const;
    void swap(tipo** x,tipo** y);
    int getCapacity()const;
    tipo* getMax();
    tipo* extractMax();
    void shiftUp(int i);
    void shiftDown(int i);

    void decreaseKey(int i, tipo* new_value);
    void MaxHeapify(int i);
};


#endif //HEAP_TEMPLATE_HEAP_H
