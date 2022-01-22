//
// Created by Jorge on 1/16/2022.
//

#include "Heap.h"

template<class tipo>
Heap<tipo>::Heap(int capacity) {
    heap_size=-1;
    Heap<tipo>::capacity=capacity;
    arr= new tipo*[capacity];
}

template<class tipo>
void Heap<tipo>::MaxHeapify(int i) {
    int l = left(i);
    int r = right(i);
    int largest = i;
    if(arr[i]<arr[left(i)]||arr[i]<arr[right(i)]){
        if(arr[left(i)]>arr[right(i)]){
            swap(&arr[i],&arr[left(i)]);
            MaxHeapify(left(i));
        }
        else{
            swap(&arr[i], &arr[right(i)]);
            MaxHeapify(right(i));
        }
    }
}

template<class tipo>
int Heap<tipo>::parent(int i) {
    return (i-1)/2;
}

template<class tipo>
int Heap<tipo>::left(int i) {
    return ((2*i)+1);
}

template<class tipo>
int Heap<tipo>::right(int i) {
    return ((2*i)+2);
}

template<class tipo>
tipo *Heap<tipo>::getMax() {
    return arr[0];
}

template<class tipo>
tipo *Heap<tipo>::extractMax() {
    tipo* root = arr[0];
    arr[0]=arr[heap_size];
    heap_size--;
    shiftDown(0);
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
    arr[i]=getMax();
    shiftUp(i);
    extractMax();
}

template<class tipo>
void Heap<tipo>::insertKey(tipo *k) {
    if(getSize()==capacity){
        throw new RuntimeException(" Overflow: Could not push key");
        return;
    }
    heap_size++;
    int i = heap_size;
    arr[i]=k;
   while (i!=0&&arr[i]>arr[parent(i)]){
        swap(&arr[i],&arr[parent(i)]);
        i= parent(i);
    }
}

template<class tipo>
tipo *Heap<tipo>::get(int index) {
    return arr[index];
}

template<class tipo>
int Heap<tipo>::getSize() const {
    return heap_size+1;
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

template<class tipo>
void Heap<tipo>::shiftUp(int i) {
    while (i>0&&arr[parent(i)]<arr[i]){
        swap(&arr[parent(i)],&arr[i]);
        i= parent(i);
    }
}

template<class tipo>
void Heap<tipo>::shiftDown(int i) {
    int maxIndex = i;
    int l = left(i);
    if(l<=heap_size&&arr[l]>arr[maxIndex])
        maxIndex = l;
    int r = right(i);
    if(r<=heap_size&&arr[r]>arr[maxIndex])
        maxIndex = r;
    if(i!=maxIndex){
        swap(&arr[i],&arr[maxIndex]);
        shiftDown(maxIndex);
    }
}

