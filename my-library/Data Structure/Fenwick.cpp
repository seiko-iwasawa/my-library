#include <iostream>

using namespace std;

#define int long long

const int N = 1e5;

int n;
int fenw[N];

void add(int i, int x) {
  for (; i < N; i = (i | i + 1)) {
    fenw[i] += x;
  }
}

int get(int i) {
  int res = 0;
  for (; i >= 0; i = (i & i + 1) - 1) {
    res += fenw[i];
  }
  return res;
}

int get(int i, int j) { return get(j) - get(i - 1); }
