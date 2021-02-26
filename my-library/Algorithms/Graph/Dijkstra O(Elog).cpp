#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

const int N = 1e5;

struct Edge {
  int v, u, w;
};

int n;
vector<Edge> g[N];

int dist[N];

void dijkstra(int start) {
  const int INF = 1e9 + 7;
  fill(dist, dist + n, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;  // you also can use std::set
  dist[start] = 0;
  q.push({dist[start], start});
  while (!q.empty()) {
    int v = q.top().second;
    int d = q.top().first;
    q.pop();
    if (d == dist[v]) {
      for (Edge e : g[v]) {
        if (dist[e.u] > dist[e.v] + e.w) {
          dist[e.u] = dist[e.v] + e.w;
          q.push({dist[e.u], e.u});
        }
      }
    }
  }
}
