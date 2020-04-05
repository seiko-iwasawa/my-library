// unchecked

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 500;
const int INF = 1e9;

struct Edge { int v, u, w; };
vector<Edge> g[N];

int dist[N][N];
int p[N][N];

void floyd_warshall() {
	// Complexity: O(N**3)
	for (int v = 0; v < N; ++v) {
		for (int u = 0; u < N; ++u) {
			dist[v][u] = INF;
			p[v][u] = u;
		}
		dist[v][v] = 0;
		for (Edge e : g[v]) {
			dist[e.v][e.u] = min(dist[e.v][e.u], e.w);
		}
	}
	for (int t = 0; t < N; ++t) {
		for (int v = 0; v < N; ++v) {
			for (int u = 0; u < N; ++u) {
				if (dist[v][t] != INF && dist[t][u] != INF && dist[v][u] > dist[v][t] + dist[t][u]) {
					dist[v][u] = max(-INF, dist[v][t] + dist[t][u]);
					p[v][u] = p[v][t];
				}
			}
		}
	}
}