#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

struct Heap {
  vector<int> heap;

  int size() { return heap.size(); }

  void sift_down(int i) {
    while (2 * i + 1 < size()) {
      int child = 2 * i + 1;
      if (2 * i + 2 < size() && heap[2 * i + 2] < heap[2 * i + 1]) {
        child = 2 * i + 2;
      }
      if (heap[child] < heap[i]) {
        swap(heap[i], heap[child]);
        i = child;
      } else {
        break;
      }
    }
  }

  void sift_up(int i) {
    while (heap[i] < heap[(i - 1) / 2]) {
      swap(heap[i], heap[(i - 1) / 2]);
      --i /= 2;
    }
  }

  int top() { return heap[0]; }

  void pop() {
    heap[0] = heap.back();
    heap.pop_back();
    sift_down(0);
  }

  void push(int x) {
    heap.push_back(x);
    sift_up(size() - 1);
  }

  void build() {
    for (int i = 0; i < size(); ++i) {
      sift_up(i);
    }
  }

  void fast_build() {
    for (int i = size() / 2; i >= 0; --i) {
      sift_down(i);
    }
  }

  Heap() {}
  Heap(vector<int> &a) : heap(a) { fast_build(); }
};

Heap merge(Heap a, Heap b) {
  for (int x : b.heap) {
    a.push(x);
  }
  return a;
}

Heap fast_merge(Heap a, Heap b) {
  for (int x : b.heap) {
    a.heap.push_back(x);
  }
  a.fast_build();
  return a;
}

int kth_min_elem(Heap a, int k) {
  while (--k) {
    a.top();
    a.pop();
  }
  return a.top();
}
