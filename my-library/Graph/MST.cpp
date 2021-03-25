#include <algorithm>
#include <cassert>
#include <iostream>
#include <numeric>

using namespace std;

const int N = 1e5;
const int M = 1e6;

struct Edge {
  int v, u, w;
} edges[M];

int n, m;

int par[N], sz[N];

void build() {
  iota(par, par + n, 0);
  fill(sz, sz + n, 1);
}

int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }

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

void build_mst() {
  sort(edges, edges + m, [](Edge q, Edge w) { return q.w < w.w; });
  int cnt = 0;
  build();
  for (Edge *e = edges; e != edges + m; ++e) {
    if (join(e->v, e->u)) {
      swap(*e, *(edges + cnt++));
    }
  }
  assert(cnt == n - 1);
}
