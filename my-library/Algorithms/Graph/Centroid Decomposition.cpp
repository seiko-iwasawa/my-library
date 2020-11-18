#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 7;

vector<int> g[N], cd[N];

bool used[N];

int d[N], p[N];

void dfs(int v, int last = -1) {
  d[v] = 1;
  for (int u : g[v]) {
    if (used[u] || u == last) continue;
    dfs(u, v);
    d[v] += d[u];
  }
}

int get_centroid(int v, int sz, int last = -1) {
  for (int u : g[v]) {
    if (used[u] || u == last) continue;
    if (2 * d[u] > sz) return get_centroid(u, sz, v);
  }
  return v;
}

int build(int v, int lst = -1) {
  dfs(v);
  int c = get_centroid(v, d[v]);
  if (lst != -1) cd[lst].push_back(c);
  p[c] = lst;
  used[c] = true;
  for (int u : g[c]) {
    if (!used[u]) build(u, c);
  }
  return c;
}