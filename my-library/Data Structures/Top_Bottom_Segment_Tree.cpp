#include <algorithm>
#include <iostream>

using namespace std;

typedef int S;

const int N = 2e5 + 7;
const int INF = 1e9 + 7;

int n, m;
S t[2 * N];

inline S f(S a, S b) { return min(a, b); }

inline S f_seg(S a, S b) { return {}; }

int to_pow_of_2(int x) {
  while (x & x - 1) {
    x &= x - 1;
  }
  return 2 * x;
}

void build() {
  for (int i = n - 1; i; --i) {
    t[i] = f(t[i << 1], t[i << 1 | 1]);
  }
}

void upd(int i, S x) {
  for (t[i += n] = x; i > 1; i >>= 1) {
    t[i >> 1] = f(t[i ^ i & 1], t[i | 1]);
  }
}

void upd(int l, int r, S x) {
  // TODO
}

S get(int l, int r) {
  S resl, resr;
  resl = resr = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l & 1) {
      resl = f(resl, t[l++]);
    }
    if (r & 1) {
      resr = f(t[--r], resr);
    }
  }
  return f(resl, resr);
}
