#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

vector<int> g[N];

void dfs_tree(int v, int last = -1) {
  // Complexity: O(N)
  for (int u : g[v]) {
    if (u != last) {
      dfs_tree(u, v);
    }
  }
}
