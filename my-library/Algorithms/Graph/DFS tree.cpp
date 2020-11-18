#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

vector<int> g[N];

/*
Just Depth First Search in tree
Additional memory: O(1)
Time complexity: O(N)
*/
void dfs_tree(int v, int last = -1) {
  for (int u : g[v]) {
    if (u != last) {
      dfs_tree(u, v);
    }
  }
}
