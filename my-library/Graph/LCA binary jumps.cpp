#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 7;
const int K = 20;

int n;
vector<int> g[N];
int par[N][K];
int tin[N], tout[N];

void dfs_lca(int v, int last) {
  static int t = 0;
  tin[v] = t++;
  par[v][0] = last;
  for (int k = 1; k < K; ++k) {
    par[v][k] = par[par[v][k - 1]][k - 1];
  }
  for (int u : g[v]) {
    if (u != last) {
      dfs_lca(u, v);
    }
  }
  tout[v] = t++;
}

bool in(int v, int u) { return tin[v] >= tin[u] && tout[v] <= tout[u]; }

int get_lca(int v, int u) {
  if (in(v, u)) {
    return u;
  }
  for (int k = K - 1; k >= 0; --k) {
    if (!in(u, v)) {
      v = par[v][k];
    }
  }
  return v;
}

void build_lca(int root = 0) { dfs_lca(root, root); }
