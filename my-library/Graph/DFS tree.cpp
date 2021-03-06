#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

vector<int> g[N];

void dfs_tree(int v, int last) {
  for (int u : g[v]) {
    if (u != last) {
      dfs_tree(u, v);
    }
  }
}

// to call: dfs(root, root)