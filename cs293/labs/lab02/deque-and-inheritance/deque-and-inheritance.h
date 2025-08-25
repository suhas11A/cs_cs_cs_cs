#include <iostream>
#include <utility>
#include <stdexcept>
using namespace std;

template <typename T>
class Deque
{
    friend ostream& operator<<(ostream& out, const Deque& dq)
    {
        for (int i = 0; i < dq.size; ++i)
        {
            int idx = (dq.front_idx + i) % dq.capacity;
            out << dq.arr[idx];
            if (i + 1 < dq.size) out << " ";
        }
        return out;
    }

protected:
    T*   arr          = nullptr;
    int  capacity     = 0;
    int  resize_factor= 2;
    int  size         = 0;
    bool auto_resize  = true;
    int  front_idx    = 0;

    void grow_if_needed()
    {
        if (size < capacity) return;
        if (!auto_resize) return;

        int new_cap = capacity > 0 ? capacity * resize_factor : 1;
        if (new_cap <= capacity) new_cap = capacity + 1;

        T* new_arr = new T[new_cap];
        for (int i = 0; i < size; ++i)
            new_arr[i] = arr[(front_idx + i) % capacity];

        delete[] arr;
        arr = new_arr;
        capacity = new_cap;
        front_idx = 0;
    }

public:
    // ctors
    Deque(int cap, bool resize = true, int resize_factor = 2)
    {
        capacity = (cap <= 0 ? 1 : cap);
        auto_resize = resize;
        this->resize_factor = (resize_factor <= 0 ? 2 : resize_factor);
        arr = new T[capacity];
        size = 0;
        front_idx = 0;
    }

    Deque(bool resize = true, int resize_factor = 2)
    {
        capacity = 2;
        auto_resize = resize;
        this->resize_factor = (resize_factor <= 0 ? 2 : resize_factor);
        arr = new T[capacity];
        size = 0;
        front_idx = 0;
    }

    Deque(const Deque& dq)
    {
        capacity = dq.capacity;
        auto_resize = dq.auto_resize;
        resize_factor = dq.resize_factor;
        size = dq.size;
        arr = new T[capacity];
        for (int i = 0; i < size; ++i)
            arr[i] = dq.arr[(dq.front_idx + i) % dq.capacity];
        front_idx = 0;
    }

    // NEW: copy assignment (deep copy)
    Deque& operator=(const Deque& dq)
    {
        if (this == &dq) return *this;
        T* new_arr = new T[dq.capacity];
        for (int i = 0; i < dq.size; ++i)
            new_arr[i] = dq.arr[(dq.front_idx + i) % dq.capacity];
        delete[] arr;
        arr = new_arr;
        capacity = dq.capacity;
        size = dq.size;
        front_idx = 0; // packed
        auto_resize = dq.auto_resize;
        resize_factor = dq.resize_factor;
        return *this;
    }

    // OPTIONAL but nice: move ctor/assignment for efficiency
    Deque(Deque&& dq) noexcept
        : arr(dq.arr), capacity(dq.capacity), resize_factor(dq.resize_factor),
          size(dq.size), auto_resize(dq.auto_resize), front_idx(dq.front_idx)
    {
        dq.arr = nullptr; dq.capacity = 0; dq.size = 0; dq.front_idx = 0;
    }

    Deque& operator=(Deque&& dq) noexcept
    {
        if (this == &dq) return *this;
        delete[] arr;
        arr = dq.arr;
        capacity = dq.capacity;
        resize_factor = dq.resize_factor;
        size = dq.size;
        auto_resize = dq.auto_resize;
        front_idx = dq.front_idx;
        dq.arr = nullptr; dq.capacity = 0; dq.size = 0; dq.front_idx = 0;
        return *this;
    }

    ~Deque()
    {
        delete[] arr;
        arr = nullptr;
        capacity = 0;
        size = 0;
        front_idx = 0;
    }

    // ---- const-correct helpers ----
    void print() const
    {
        cout << *this << "\n";
    }

    bool is_empty() const { return size == 0; }
    int  get_capacity() const { return capacity; }
    int  get_size() const { return size; }

protected:
    bool push_back(T data)
    {
        if (size == capacity)
        {
            if (!auto_resize) return false;
            grow_if_needed();
        }
        int idx = (front_idx + size) % capacity;
        arr[idx] = data;
        ++size;
        return true;
    }

    T pop_front()
    {
        if (size == 0) throw "Deque underflow";
        T val = arr[front_idx];
        front_idx = (front_idx + 1) % capacity;
        --size;
        return val;
    }

    bool push_front(T data)
    {
        if (size == capacity)
        {
            if (!auto_resize) return false;
            grow_if_needed();
        }
        front_idx = (front_idx - 1 + capacity) % capacity;
        arr[front_idx] = data;
        ++size;
        return true;
    }

    T pop_back()
    {
        if (size == 0) throw "Deque underflow";
        int idx = (front_idx + size - 1) % capacity;
        T val = arr[idx];
        --size;
        return val;
    }

    // make these const
    T peek_front() const
    {
        if (size == 0) throw "Deque is empty";
        return arr[front_idx];
    }

    T peek_back() const
    {
        if (size == 0) throw "Deque is empty";
        int idx = (front_idx + size - 1) % capacity;
        return arr[idx];
    }
};


// -------------------- Queue --------------------

template<typename T>
class Queue : public Deque<T>
{
    friend ostream& operator<<(ostream& out, const Queue& q)
    {
        const Deque<T>& base = static_cast<const Deque<T>&>(q);
        out << base;
        return out;
    }

public:
    using Deque<T>::Deque; // inherit ctors

    Queue(const Queue& other) : Deque<T>(other) {}
    Queue& operator=(const Queue& other) { Deque<T>::operator=(other); return *this; }
    Queue(Queue&& other) noexcept : Deque<T>(std::move(other)) {}
    Queue& operator=(Queue&& other) noexcept { Deque<T>::operator=(std::move(other)); return *this; }

    using Deque<T>::push_back;
    using Deque<T>::pop_front;
    using Deque<T>::peek_front;
    using Deque<T>::print;
    using Deque<T>::is_empty;
    using Deque<T>::get_size;
    using Deque<T>::get_capacity;

    bool push(T data) { return this->push_back(data); }
    T pop()           { return this->pop_front();     }
    T peek()    const { return this->peek_front();    }
};


// -------------------- Stack --------------------

template<typename T>
class Stack : public Deque<T>
{
    friend ostream& operator<<(ostream& out, const Stack& s)
    {
        // print bottom -> top, same as Deque front -> back
        const Deque<T>& base = static_cast<const Deque<T>&>(s);
        out << base;
        return out;
    }

public:
    using Deque<T>::Deque; // inherit ctors

    Stack(const Stack& other) : Deque<T>(other) {}
    Stack& operator=(const Stack& other) { Deque<T>::operator=(other); return *this; }
    Stack(Stack&& other) noexcept : Deque<T>(std::move(other)) {}
    Stack& operator=(Stack&& other) noexcept { Deque<T>::operator=(std::move(other)); return *this; }

    using Deque<T>::push_back;
    using Deque<T>::pop_back;
    using Deque<T>::peek_back;
    using Deque<T>::print;
    using Deque<T>::is_empty;
    using Deque<T>::get_size;
    using Deque<T>::get_capacity;

    bool push(T data) { return this->push_back(data); }
    T pop()           { return this->pop_back();      }
    T peek()    const { return this->peek_back();     }
};
