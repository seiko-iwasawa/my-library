#include <iostream>
#include <numeric>  // iota()

using namespace std;

const int N = 1e5;

int par[N], sz[N];

void build(int n) {
  iota(par, par + n, 0);
  fill(sz, sz + n, 1);
}

int find(int x) { return x == par[x] ? x : find(par[x]); }

bool join(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    if (sz[x] > sz[y]) {
      swap(x, y);
    }
    par[x] = y;
    sz[y] += sz[x];
  }
  return x != y;
}
