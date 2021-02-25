#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const int N = 1e3;

struct Edge {
  int v, u, w;
};

int n;
vector<Edge> g[N];

bool used[N];
int dist[N];

void dijkstra(int start) {
  const int INF = 1e9 + 7;
  fill(dist, dist + n, INF);
  dist[start] = 0;
  for (int i = 0; i < n; ++i) {
    int v = find(used, used + n, false) - used;
    for (int u = 0; u < n; ++u) {
      if (!used[u] && dist[v] > dist[u]) {
        v = u;
      }
    }
    if (dist[v] == INF) {
      break;
    }
    used[v] = true;
    for (Edge e : g[v]) {
      dist[e.u] = min(dist[e.u], dist[e.v] + e.w);
    }
  }
}
