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
  topsort.push_back(v);
}

/*
Builds array topsort of a DAG
if the graph has cycles the function will be crush
topsort stores order of vertexes that there are only edges from topsort[i] to
topsort[j] where i < j
Additional memory: O(n)
Complexity: O(n+m)
*/
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
