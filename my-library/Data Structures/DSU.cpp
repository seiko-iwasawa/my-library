#include <iostream>
#include <numeric>  // iota()

using namespace std;

const int N = 1e5;

int par[N], sz[N];

void build() {
  // Complexity: O(N)
  iota(par, par + N, 0);
  fill(sz, sz + N, 1);
}

// a is the inverse Ackerman function

int find(int x) {
  // Complexity: O(a(N))
  return x == par[x] ? x : par[x] = find(par[x]);
}

bool join(int x, int y) {
  // Complexity: O(a(N))
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
