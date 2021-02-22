#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5;

vector<int> g[N];
int dist[N];

void bfs(int start) {
  fill(dist, dist + N, N);
  queue<int> q({start});
  dist[start] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v]) {
      if (dist[u] == N) {
        q.push(u);
        dist[u] = dist[v] + 1;
      }
    }
  }
}
