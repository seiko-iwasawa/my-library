#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const int N = 1e3;
const int INF = 1e9 + 7;

struct Edge {
  int v, u, w;
};
vector<Edge> g[N];

bool used[N];
int dist[N];

void dijkstra1(int start) {
  fill(used, used + N, false);
  fill(dist, dist + N, INF);
  dist[start] = 0;
  for (int i = 0; i < N; ++i) {
    int v = find(used, used + N, false) - used;
    for (int u = 0; u < N; ++u) {
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

void dijkstra2(int start) {
  fill(dist, dist + N, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  dist[start] = 0;
  q.push({dist[start], start});
  while (!q.empty()) {
    int v = q.top().second, d = q.top().first;
    q.pop();
    if (d == dist[v]) {
      for (Edge e : g[v]) {
        if (dist[e.u] > dist[e.v] + e.w) {
          dist[e.u] = dist[e.v] + e.w;
          q.push({dist[e.u], e.v});
        }
      }
    }
  }
}