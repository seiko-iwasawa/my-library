#include <iostream>

using namespace std;

#define int long long

const int N = 1e5;

int a[N];
int t[4 * N], d[4 * N];

void build(int pos, int l, int r) {
  // Complexity: O(N)
  d[pos] = 0;
  if (r - l == 1) {
    t[pos] = a[l];
  } else {
    build(2 * pos + 1, l, l + r >> 1);
    build(2 * pos + 2, l + r >> 1, r);
    t[pos] = t[2 * pos + 1] + t[2 * pos + 2];
  }
}

void push(int pos, int l, int r) {
  // Complexity: O(1)
  if (d[pos]) {
    if (r - l > 1) {
      d[2 * pos + 1] += d[pos];
      d[2 * pos + 2] += d[pos];
    }
    t[pos] += (r - l) * d[pos];
    d[pos] = 0;
  }
}

void upd(int pos, int l, int r, int i, int x) {
  // Complexity: O(logN)
  push(pos, l, r);
  if (i < l || r < i) {
    return;
  } else if (r - l == 1) {
    t[pos] += x;
  } else {
    upd(2 * pos + 1, l, l + r >> 1, i, x);
    upd(2 * pos + 2, l + r >> 1, r, i, x);
    t[pos] = t[2 * pos + 1] + t[2 * pos + 2];
  }
}

void upd(int pos, int l, int r, int ql, int qr, int x) {
  // Complexity: O(logN)
  push(pos, l, r);
  if (qr < l || r < ql) {
    return;
  } else if (ql <= l && r <= qr) {
    d[pos] += x;
    push(pos, l, r);
  } else {
    upd(2 * pos + 1, l, l + r >> 1, ql, qr, x);
    upd(2 * pos + 2, l + r >> 1, r, ql, qr, x);
    t[pos] = t[2 * pos + 1] + t[2 * pos + 2];
  }
}

int get(int pos, int l, int r, int ql, int qr) {
  // Complexity: O(logN)
  push(pos, l, r);
  if (qr < l || r < ql) {
    return 0;
  } else if (ql <= l && r <= qr) {
    return t[pos];
  } else {
    return get(2 * pos + 1, l, l + r >> 1, ql, qr) +
           get(2 * pos + 2, l + r >> 1, r, ql, qr);
  }
}
