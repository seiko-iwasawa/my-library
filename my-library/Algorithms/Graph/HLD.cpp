#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 7;

int n;
vector<int> g[N];

int sz[N];
int nxt[N];
int par[N];
int par_hld[N];

void dfs(int v, int last) {
  sz[v] = 1;
  nxt[v] = -1;
  par[v] = last;
  par_hld[v] = -1;
  for (int u : g[v]) {
    if (u != last) {
      dfs(u, v);
      sz[v] += sz[u];
      if (nxt[v] == -1 || sz[nxt[v]] < sz[u]) {
        nxt[v] = u;
      }
    }
  }
  if (nxt[v] != -1) {
    par_hld[nxt[v]] = v;
  }
}

vector<vector<int>> hld;
int ind_tree[N];
int ind[N];

void build_hld() {
  dfs(0, 0);
  for (int v = 0; v < n; ++v) {
    if (par_hld[v] == -1) {
      int u = v;
      hld.push_back({});
      while (u != -1) {
        hld.back().push_back(u);
        u = nxt[u];
      }
      reverse(hld.back().begin(), hld.back().end());
      for (int i = 0; i < hld.back().size(); ++i) {
        int u = hld.back()[i];
        ind_tree[u] = hld.size() - 1;
        ind[u] = i;
      }
    }
  }
}