#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

struct Edge {
  int v, u, id;
};

int n, m;
vector<Edge> g[N];
int tin[N], ct = 1;
int up[N];
vector<int> cut_e;

void dfs(int v, int last, int id) {
  up[v] = tin[v] = ct++;
  for (Edge e : g[v]) {
    if (!tin[e.u]) {
      dfs(e.u, e.v, e.id);
      up[e.v] = min(up[e.v], up[e.u]);
    } else if (e.u != last) {
      up[e.v] = min(up[e.v], tin[e.u]);
    }
  }
  if (up[v] == tin[v] && last != v) {
    cut_e.push_back(id);
  }
}

void build_cut_e() {
  for (int v = 0; v < n; ++v) {
    if (!tin[v]) {
      dfs(v, v, -1);
    }
  }
}
