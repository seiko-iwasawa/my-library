#include <deque>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

struct Edge {
  int v, u, w;
};  // w (weight) is 0 or 1
vector<Edge> g[N];
int dist[N];

/*
Calculates array dist
dist[v] is the distance beetween start and v
dist[v] is N if v isn't reachable for start
weights of edges is 0 or 1
Additional memory: O(N)
Time complexity: O(M)
*/
void bfs01(int start) {
  fill(dist, dist + N, N);
  deque<int> d({start});
  dist[start] = 0;
  while (!d.empty()) {
    int v = d.front();
    d.pop_front();
    for (Edge e : g[v]) {
      if (dist[e.u] > dist[e.v] + e.w) {
        if (e.w == 0) {
          d.push_front(e.u);
        } else {
          d.push_back(e.u);
        }
        dist[e.u] = dist[e.v] + e.w;
      }
    }
  }
}
