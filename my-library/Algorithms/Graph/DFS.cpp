#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

vector<int> g[N];
bool used[N];

// don't forget to zero used[] before call
void dfs(int v) {
  // Complexity: O(M)
  used[v] = true;
  for (int u : g[v]) {
    if (!used[u]) {
      dfs(u);
    }
  }
}
