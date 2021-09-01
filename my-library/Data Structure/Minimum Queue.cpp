#include <bits/stdc++.h>

using namespace std;

queue<int> q;
deque<int> q_min;

void push(int x) {
  q.push(x);
  while (!q_min.empty() && x < q_min.back()) {
    q_min.pop_back();
  }
  q_min.push_back(x);
}

void pop() {
  assert(!q.empty());
  if (q_min.front() == q.front()) {
    q_min.pop_front();
  }
  q.pop();
}

int get_min() {
  assert(!q.empty());
  return q_min.front();
}