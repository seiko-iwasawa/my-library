#include <algorithm>
#include <iostream>

using namespace std;

struct Line {
  int k, b;

  Line() {}
  Line(int k, int b) : k(k), b(b) {}

  int operator()(int x) { return k * x + b; }
};

const int N = 1e5 + 7;

Line t[4 * N];
int x[N];

void upd(int pos, int l, int r, Line n) {
  int m = l + r >> 1;
  bool ch_mid = (n(x[m]) < t[pos](x[m]));
  bool ch_left = (n(x[l]) < t[pos](x[l]));
  if (ch_mid) {
    swap(n, t[pos]);
  }
  if (r - l == 1) {
    return;
  } else if (ch_mid == ch_left) {
    upd(2 * pos + 2, m, r, n);
  } else {
    upd(2 * pos + 1, l, m, n);
  }
}

int get(int pos, int l, int r, int i) {
  int m = l + r >> 1;
  if (r - l == 1) {
    return t[pos](x[i]);
  } else if (i < m) {
    return min(t[pos](x[i]), get(2 * pos + 1, l, m, i));
  } else {
    return min(t[pos](x[i]), get(2 * pos + 2, m, r, i));
  }
}
