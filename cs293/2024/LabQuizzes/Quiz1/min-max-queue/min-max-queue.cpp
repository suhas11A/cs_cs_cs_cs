#include "min-max-queue.h"

/*
The task of this question is to implement a Min Max Queue, a queue
data structure that can find the minimum/maximum of ALL
the elements CURRENTLY PRESENT in it in O(1)/amortized O(1) time.
The queue should also be able to push/pop in amortized O(1) time.
Checking front/empty should also be O(1) time.

In min-max-queue.cpp, complete the function definitions
(You may leave the constructor/destructor empty if not needed).
Feel free to add any member variables/functions to this class or
any new class/struct(s) if needed. There are brief descriptions
for the given functions as well.

Constraints:
 - 0 <= n <= 10^7 (or 10 million) where n are the number of
   elements pushed/popped from queue.
 - Only non-negative integers (any from 0 to 2^31-1) will be
   pushed into the queue.

2 public testcases have been given to you (one for small n and other
for large). There will be some hidden testcases as well.
Your grading will depend on the output obtained from the hidden
testcases ONLY and NOT the 2 public ones.

"min-max-queue.cpp" shall ONLY be considered for grading (Don't put your solution in any other file).
DON'T TOUCH "main.cpp" or any ".h" file.

NOTE: NO OTHER "#include"s are allowed. Straight 0 if did.

During grading, a time limit will be set for the execution on the
testcases. If the functions are implemented in O(1)/amortized O(1)
time, then you don't need to worry about the time limit, they won't
exceed it. (Long testcase may take few seconds).

More efficient implementations will get greater marks!!

In case of the queue is empty, return INT_MAX for getMin(),
return INT_MIN for getMax() and return -1 for front().

*/


#include <vector>
#include <algorithm>
#include <climits>
#include <stdexcept>

class MinMaxQueue {
private:
  struct Node {
    int val;
    int mn;
    int mx;
  };

  std::vector<Node> in_;   // push here
  std::vector<Node> out_;  // pop/front from here

  void push_with_mm(std::vector<Node>& st, int x) {
    if (st.empty()) st.push_back({x, x, x});
    else {
      int mn = std::min(x, st.back().mn);
      int mx = std::max(x, st.back().mx);
      st.push_back({x, mn, mx});
    }
  }

  void move_in_to_out() {
    // Move all items from in_ to out_, rebuilding min/max for out_
    while (!in_.empty()) {
      int v = in_.back().val;
      in_.pop_back();
      if (out_.empty()) out_.push_back({v, v, v});
      else {
        int mn = std::min(v, out_.back().mn);
        int mx = std::max(v, out_.back().mx);
        out_.push_back({v, mn, mx});
      }
    }
  }

public:
  MinMaxQueue() {}

  void push(int n) {
    push_with_mm(in_, n);
  }

  void pop() {
    if (out_.empty()) {
      if (in_.empty()) throw std::out_of_range("pop from empty queue");
      move_in_to_out();
    }
    out_.pop_back();
  }

  int front() {
    if (out_.empty()) {
      if (in_.empty()) throw std::out_of_range("front from empty queue");
      move_in_to_out();
    }
    return out_.back().val;
  }

  int getMin() {
    if (in_.empty() && out_.empty()) throw std::out_of_range("min from empty queue");
    if (in_.empty()) return out_.back().mn;
    if (out_.empty()) return in_.back().mn;
    return std::min(in_.back().mn, out_.back().mn);
  }

  int getMax() {
    if (in_.empty() && out_.empty()) throw std::out_of_range("max from empty queue");
    if (in_.empty()) return out_.back().mx;
    if (out_.empty()) return in_.back().mx;
    return std::max(in_.back().mx, out_.back().mx);
  }

  bool empty() {
    return in_.empty() && out_.empty();
  }
};
