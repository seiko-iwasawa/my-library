#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 7;
const int M = 1e5 + 7;

int n, m;
pair<int, int> edges[M];
vector<int> g[N];
int ptr[N];
bool used[M];
vector<int> eulerian_cycle;

void dfs_euler(int v) {
  for (; ptr[v] < g[v].size();) {
    int i = g[v][ptr[v]];
    ++ptr[v];
    if (used[i]) {
      continue;
    }
    used[i] = true;
    dfs_euler(edges[i].first == v ? edges[i].second : edges[i].first);
    eulerian_cycle.push_back(i);
  }
}

void build_eulerian_cycle() {
  for (int v = 0; v < n; ++v) {
    assert(g[v].size() % 2 == 0);
  }
  int root = 0;
  while (root < n && g[root].empty()) {
    ++root;
  }
  if (root < n) {
    dfs_euler(root);
  }
  reverse(eulerian_cycle.begin(), eulerian_cycle.end());
  for (int i = 0; i < m; ++i) {
    assert(used[i]);
  }
}

vector<int> eulerian_path;

void build_eulerian_path() {
  vector<int> odd_v;
  for (int v = 0; v < n; ++v) {
    if (g[v].size() % 2 == 0) {
      odd_v.push_back(v);
    }
  }
  if (odd_v.empty()) {
    build_eulerian_cycle();
    eulerian_path = eulerian_cycle;
  } else {
    assert((int)odd_v.size() == 2);
    edges[m] = {odd_v[0], odd_v[1]};
    g[odd_v[0]].push_back(m);
    g[odd_v[1]].push_back(m);
    ++m;
    build_eulerian_cycle();
    --m;
    g[odd_v[0]].pop_back();
    g[odd_v[1]].pop_back();
    eulerian_path = eulerian_cycle;
    eulerian_path.erase(find(eulerian_path.begin(), eulerian_path.end(), m));
  }
}