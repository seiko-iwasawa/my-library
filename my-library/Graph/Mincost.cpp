#include <bits/stdc++.h>

using namespace std;

const int N = 107;
const int M = 1007;
const int INF = 1e9 + 7;

struct Edge {
  int v, u, c, f, w;

  int cf() { return c - f; }

  Edge() {}
  Edge(int v, int u, int c, int f, int w) : v(v), u(u), c(c), f(f), w(w) {}
};

int n, m;
Edge edges[2 * M];
vector<int> g[N];

void add_edge(int v, int u, int c, int w) {
  static int i = 0;
  g[v].push_back(i);
  g[u].push_back(i + 1);
  edges[i] = {v, u, c, 0, w};
  edges[i + 1] = {u, v, 0, 0, -w};
  i += 2;
}

int dist[N];

bool in_q[N];

void spfa(int start) {
  fill(dist, dist + n, INF);
  fill(in_q, in_q + n, false);
  dist[start] = 0;
  queue<int> q({start});
  in_q[start] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    in_q[v] = false;
    for (int i : g[v]) {
      Edge e = edges[i];
      if (e.cf() && dist[e.u] > max(-INF, dist[e.v] + e.w)) {
        dist[e.u] = max(-INF, dist[e.v] + e.w);
        if (!in_q[e.u]) {
          q.push(e.u);
          in_q[e.u] = true;
        }
      }
    }
  }
}

bool used[N];

int cnt_dfs = 0;

int dfs(int v, int t, int f) {
  ++cnt_dfs;
  if (v == t) {
    return f;
  }
  used[v] = true;
  for (int i : g[v]) {
    Edge e = edges[i];
    if (e.cf() && !used[e.u] && dist[v] + e.w == dist[e.u]) {
      int nxt_f = dfs(e.u, t, min(f, e.cf()));
      if (nxt_f) {
        edges[i].f += nxt_f;
        edges[i ^ 1].f -= nxt_f;
        return nxt_f;
      }
    }
  }
  return 0;
}

int phi[N];

void johnson(int start) {
  fill(dist, dist + n, INF);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  dist[start] = 0;
  q.push({dist[start], start});
  while (!q.empty()) {
    int v = q.top().second;
    int d = q.top().first;
    q.pop();
    if (d == dist[v]) {
      for (int i : g[v]) {
        Edge e = edges[i];
        if (e.cf() && dist[e.u] > dist[e.v] + e.w + phi[v] - phi[e.u]) {
          assert(e.w + phi[v] - phi[e.u] >= 0);
          dist[e.u] = dist[e.v] + e.w + phi[v] - phi[e.u];
          q.push({dist[e.u], e.u});
        }
      }
    }
  }
}

void mincost(int s, int t) {
  // TODO: delete all negative cycles
  spfa(s);
  copy(dist, dist + n, phi);
  while (dfs(s, t, INF)) {
    johnson(s);
    for (int v = 0; v < n; ++v) {
      dist[v] += phi[v];
      phi[v] = dist[v];
    }
    fill(used, used + n, false);
  }
}