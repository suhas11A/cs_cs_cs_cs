#include "common.h"

int BinarySearch ( int * S , int n , int e ) {
  int iteration_count = 1;
  // Implement binary search here
  int first = 0;
  int last = n;
  int mid = (first+last)/2;
  while (last>first) {
    if (S[mid]==e) return iteration_count;
    else if(S[mid]>e) first=mid+1;
    else last=mid;
    mid = (first+last)/2;
    iteration_count++;
  }
  // instead of returning position return the number
  // of executed iterations of binary search.
  return iteration_count;
}

double drive_binary_search(unsigned size) {
  // Initialize an array with distinct elements
  int A[size];
  for (unsigned i=0;i<size;i++) {
    A[i]=size-i;
  }
  long long itr = 0;
  for (unsigned i=0;i<size;i++) {
    itr += BinarySearch(A, size, size-i);
  }
  
  // search all elements stored in S and compute
  // the average number of iterations in binary search

  return (double(itr))/size;
}

