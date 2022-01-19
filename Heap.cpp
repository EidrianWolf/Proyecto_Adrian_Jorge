//
// Created by jartu on 1/16/2022.
//

#include "Heap.h"

template<class tipo>
Heap<tipo>::Heap(int capacity) {
    heap_size=0;
    Heap<tipo>::capacity=capacity;
    arr= new tipo*[capacity];
}

template<class tipo>
void Heap<tipo>::MinHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l<heap_size&&arr[l]<arr[i])
        smallest=l;
    if(r<heap_size&&arr[r]<arr[smallest])
        smallest=r;
    if(smallest!=i){
        swap(&arr[i],&arr[smallest]);
        MinHeapify(smallest);
    }
}

template<class tipo>
int Heap<tipo>::parent(int i) {
    return (i-1)/2;
}

template<class tipo>
int Heap<tipo>::left(int i) {
    return (2*i+1);
}

template<class tipo>
int Heap<tipo>::right(int i) {
    return (2*i+2);
}

template<class tipo>
tipo *Heap<tipo>::getMin() {
    return arr[0];
}

template<class tipo>
tipo *Heap<tipo>::extractMin() {
    if(heap_size<=0)
        return nullptr;
    if(heap_size==1){
        heap_size--;
        return arr[0];
    }
    tipo* root = arr[0];
    arr[0]=arr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}

template<class tipo>
void Heap<tipo>::decreaseKey(int i, tipo *new_value) {
    arr[i]=new_value;
    while (i!=0&&arr[parent(i)]>arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i = parent(i);
    }
}

template<class tipo>
void Heap<tipo>::deleteKey(int i) {
    decreaseKey(i, nullptr);
    extractMin();
}

template<class tipo>
void Heap<tipo>::insertKey(tipo *k) {
    if(heap_size==capacity){
        throw new RuntimeException(" Overflow: Could not insert key");
        return;
    }
    heap_size++;
    int i=heap_size-1;
    arr[i]=k;
    while (i!=0&&arr[parent(i)]<arr[i]){
        swap(&arr[i],&arr[parent(i)]);
        i= parent(i);
    }
}

template<class tipo>
tipo *Heap<tipo>::get(int index) {
    return arr[index];
}

template<class tipo>
int Heap<tipo>::size() const {
    return heap_size;
}

template <class tipo>
void Heap<tipo>::swap(tipo** x,tipo** y){
    tipo* temp = *x;
    *x=*y;
    *y=temp;
}

template<class tipo>
int Heap<tipo>::getCapacity() const {
    return capacity;
}
