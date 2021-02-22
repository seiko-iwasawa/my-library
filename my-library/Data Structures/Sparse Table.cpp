#include <algorithm>
#include <iostream>

using namespace std;

const int N = 2e5 + 1;
const int K = 18;

int f(int a, int b) { return min(a, b); }

int n, arr[N];
int lg[N];
int st[N][K];

void build_lg() {
  lg[0] = -1;
  for (int i = 1; i < N; ++i) {
    lg[i] = lg[i / 2] + 1;
  }
}

void build_st() {
  for (int i = 0; i < n; ++i) {
    st[i][0] = arr[i];
  }
  for (int k = 1; k < K; ++k) {
    for (int i = 0; i + (1 << k) <= n; ++i) {
      st[i][k] = f(st[i][k - 1], st[i + (1 << k - 1)][k - 1]);
    }
  }
}

void build() {
  build_lg();
  build_st();
}

int get(int l, int r) {
  int k = lg[r - l];
  return f(st[l][k], st[r - (1 << k)][k]);
}
