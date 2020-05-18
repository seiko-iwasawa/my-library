#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e3;
const int M = 1e4;
const int INF = 1e9 + 7;

struct Edge { int v, u, w; } edges[M];
vector<Edge> g[N];

int dist[N];

void bellman_ford1(int start) {
	// Complexity: O(N*M)
	fill(dist, dist + N, INF);
	dist[start] = 0;
	for (int _ = 0; _ < N; ++_) {
		for (Edge *e = edges; e < edges + M; ++e) {
			dist[e->u] = min(dist[e->u], max(-INF, dist[e->v] + e->w));
		}
	}
}

void bellman_ford2(int start) {
	// Complexity: O(max(L_v)*M),
	// where L_v is length of the shortest of the lightest paths from start to v
	fill(dist, dist + N, INF);
	dist[start] = 0;
	for (int _ = 0; _ < N; ++_) {
		bool flag = false;
		for (Edge *e = edges; e < edges + M; ++e) {
			if (dist[e->u] > max(-INF, dist[e->v] + e->w)) {
				dist[e->u] = max(-INF, dist[e->v] + e->w);
				flag = true;
			}
		}
		if (!flag) {
			break;
		}
	}
}

// bellman_ford3 is the same as bellman_ford2 but shorter
void bellman_ford3(int start) {
	// Complexity: O(max(L_v)*M),
	// where L_v is length of the shortest of the lightest paths from start to v
	fill(dist, dist + N, INF);
	dist[start] = 0;
	for (int _ = 0, flag = true; _ < N && flag; ++_, flag = false) {
		for (Edge *e = edges; e < edges + M; ++e) {
			flag |= (dist[e->u] != (dist[e->u] = min(dist[e->u], max(-INF, dist[e->v] + e->w))));
		}
	}
}

// bellman_ford2 and bellman_ford3 will be twice as faster if you random shuffle edges
// In a random graph, max(L_v) isn't very big

bool in_q[N];

// the fastest implementation
void bellman_ford4(int start) {
	// Complexity: O(IDK) :D
	fill(dist, dist + N, INF);
	fill(in_q, in_q + N, false);
	dist[start] = 0;
	queue<int> q({ start });
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
