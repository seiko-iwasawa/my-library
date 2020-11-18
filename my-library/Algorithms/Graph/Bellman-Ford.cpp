#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3;
const int M = 1e4;
const int INF = 1e9 + 7;

struct Edge {
  int v, u, w;
} edges[M];
vector<Edge> g[N];

int dist[N];

/*
Calculates array dist
dist[v] is the distance beetween start and v
dist[v] is INF if v isn't reachable for start
Additional memory: O(1)
Time complexity: O(N*M)
*/
void bellman_ford(int start) {
  fill(dist, dist + N, INF);
  dist[start] = 0;
  for (int i = 0; i < N; ++i) {
    for (Edge *e = edges; e < edges + M; ++e) {
      dist[e->u] = min(dist[e->u], max(-INF, dist[e->v] + e->w));
    }
  }
}

bool in_q[N];

/*
Calculates array dist
dist[v] is the distance beetween start and v
dist[v] is INF if v isn't reachable for start
Additional memory: O(N)
Time complexity: O(N*M), but in practice, works VERY fast
*/
void bellman_ford_queue(int start) {
  fill(dist, dist + N, INF);
  dist[start] = 0;
  fill(in_q, in_q + N, false);
  queue<int> q({start});
  in_q[start] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    in_q[v] = false;
    for (Edge e : g[v]) {
      if (dist[e.u] > max(-INF, dist[e.v] + e.w)) {
        dist[e.u] = max(-INF, dist[e.v] + e.w);
        if (!in_q[e.u]) {
          q.push(e.u);
          in_q[e.u] = true;
        }
      }
    }
  }
}
