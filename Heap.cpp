//
// Created by jartu on 1/13/2022.
//

#include "Heap.h"

template <class tipo>
Heap<tipo>::Heap(int capacity) {
heap_size=0;
this->capacity=capacity;
harr= new int[capacity];
}

template <class tipo>
void Heap<tipo>::MinHeapify(int i) {
    int l= left(i);
    int r = right(i);
    int smallest = i;
    if(l<heap_size&&harr[l]<harr[i])
        smallest=l;
    if(r<heap_size&&harr[r]<harr[smallest])
        smallest = r;
    if(smallest!=i){
        swap(&harr[i],&harr[smallest]);
        MinHeapify(smallest);
    }
}

template <class tipo>
int Heap<tipo>::parent(int i) {
    return (i-1)/2;
}

template <class tipo>
int Heap<tipo>::left(int i) {
    return (2*i+1);
}

template <class tipo>
int Heap<tipo>::right(int i) {
    return (2*i+2);
}

template <class tipo>
int Heap<tipo>::getMin() {
    return harr[0];
}

template <class tipo>
int Heap<tipo>::extractMin() {
    if(heap_size<=0)
        return INT_MAX;
    if(heap_size==1){
        heap_size--;
        return harr[0];
    }
    int root=harr[0];
    harr[0]=harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}

template <class tipo>
void Heap<tipo>::decreaseKey(int i, int new_val) {
    harr[i]= new_val;
    while (i!=0&&harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i= parent(i);
    }
}

template <class tipo>
void Heap<tipo>::deleteKey(int i) {
    decreaseKey(i,INT_MIN);
    extractMin();
}

template <class tipo>
void Heap<tipo>::insertKey(int k) {
    if(heap_size == capacity) {
        throw "Overflow: Could not insertKey\n";
        return ;
    }
    heap_size++;
    int i=heap_size-1;
    harr[i]=k;
    while (i!=0&&harr[parent(i)]>harr[i]){
        swap(&harr[i],&harr[parent(i)]);
        i= parent(i);
    }
}
