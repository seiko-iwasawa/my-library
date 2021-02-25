#include <iostream>
#include <vector>

using namespace std;

const int N = 1e3;
const int M = 2e4;

struct Edge {
  int v, u, c, f;

  int cf() { return c - f; }
} edges[2 * M];

int n, s, t;
vector<int> g[N];

void add_edge(int v, int u, int c) {
  static int i = 0;
  edges[i] = {v, u, c};
  g[v].push_back(i);
  edges[i ^ 1] = {u, v, 0};
  g[u].push_back(i ^ 1);
  i += 2;
}

int f;
bool used[N];

bool dfs(int v) {
  if (v == t) {
    return true;
  }
  used[v] = true;
  for (int i : g[v]) {
    if (edges[i].cf() && !used[edges[i].u] && dfs(edges[i].u)) {
      ++edges[i].f;
      --edges[i ^ 1].f;
      return true;
    }
  }
  return false;
}

void ford_fulkerson() {
  f = 0;
  do {
    fill(used, used + n, false);
  } while (dfs(s));
}
