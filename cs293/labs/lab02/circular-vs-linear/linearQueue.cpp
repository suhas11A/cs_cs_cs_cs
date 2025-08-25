#include "queue.h"

using namespace std;

template <typename T> bool DynamicQueue<T> :: isEmpty() {
  return tail==head;
}

template <typename T> bool DynamicQueue<T> :: isFull() {
  return (tail-head==N);
}

template <typename T> void DynamicQueue<T> :: grow() {
  auto s = size();
  N = nextSize();
  T* B = new T[N];
  for (size_t i = 0; i < s; ++i) {
    B[i] = A[head + i];
  }
  delete[] A;
  A = B;
  head = 0;
  tail = s;
}

template <typename T> unsigned int DynamicQueue<T> :: size() {
  return tail-head;
}

template <typename T> void DynamicQueue<T> :: QInsert(T x) {
  if (tail < N) {
    A[tail++] = x;
    return;
  }
  if (head > 0 && tail == N) {
    auto s = size();
    for (size_t i = 0; i < s; ++i) {
      A[i] = A[head + i];
    }
    head = 0;
    tail = s;
    A[tail++] = x;
    return;
  }
  grow();
  A[tail++] = std::move(x);
}

template <typename T> bool DynamicQueue<T> :: QDelete(T* x) {
  if (isEmpty()) return false;
  *x = A[head];
  head++;
  if (head == tail) {
    head = tail = 0;
  }
  return true;
}