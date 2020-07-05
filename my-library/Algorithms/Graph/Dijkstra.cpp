// unchecked

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int N = 1e3;
const int INF = 1e9 + 7;

struct Edge { int v, u, w; };
vector<Edge> g[N];

bool used[N];
int dist[N];

void dijkstra1(int start) {
	// Complexity: O(N*N+M)
	fill(used, used + N, false);
	fill(dist, dist + N, INF);
	dist[start] = 0;
	for (int _ = 0; _ < N; ++_) {
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
	// Complexity: O((N+M)*logN)
	fill(used, used + N, false);
	fill(dist, dist + N, INF);
	priority_queue<pair<int, int>> q({ dist[start] = 0, start });
	while (!q.empty()) {
		int v = q.top().first;
		q.pop();
		if (!used[v]) {
			used[v] = true;
			for (Edge e : g[v]) {
				if (!used[e.u] && dist[e.u] > dist[e.v] + e.w) {
					dist[e.u] = dist[e.v] + e.w;
					q.push({ dist[e.u], e.v });
				}
			}
		}
	}
}

void cool_dijkstra2(int start) {
	// Complexity: O((N+M)*logN)
	fill(used, used + N, false);
	fill(dist, dist + N, INF);
	set<pair<int, int>> f({dist[start] = 0, start});
	for (auto cur = f.begin(); cur != f.end(); f.erase(f.begin()), cur = f.begin()) {
		int v = cur->second, w = cur->first;
		if (!used[v] && (used[v] = true))
			for (Edge e : g[v])
				if (!used[e.u])
					f.insert({ dist[e.u] = min(dist[e.u], w + e.w), e.u });
	}
}
