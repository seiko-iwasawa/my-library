#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 7;
const int K = 20;

int n;
vector<int> g[N];
vector<pair<int, int>> ett;
int ind[N];

void dfs_lca(int v, int last, int depth) {
  ett.push_back({depth, v});
  ind[v] = ett.size() - 1;
  for (int u : g[v]) {
    if (u != last) {
      dfs_lca(u, v, depth + 1);
      ett.push_back({depth, v});
    }
  }
}

int lg[2 * N];
pair<int, int> st[2 * N][K];

void build_lg() {
  lg[0] = -1;
  for (int i = 1; i < N; ++i) {
    lg[i] = lg[i / 2] + 1;
  }
}

void build_st() {
  for (int i = 0; i < n; ++i) {
    st[i][0] = ett[i];
  }
  for (int k = 1; k < K; ++k) {
    for (int i = 0; i + (1 << k) <= n; ++i) {
      st[i][k] = min(st[i][k - 1], st[i + (1 << k - 1)][k - 1]);
    }
  }
}

pair<int, int> get_st(int l, int r) {
  int k = lg[r - l];
  return min(st[l][k], st[r - (1 << k)][k]);
}

void build_lca(int root = 0) {
  dfs_lca(root, root, 0);
  build_lg();
  build_st();
}

int get_lca(int v, int u) {
  if (ind[v] > ind[u]) {
    swap(v, u);
  }
  return get_st(ind[v], ind[u] + 1).second;
}