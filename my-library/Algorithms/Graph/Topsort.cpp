#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

vector<int> g[N];
vector<int> topsort;
bool used[N];

void dfs(int v) {
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
  topsort.push_back(v);
}

void build_topsort() {
  // Complexity: O(N+M)
  fill(used, used + N, false);
  topsort.clear();
  for (int v = 0; v < N; ++v) {
    if (!used[v]) {
      dfs(v);
    }
  }
  reverse(topsort.begin(), topsort.end());
}
