#include <algorithm>
#include <iostream>

using namespace std;

const int N = 1e3;
const int M = 1e4;

struct Edge {
  int v, u, w;
} edges[M];

int n, m;

int dist[N];

void bellman_ford(int start) {
  const int INF = 1e9 + 7;
  fill(dist, dist + n, INF);
  dist[start] = 0;
  for (int i = 0; i < n; ++i) {
    for (Edge *e = edges; e < edges + m; ++e) {
      dist[e->u] = min(dist[e->u], max(-INF, dist[e->v] + e->w));
    }
  }
}
