#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return !(tail-head);
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return (head==(tail+1)%N);
}

template <typename T> void DynamicQueue<T> :: grow() {
  auto oldN = N;
  auto s = size();
  N = nextSize();
  T* B = new T[N];
  for (unsigned int i = 0; i < s; ++i) {
    B[i] = A[(head + i) % oldN];
  }
  delete[] A;
  A = B;
  head = 0;
  tail = s;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return (tail + N - head) % N;
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if (isFull()) grow();
  A[tail] = x;
  tail = (tail + 1) % N;
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if (isEmpty()) return false;
  *x = A[head];
  head = (head + 1) % N;
  return true; 
}