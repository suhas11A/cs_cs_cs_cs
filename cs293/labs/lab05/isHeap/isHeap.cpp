#include "isHeap.h"


// TODO : Implement the function isMaxHeap_h
bool isMaxHeap_h(int i, const std::vector<int>& data) {
  int sizee = data.size();
  if (sizee==0) return true;
  if (2*i+1>=sizee) return true;
  if (2*i+2>=sizee) return data[i]>=data[2*i+1];
  return ((data[i]>=data[2*i+1] )& (data[i]>=data[2*i+2]) & isMaxHeap_h(2*i+1, data) & isMaxHeap_h(2*i+2, data));
}


bool isMaxHeap(const std::vector<int>& data) {
  return isMaxHeap_h(0, data);  
}
