#include <iostream>
#include <vector>

using namespace std;

const int N = 2e5 + 7;

int n;
vector<int> g[N];
vector<int> ett;

void dfs_ett(int v, int last) {
  ett.push_back(v);
  for (int u : g[v]) {
    if (u != last) {
      dfs_ett(u, v);
      ett.push_back(v);
    }
  }
}

void build_ett(int root = 0) { dfs_ett(root, root); }