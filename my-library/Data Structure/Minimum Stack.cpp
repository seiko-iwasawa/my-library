#include <bits/stdc++.h>

using namespace std;

#define stack _stack

vector<pair<int, int>> stack;

void push(int x) {
  stack.push_back({x, stack.empty() ? x : min(x, stack.back().second)});
}

void pop(int x) {
  assert(!stack.empty());
  stack.pop_back();
}

int get_min() {
  assert(!stack.empty());
  return stack.back().second;
}