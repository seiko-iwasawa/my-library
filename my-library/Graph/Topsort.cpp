#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

int n, m;
vector<int> g[N];

vector<int> topsort;
int used[N];

void dfs(int v) {
  used[v] = 1;
  for (int u : g[v]) {
    if (used[u] == 0) {
      dfs(u);
    } else if (used[u] == 1) {
      assert(false);
    }
  }
  used[v] = 2;
  topsort.push_back(v);
}

void build_topsort() {
  fill(used, used + n, false);
  topsort.clear();
  for (int v = 0; v < n; ++v) {
    if (used[v] == 0) {
      dfs(v);
    }
  }
  reverse(topsort.begin(), topsort.end());
}
