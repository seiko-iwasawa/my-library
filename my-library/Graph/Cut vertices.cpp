#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

int n;
vector<int> g[N];
int tin[N], ct = 1;
int up[N];
bool is_cut_v[N];

void dfs(int v, int last) {
  up[v] = tin[v] = ct++;
  int cnt = 0;
  for (int u : g[v]) {
    if (!tin[u]) {
      dfs(u, v);
      up[v] = min(up[v], up[u]);
      if (last != -1 && up[u] >= tin[v]) {
        is_cut_v[v] = true;
      }
      ++cnt;
    } else if (u != last) {
      up[v] = min(up[v], tin[u]);
    }
  }
  if (last == v && cnt >= 2) {
    is_cut_v[v] = true;
  }
}

void build_cut_v() {
  for (int v = 0; v < n; ++v) {
    if (!tin[v]) {
      dfs(v, v);
    }
  }
}
