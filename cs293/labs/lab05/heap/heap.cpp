#include <iostream>

/*
In this exercise, we will implement heap as discussed in the class.
We need to implement the following functions.


ONLY THIS FILE MUST BE MODIFIED FOR SUBMISSION
*/


#include "heap.h"

// gives us the index of the parent for the element at index 'i'
int Heap::parent(int i) {
    if (i==0) return i;
    return ((i-1)/2); // dummy return
}


// gives us the index of the left child for the element at index 'i'
int Heap::left(int i) {
    return 2*i+1; // dummy return
}


// gives us the index of the right child for the element at index 'i'
int Heap::right(int i) {
    return 2*i+2; //dummy
}


// gives us the maximum element in the heap
int Heap::max() {
    return store[0]; //dummy
}


//swaps the elements at indices 'i' and 'j' in the store array
// Do not forget to increment the swap_count
void Heap::swap(int i, int j) {
    if (store[i]==store[j]) return;
    int temp = store[i];
    store[i] = store[j];
    store[j] = temp;
    swap_count++;
    return;
}


// inserts elements into the store array
// can use the helper function append in heap.h
void Heap::insert(int v) {
    append(v);
    int index = sz-1;
    while(true) {
        if (index==0) break;
        if (store[parent(index)]<store[index]) {
            swap(index, parent(index));
            index = parent(index);
        }
        break;
    }   
    return;
}

// makes the subtree rooted at index 'i' follow the Max Heap property
// HINT: calls the swap and recusively goes down the subtree
void Heap::heapify(int i) {
    unsigned leftt = left(i);
    unsigned rightt = right(i);
    if ((leftt<sz && store[i]<store[leftt]) || (rightt<sz && store[i]<store[rightt])) {
        int temp_i = (store[leftt] > (rightt<sz ? store[rightt] : -1)) ? leftt : rightt;
        swap(i, temp_i);
        heapify(temp_i);
    }   
    return;
}

// deletes the maximum element and makes the remaining tree follow the max heap property
// HINT: calls the heapify
void Heap::deleteMax() {
    if (sz==0) return;
    swap(0, sz-1);
    sz--;
    heapify(0);
}


// rearranges the array such that it follows the max heap property
// HINT: calls the heapify
// HINT: for efiicient building follow a bottom-up approach
void Heap::buildHeap() {
    if (sz==0) return;
    int temp_sz=sz;
    while(temp_sz--) {
        heapify(temp_sz);
    }   
    return;
}


// used to arrange the elements in descending order
// The sorted elemendts must be stored in the 'store' array
// Can use a temporary vector to sort
// HINT: Since you are using a temporary vector to sort, make sure to apply the heapify logic on that temporary vector
// and also increment the swap count whenever you perform a swap
void Heap::heapSort() {
    if (sz==0) return;
    int temp_sz=sz;
    int temp_sz1=sz;
    while(temp_sz--) {
        deleteMax();
    }   
    sz = temp_sz1;
    int reve[sz];
    for (unsigned i=0;i < sz; i++) {
        reve[i] = store[i];
    }   
    for (unsigned i=0;i < sz; i++) {
        store[i] = reve[sz-i-1];
    }   
    return;
}

