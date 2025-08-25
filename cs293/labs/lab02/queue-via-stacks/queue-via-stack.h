// WRITE IMPLEMENTATIONS OF METHODS BELOW
#include <stdexcept>
#include "queue.h"

template <typename T>
Queue<T>::Queue() {
    first_stack = Stack<T>();
    second_stack = Stack<T>();
}

template <typename T>
Queue<T>::~Queue() {
}

template <typename T>
void Queue<T>::enqueue(T value) {
    first_stack.push(value);
    return;
}

template <typename T>
T Queue<T>::dequeue() {
    if (second_stack.isEmpty()) {
        while(!first_stack.isEmpty()) {
            second_stack.push(first_stack.pop());
        }
    }
    if (second_stack.isEmpty()) throw std::invalid_argument("Empty Queue Dequeue Error");
    return second_stack.pop();
}

template <typename T>
T Queue<T>::peek() {
    if (second_stack.isEmpty()) {
        while(!first_stack.isEmpty()) {
            second_stack.push(first_stack.pop());
        }
    }
    if (second_stack.isEmpty()) throw std::invalid_argument("Empty Queue Peek Error");
    return second_stack.peek();
}

template <typename T>
bool Queue<T>::isEmpty() {
    return first_stack.isEmpty() & second_stack.isEmpty();
}

template <typename T>
size_t Queue<T>::getSize() {
    return first_stack.getSize() + second_stack.getSize();
}