#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

vector<int> g[N];
bool used[N];

void dfs(int v) {
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
}
