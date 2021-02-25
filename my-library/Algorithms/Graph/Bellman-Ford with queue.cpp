#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

const int N = 1e3;

struct Edge {
  int v, u, w;
};

int n;
vector<Edge> g[N];

int dist[N];
bool in_q[N];

void bellman_ford_queue(int start) {
  // you can try shuffle 'g'
  const int INF = 1e9 + 7;
  fill(dist, dist + n, INF);
  fill(in_q, in_q + n, false);
  dist[start] = 0;
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
