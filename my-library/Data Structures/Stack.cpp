#include <cassert>
#include <iostream>

using namespace std;

const int N = 1e5;

int stack[N], sz = 0;

int size() { return sz; }

bool empty() { return size() == 0; }

void clear() { sz = 0; }

void push(int x) { stack[sz++] = x; }

void pop() {
  assert(!empty());
  --sz;
}

int back() {
  assert(!empty());
  return stack[sz - 1];
}
