#include <cassert>
#include <iostream>

using namespace std;

const int N = 1e5;

int deque[2 * N], *first = deque + N, *last = deque + N;

int size() { return last - first; }

bool empty() { return size() == 0; }

void clear() { first = last = deque + N; }

void push_front(int x) { *--first = x; }

void push_back(int x) { *last++ = x; }

void pop_front() {
  assert(!empty());
  ++first;
}

void pop_back() {
  assert(!empty());
  --last;
}

int front() {
  assert(!empty());
  return *first;
}

int back() {
  assert(!empty());
  return *(last - 1);
}
