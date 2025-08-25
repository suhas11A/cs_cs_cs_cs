#include "common.h"

int linear_search ( int * S , unsigned n , int e ) {
  // Write your code here!
  for (unsigned i=0;i<n;i++) {
    if (S[i]==e) return i;
  }
  return -1;
}

