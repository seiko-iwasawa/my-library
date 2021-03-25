#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 7;

struct Edge {
  int v, u, w;
};

int n, k;
vector<Edge> g[N];

int dist[N];

void bfs0k(int start) {
  const int INF = 1e9 + 7;
  vector<queue<int>> q(k + 1);
  int cnt = 0;
  int i = 0;
  fill(dist, dist + n, INF);
  q[0].push(start);
  ++cnt;
  dist[start] = 0;
  while (cnt) {
    if (q[i].empty()) {
      i = (i + 1) % (k + 1);
      continue;
    }
    int v = q[i].front();
    q[i].pop();
    --cnt;
    for (auto e : g[v]) {
      if (dist[e.u] > dist[e.v] + e.w) {
        dist[e.u] = dist[e.v] + e.w;
        q[(i + e.w) % (k + 1)].push(e.u);
      }
    }
  }
}