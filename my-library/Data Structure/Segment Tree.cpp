#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e5;
const int INF = 1e9 + 7;

int a[N];
int t[4 * N];

void build(int pos, int l, int r) {
  if (r - l == 1) {
    t[pos] = a[l];
  } else {
    build(2 * pos + 1, l, l + r >> 1);
    build(2 * pos + 2, l + r >> 1, r);
    t[pos] = max(t[2 * pos + 1], t[2 * pos + 2]);
  }
}

void upd(int pos, int l, int r, int i, int x) {
  if (i < l || r <= i) {
    return;
  } else if (r - l == 1) {
    t[pos] = x;
  } else {
    upd(2 * pos + 1, l, l + r >> 1, i, x);
    upd(2 * pos + 2, l + r >> 1, r, i, x);
    t[pos] = max(t[2 * pos + 1], t[2 * pos + 2]);
  }
}

int get(int pos, int l, int r, int ql, int qr) {
  if (qr <= l || r <= ql) {
    return -INF;
  } else if (ql <= l && r <= qr) {
    return t[pos];
  } else {
    return max(get(2 * pos + 1, l, l + r >> 1, ql, qr),
               get(2 * pos + 2, l + r >> 1, r, ql, qr));
  }
}
